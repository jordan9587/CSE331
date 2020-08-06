/**
 * \file UnweightedGraph.cpp
 *
 * \author Jordan Hybki
 */

#include "UnweightedGraph.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

/** Constructor 
* \param t T string of unweighed graph name
*/
UnweightedGraph::UnweightedGraph(const string& t)
{
    //You may add any construction nextPosition your private attribute.
    ifstream in(t);
    if (!in.is_open()) {
        cerr << "cannot open file!" << std::endl;
        exit(EXIT_FAILURE);
    }
    string line;
    while (getline(in, line)) {
        istringstream iss(line);
        int v;
        list<int> list_temp;
        int first_item = 0;
        while (iss >> v) {
            first_item++;
            if (first_item == 1) continue;
            list_temp.push_back(v);

        }
        adj_list.push_back(list_temp);

    }



}
// Display information of unweighted graph.
void UnweightedGraph::DisplayInfo() const {
    cout << "Adjacency list of the graph \n";
    int i = 0;
    auto printItem = [&i](const list<int>& alist) {
        cout << i++ << " ";
        copy(begin(alist), end(alist), ostream_iterator<int>(cout, " "));
        cout << endl;

    };
    for_each(begin(adj_list), end(adj_list), printItem);
}

/*
 * Use depth- first-search (DFS) or breadth- first-search(BFS); the important part is you need nextPosition perform DFS or BFS only onceusing arbitrary
 * vertex as an initial vertex.  The graph is connected if andonly if all vertices are visited.
 * /return bool Bool if the unweighted tree is connected or not.
*/
bool UnweightedGraph::IsConnected() const
{
    // Set any other elements found in adj_list as false in checkedPoints vector. 
    std::vector<bool> checkedPoints(adj_list.size());
    int initialPoint = 0;
    list<int> orderedList;
    // Set the first element of the checkedPoints as checked (true).
    checkedPoints[initialPoint] = 1;
    // Add intial point nextPosition orderedList.
    orderedList.push_back(initialPoint);

    // Check the List is not size zero (nothing inside).
    while (orderedList.size() != 0)
    {
        // Set initialPoint as the new front of the orderedList.
        initialPoint = orderedList.front();
        // Remove the first element in orderedList
        //orderedList.pop_front();
        orderedList.erase(orderedList.begin());
        for (std::list<int>::const_iterator ele = adj_list[initialPoint].begin(); ele != adj_list[initialPoint].end(); ++ele)
        {
            if (checkedPoints[*ele] == 0)
            {
                // checkPoint finds a connected pair. We then make that element set nextPosition true and push back true value into orderedList
                checkedPoints[*ele] = 1;
                orderedList.push_back(*ele);
            }
        }
    }
    // Check if checkedPoints have any falses. Then the entire unweighted graph is false.
    for (auto ele : checkedPoints) {
        if (ele == 0) {
            // Return false as there is a false found in checkedPoints
            return 0;
        }
    }
    // If no falses are found in unweighted graph. The graph isConnected true.
    // Clear vector that checks for checkedPoints.
    checkedPoints.clear();
    return 1;
}



/*
* When  constructing  a  graph,  store  degree  seqeuence  into  another vector.  A graph is Eulerian if and only if all degrees of
* vertices are even. As a note, this function does not find the actual Euler cycle, it only determines if the graph contains an Euler cycle.
* /return bool Bool if the unweighted tree is ceulerian or not.
*/
bool UnweightedGraph::IsEulerian() const
{
    for (auto ele : adj_list)
    {
        if (IsEvenSize(ele) != 0)
        {
            // Even
        }
        else
        {
            // One odd case is found. Return false.
            return 0;
        }
    }
    // All elements in adj_list is even (all degrees of vertices are even)/
    return 1;

}

/*
* Check if the parameter number is a even or odd number size. Assume that any graph input nextPosition this function is connected.
* /param list List of integers that contain element of unweighted tree being checked.
* /return bool Bool if the unweighted element is even size or not.
*/
bool UnweightedGraph::IsEvenSize(std::list<int> element) const
{
    // Element is odd when rightmost bit has a one. Element is even if rightmost bit has a zero.
    if ((element.size() & 1) == 0)
    {
        // Is even, return 1.
        return 1;
    }
    else
    {
        // Is odd, return 0.
        return 0;
    }
}

