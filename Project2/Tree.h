/**
* \file Tree.h
*
* \author Jordan Hybki
*
* Binary Search Tree header file.
*
*/

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include <iostream>
#include <fstream>
#include <functional>

using namespace std;
template<class T> class BinarySearchTree
{
public:
    BinarySearchTree() { root = nullptr; }
    //destructor
    ~BinarySearchTree() {
        _emptyTree(root);
        //deleteTree(root);
        //int k = 1;

        //auto isDivisibleByK = [k](int x) { return x % k == 0; };

        //_filter(root, isDivisibleByK);


    }
    void insert(const T& t)
    {
        _insert(root, t);
    }
    void display() const
    {
        int level = 0;
        _display(root, level);
    }
    void inOrderTraverse(vector<T>& vec) const
    {
        _inOrderTraverse(root, vec);
    }
    void deleteNode(const T& t)
    {
        _deleteNode(root, t);
    }
    void filter(function<bool(const T)> isIn)
    {
        _filter(root, isIn);
    }
    void forEachInterval(const T& a, const T& b, function<void(const T)> func) const
    {
        _forEachInterval(root, a, b, func);

    }
    bool verifyBinarySearchTree() const
    {
        T min_element;
        T max_element;
        return _verifyBinarySearchTree(root, min_element, max_element);
    }


private:
    // class Node (you can modify,but it is not necessary)
    // The nested node class for objects in our tree.
    struct Node
    {
        friend class BinarySearchTree;

        Node() { m_ll = nullptr;  m_rl = nullptr; }

        Node(const T& t) { m_num = t;  m_ll = nullptr;  m_rl = nullptr; }
        Node(const T& t, Node* l, Node* r) : m_num{ t }, m_ll{ l }, m_rl{ r } {}

        T& data() { return m_num; }

        const T& data() const { return m_num; }

        Node* m_ll;
        Node* m_rl;
        T     m_num;
    };

    Node* root;
    /**
     * Deletes each leaf in the root tree
     * Acts as deconstructor
     * \param node Node of someNode
     * \return node Node of root that is empty
     *
     */
    Node* _emptyTree(Node* someNode) {
        if (someNode == nullptr)
            return nullptr;
        {
            _emptyTree(someNode->m_ll);
            _emptyTree(someNode->m_rl);
            delete someNode;
        }
        return nullptr;
    }

    /**
     * Prints tree in accordance to Mimir output
     * \param node Node of p
     * \param int Int level we are currently at when recusively calling print leaf in node
     *
     */
    void _display(Node* p, int level) const
    {
        if (p == nullptr) return;
        level++;
        if (p->m_rl != nullptr)
        {
            _display(p->m_rl, level);
        }
        for (int i = 0; i <= level; i++)
        {
            cout << "    ";
        }
        cout << "__" << p->data() << endl;
        if (p->m_ll != nullptr)
        {
            _display(p->m_ll, level);
        }
    }

    /**
     * Inserts Recursively data into a Binary tree Node. Inserts an item into the tree.
     * No need to balance the tree. Thisshould be O(h) where h is height of the tree.
     * \param node Node of someNode
     * \param data Data of any data type wanting to be inserted into someNode
     *
     */
    void _insert(Node*& someNode, const T& data)
    {
        /* Check if tree is empty*/
        if (someNode == nullptr)
        {
            /* Empty means new first node*/
            someNode = new Node(data);
        }
        /* Tree is not empty, insert node*/
        else
        {
            /* If data < someNode->data() then we go down left side */
            if (data < someNode->data())
            {
                /* Recursively Call _insert with someNode left branch and data input parameter*/
                _insert(someNode->m_ll, data);
            }
            /* Else if data > someNode->data() (any other option left in if statement) then we go down right side */
            else
            {
                /* Recursively Call _insert with someNode right branchand data input parameter*/
                _insert(someNode->m_rl, data);

            }
        }
    }

    /**
     * Does InOrderTraversal of Binary tree. Traverses the tree in order. In addition, there is an-
     * other parameter: vector. The vector is expected to have all elements in
     * the tree by the same order as visited by each recursion. This should be
     * O(n).
     * \param node Node of someNode
     * \param vector Vector of order we visit each leaf in Node.
     *
     */
    void _inOrderTraverse(Node* someNode, vector<T>& vec)const
    {
        /* Check if someNode parameter input is not nullptr (empty means nothing to traverse to begin with)*/
        if (someNode != nullptr)
        {
            /*Move left until nullptr*/
            _inOrderTraverse(someNode->m_ll, vec);
            /* Push back node data into vec input parameter*/
            vec.push_back(someNode->data());
            /* Move right until nullptr*/
            _inOrderTraverse(someNode->m_rl, vec);
        }
    }


    /**
     * Gets the minimum leaf value in the tree.
     * \param node Node of someNode
     * \return node Node of min value found in tree.
     *
     */
    Node* minLeafRetrieved(Node* someNode)
    {
        /* Increment through each left leaf found in tree*/
        while (someNode->m_ll != nullptr)
        {
            /* Get to the leftmost leaf in the left side of the tree*/
            someNode = someNode->m_ll;
        }
        /* Return position that is the leftmost value in the left side of tree*/
        return someNode;
    }

    /**
     * Deletes leaf from node of Binary tree. Deletes an element of the tree. This should be O(h).
     * \param node Node of someNode
     * \param data Data of any data type wanting to be deleted from someNode
     *
     */
    void _deleteNode(Node*& someNode, const T& data)
    {
        /* If tree is empty, do nothing*/
        if (someNode == nullptr)
        {
            /* Tree is empty*/
            return;
        }
        /* Tree is not empty*/
        /* Find node to delete in the tree*/
        else if (data < someNode->data())
        {
            /* Left side of the tree delete*/
            _deleteNode(someNode->m_ll, data);
        }
        else if (data > someNode->data())
        {
            /* Right side of the tree delete*/
            _deleteNode(someNode->m_rl, data);
        }
        /* someNode->Data() == data*/
        else
        {
            /* When there is no leafs found in tree.*/
            if (someNode->m_ll == nullptr && someNode->m_rl == nullptr) {
                delete someNode;
                someNode = nullptr;
            }
            /* When there is only one leaf found in tree (LHS)*/
            else if (someNode->m_ll == nullptr) {
                Node* lastNode = someNode;
                someNode = someNode->m_rl;
                delete lastNode;
            }
            /* When there is only one leaf found in tree (RHS)*/
            else if (someNode->m_rl == nullptr) {
                Node* lastNode = someNode;
                someNode = someNode->m_ll;
                delete lastNode;
            }
            /* When there is two leafs exactly in tree*/
            else {
                /* No need to recursively call when there can be only one min value in each side
                of tree */
                Node* minNode = minLeafRetrieved(someNode->m_rl);
                /* Set someNode data to minNode data found in minLeafRetrieved*/
                someNode->m_num = minNode->data();
                /* Delete min node found in original someNode*/
                _deleteNode(someNode->m_rl, minNode->data());
            }

        }
    }

    /**
     * Filter: Deletes all nodes that do not have the desired property keepingonly ones with the property.
     * This should be O(n). Provide an memory effcient implementation, i.e., O(1) space.
     * \param node Node of someNode
     * \param function<bool(const T)> Function<Bool(Const T)> that determines which leafs to filter from tree.
     *
     */
    void _filter(Node*& someNode, function<bool(const T)> isIn)
    {
        /* If tree is empty*/
        if (someNode == nullptr)
        {
            /* Do nothing when tree empty*/
            return;
        }
        else
        {
            /* Not Empty*/
            /* Filter pointer of leafs left of tree*/
            _filter(someNode->m_ll, isIn);
            /* Filter pointer of leafs right of tree*/
            _filter(someNode->m_rl, isIn);
            /* Check if leaf needs to be deleted from tree*/
            if (!isIn(someNode->m_num))
            {
                /* Delete node that dosen't satisfy isIn function*/
                _deleteNode(someNode, someNode->m_num);
            }
        }
    }

    /**
     * ForEachInterval: perform some function to each node of the tree inrange of interval [a; b] where a; b are parameters of the method.
     * Providea memory effcient implementation, i.e., O(1) space. The running timeshould be equal to h plus number of elements satisfying the interval.
     * \param node Node of someNode
     * \param T t a is starting range
     * \param T t b is end range
     * \param function<void(const T)> function<void(const T)> function that determines which leafs fit in interval
     *
     */
    void _forEachInterval(Node* someNode, const T& a, const T& b, function<void(const T)> func) const
    {
        if (someNode == nullptr)
        {
            /* If tree is empty*/
            return;
        }
        if (someNode->m_num < a)
        {
            /* Not Empty*/
            /* Check if Current Node is in range */
            /* Run function through pointer value of leafs right of tree*/
            _forEachInterval(someNode->m_rl, a, b, func);
        }
        else if (someNode->m_num > b) 
        {
            /* Check if Current Node is in range */
            /* Run function through pointer value of leafs left of tree*/
            _forEachInterval(someNode->m_ll, a, b, func);
        }
        else if ((someNode->m_num >= a) && (someNode->m_num <= b))
        {
            /* Yes node is in range*/
            /* Pass node value in func*/
            func(someNode->m_num);
            /* Run function through pointer value of leafs left and right of tree*/
            _forEachInterval(someNode->m_ll, a, b, func);
            _forEachInterval(someNode->m_rl, a, b, func);

        }
    }

    /**
     * VerifyBinarySearchTree: returns true if the tree has properties of binary
     * search tree, e.g., value of left child node is less than that of its parent.
     * Return false otherwise. This should be O(n). Provide a memory effcient
     * implementation, i.e., O(1) space.
     * \param node Node of someNode pointer
     * \param MIN min of minimum value to check in range
     * \param MAX max of maximum value to check in range
     *
     */
    bool _verifyBinarySearchTree(Node* someNode, const T& MIN, const T& MAX) const
    {
        /* If tree is empty*/
        if (someNode == nullptr)
        {
            /* Do nothing when tree empty*/
            return true;
        }
        /* Not empty*/
        else if (MIN <= someNode->data() && someNode->data() <= MAX)
        {
            /* Move pointer to the left. Check in [MIN, this_node]*/
            _verifyBinarySearchTree(someNode, MIN, someNode->data());
            /* Move pointer to the right. Check in [this_node,MAX]*/
            _verifyBinarySearchTree(someNode, someNode->data(), MAX);
            return true;
        }
        else
        {
            return false;
        }

    }

};


#endif