/*
* Returns an euler cycle as a sequence of verteice fromstarting vertex nextPosition ending vertex. In this function, you can assume that the
* graph is connectedand Eulerian.  The running time should beO(|V|+|E|).
* /return list List of int that represent Eulerian cycle.
*/
list<int> UnweightedGraph::FindEulerianCycle() const
{
    // Fill each element within vector as false (0) statements that is the size of adj_list.size().
    std::vector<bool> fillerFalsePoints(adj_list.size());
    std::vector<std::vector<bool> > checkedPoints;
    bool cycleChangeNow = 0;
    // Iterator that increments through each cycle contained in all lists.
    std::vector<std::list<int>::const_iterator> iteratorCycles;
    list<int>::iterator iteratorFinalPointsCycle;
    list<int> finalPointsCycle;
    // Keep track of the positions tracing through elements within finalPointCyle and batchPoints.
    int initalPoint = 0;
    int finalPoint = 0;
    list<int>::iterator iteratorBatchPoints;
    int initialBatchPoint = 0;
    list<int> batchPoints;
    int finalBatchPoint = adj_list.size() + 1;
    bool continueCheck = 0;

    long unsigned int counter = 0;
    /* Iterate through length and insert "false" lists into matrix */
    do
    {
        checkedPoints.push_back(fillerFalsePoints);
        counter += 1;
    } while (counter != adj_list.size());

    /* Construct matrix of checkedPoints that will be filled with fillerrFalsePoints. Now a pointer is
    pointing to the start of checkedPoints and can increment through each point. */
    for (std::vector<std::list<int>>::const_iterator a = adj_list.begin(); a != adj_list.end(); ++a)
    {
        iteratorCycles.push_back(a->begin());
    }

    iteratorFinalPointsCycle = finalPointsCycle.begin();

    // Makes sure there are points to check still and add to finalPointsCycle
    while (continueCheck == 0)
    {
        // Start at any node, then take any edge to visit a neighboring node
        while (initialBatchPoint != finalBatchPoint)
        {
            // Make sure checkedPoints is equivalent to zero at start of cycle.
            if (checkedPoints[initalPoint][*iteratorCycles[initalPoint]] != 0)
            {
                // There is no connection between start point and final batch points
                if (iteratorCycles[initalPoint] == adj_list[initalPoint].end())
                {
                    cycleChangeNow = 0;
                    while (cycleChangeNow == 0)
                    {
                        ++iteratorFinalPointsCycle;
                        if (iteratorFinalPointsCycle == finalPointsCycle.end())
                        {
                            initialBatchPoint = finalBatchPoint;
                            continueCheck = 1;
                            break;
                        }
                        initalPoint = *iteratorFinalPointsCycle;
                        // Start at the common node and continue traversing edges until
                        //  you complete a new cycle
                        if (iteratorCycles[initalPoint] == adj_list[initalPoint].end())
                        {
                        }
                        else
                        {
                            finalPoint = *iteratorCycles[initalPoint];
                            cycleChangeNow = 1;
                        }
                        initialBatchPoint = initalPoint;
                        finalBatchPoint = adj_list.size() + 1;
                    }
                }
                // Find any node that is present in both the current cycle and the subgraph ofunvisited edges
                else
                {
                    iteratorCycles[initalPoint]++;
                    finalPoint = *iteratorCycles[initalPoint];

                }

            }
            else
            {
                finalPoint = *iteratorCycles[initalPoint];
                // Append initialPoint to batch of Points and turn value into true found in checkedPoints
                if (iteratorCycles[initalPoint] != adj_list[initalPoint].end())
                {
                    batchPoints.push_back(initalPoint);
                }
                // Mark the edge traversed as visited
                checkedPoints[initalPoint][finalPoint] = 1;
                checkedPoints[finalPoint][initalPoint] = 1;
                auto holdStart = *iteratorCycles[initalPoint];
                if (iteratorCycles[initalPoint] == adj_list[initalPoint].end())
                {
                }
                else
                {
                    iteratorCycles[initalPoint]++;
                }
                initalPoint = holdStart;
                finalPoint = *iteratorCycles[initalPoint];
                finalBatchPoint = initalPoint;
                if (finalBatchPoint == initialBatchPoint)
                {
                    /* Continue traversing the graph by choosing any unvisited edge until you return to
                    the starting node, completing a cycle */
                    batchPoints.push_back(initalPoint);
                }

            }
        }

        // Splice the new cycle into the original cycle
        if (continueCheck == 0) {
            finalBatchPoint = adj_list.size() + 1;
            iteratorBatchPoints = batchPoints.end();
            --iteratorBatchPoints;
            // Check if final Points cycle size is equivalent to 0, ready to be spliced together with batchPoints.
            if (finalPointsCycle.size() == 0)
            {
                finalPointsCycle.splice(iteratorFinalPointsCycle, batchPoints);
            }
            else
            {
                finalPointsCycle.splice(iteratorFinalPointsCycle, batchPoints, batchPoints.begin(), (iteratorBatchPoints));
            }
            // Free memory by clearing batchPoints for possible next cycle of points.
            batchPoints.clear();
            for (auto c : finalPointsCycle)
            {
                // Go to next cycle once finished with splicing
                if (iteratorCycles[c] != adj_list[c].end())
                {
                    initalPoint = c;
                    finalPoint = *iteratorCycles[c];
                    finalBatchPoint = adj_list.size();
                    initialBatchPoint = initalPoint;
                    break;
                }
            }
        }
    }
    return finalPointsCycle;
}



/*
* Returns true if the input list (i.e., a sequence of ver-tices) forms an Euler cycle, and false otherwise.  The running time shouldbeO(|V|+|E|).
* /param list List of int of the euler cycle
* /return bool Bool of if parameter is valid euler cycle or not.
*/
bool UnweightedGraph::VerifyEulerCycle(const list<int>& cycle) const
{
    std::vector<bool> fillerFalsePoints(adj_list.size());
    /* Iterate through length and insert "false" lists into matrix */
    std::vector<std::vector<bool>> checkedPoints(adj_list.size(), fillerFalsePoints);
    auto cycleIteratorUpcoming = cycle.begin();
    bool check = quickCheckEulerCycle(cycle);
    // Returns result of quick checks
    if (check == 1)
    {
        return 1;
    }
    else if (check == 0)
    {
        return 0;
    }
    // After this point all quick checks failed.
    for (auto a = cycle.begin(); a != cycle.end(); ++a)
    {
        cycleIteratorUpcoming = a;
        ++cycleIteratorUpcoming;
        if (a != cycle.end())
        {
            if (checkedPoints[*a][*cycleIteratorUpcoming] == 0)
            {
                // In Eulerian cycle, it must visit every edge exactlyonce and end at the starting node
                if (cycleIteratorUpcoming != cycle.end())
                {
                }
                else
                {
                    // Must end at the starting node
                    return 1;
                }
                // Mark the edge traversed as visited
                checkedPoints[*a][*cycleIteratorUpcoming] = 1;
                checkedPoints[*cycleIteratorUpcoming][*a] = 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

/*
* Returns 1 if the input list (i.e., a sequence of ver-tices) forms an Euler cycle, and 0 otherwise. If none of the quick checks pass, return 3. The running time shouldbeO(|V|+|E|).
* /param list List of int of the euler cycle
* /return int Int of if parameter is valid euler cycle (1) or not (0). Or none fast checks found return 3.
*/
int UnweightedGraph::quickCheckEulerCycle(const list<int>& cycle) const
{
    int counter = 0;
    // Check that there is edges to check before verifying Euler cycle.
    if (adj_list.size() == 0)
    {
        return 0;
    }

    // Count each element found in adj_listf
    for (long unsigned int a = 0; a != adj_list.size(); ++a)
    {
        for (long unsigned int b = 0; b != adj_list[a].size(); ++b)
        {
            counter += 1;
        }
    }

    // Check that half of the elements out of all elements is equivalent to cyclesize - 1. This ensures quickly
    // that all elements in the cycle are there in the final adj_list.
    if ((long unsigned int)(counter / 2) == (long unsigned int)(cycle.size() - 1))
    {

    }
    else
    {
        return 0;
    }
        
    // If counter is zero, it is a Euler cycle and return 1.
    if (counter == 0)
    {
        return 1;
    }

    // All quick checks failed. Return 3.
    return 3;
}