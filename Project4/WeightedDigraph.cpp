/**
 * \file WeightedDigraph.cpp
 *
 * \author Jordan Hybki
 */

#include "WeightedDigraph.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>

using namespace std;

/**
 * Constructs the digraph from a file.
 * You may add any additional construction to this section.
 */
WeightedDigraph::WeightedDigraph(const string& filename) : numVertices(0), numArcs(0)
{
	ifstream in(filename);
	if(!in.is_open()) 
	{
		cerr << "cannot open file!" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	string line;
	getline(in, line);
	istringstream vertexStream(line);
	vertexStream >> numVertices;
	
	// TODO : You can initialize your data structure here.
	weightedArc.resize(numVertices);
	while(getline(in,line)) 
	{
		istringstream iss(line);
		int u, v;
		float weight;
		iss >> u >> v >> weight;
		InsertArc(u, v, weight);
	}
}

/**
 * Destructor
 * You can do any needed cleanup here.
 */
WeightedDigraph::~WeightedDigraph() 
{
	// Intentionally left empty
	// You may do any needed cleanup here
}

/**
 * Inserts a weighted arc into the digraph.
 * This is the sole mutator of this class and it is private
 * so the digraph is immutable once created.
 */
void WeightedDigraph::InsertArc(int from, int to, double weight)
{
    // Push into weightedArc each pair found in input.
    auto arcPair = pair<int,int>(to,weight);
    // Adds an arc to given wieght between two verticies.
	weightedArc[from].push_back(arcPair);
	// Increase counter for found Arcs from input.
    numArcs += 1;
}

 
/**
 * Finds the sum weight of the given path.
 * Returns infinity if the path is broken.
 */
double WeightedDigraph::GetPathWeight(const list<int> & path) const
{
    double Result = 0;
    int arcWeight = 0;
    int previousPosition = -1;
    int currentWeight = 0;
    bool completed = 0;
    
    for (auto ele : path)
    {
        // Finds the weight of the sum of a directed path. Assumes input is valid path.
        if (previousPosition >= 0)
        {
            for (auto ele1 : weightedArc[previousPosition])
            {
                if (ele1.first != ele)
                {
                    // The first key in pair is not equal to current element in path parameter
                }
                else
                {
                    // Swap arcWeight with value in pair and signal completed all paths.
                    arcWeight = ele1.second;
                    completed = 1;
                }
            }
            if(completed == 0)
            {
                // Path is broken, return infinity.
                currentWeight = std::numeric_limits<int>::infinity();
            }
            else
            {
                // Path is not broken, set arcWeight as currentWeight
                currentWeight = arcWeight;
            }
            if (currentWeight != std::numeric_limits<int>::infinity())
            {
                // Add each currentWeight (non broken path) to total result of weight.
                Result += currentWeight;
            }
            else
            {
                // All paths are broken with current input, return infinity.
                return std::numeric_limits<int>::infinity();
            }
           
        }
        // Swap the key in pair with previous position.
        previousPosition = ele;
    }
    return Result;
}


/**
 * Recursivelt determines whether a path between the two vertices exists.
 */
bool WeightedDigraph::_DoesPathExist(int from, int to, std::list<int>& checkedPoints) const 
{
    bool pathValid = 0;
	checkedPoints.push_back(from);
	
	for(auto ele : weightedArc[from])
	{
	    // Given the first vertex parameter u and the second v, this function does not test to see if there 
	    // is just a single arc from u to v but a directed path from u to v. 
	    // As such, you will need to use a graph searching algorithm like dfs or bfs.
		if(std::find(checkedPoints.begin(), checkedPoints.end(), ele.first) == checkedPoints.end())
		{
			if(ele.first != to) 
			{
			    // The next element is not equivalent to key of pair. Means path is not finished.
			}
			else
			{
			    // We are at the end of the path, return true as the key is equivalent to next key of pair.
			    return 1;
			}
			// Recursively call itself with the new previous key being the key of the next pair.
			pathValid = _DoesPathExist(ele.first, to, checkedPoints);
			if(pathValid == 0)
			{
			//  if you use a visited variable which keeps track of which vertices are visited in the search 
			// of the graph you should reset this variable after or before your call to DoesPathExist
			}
			else
			{
			    // Break if path is Valid from checks above.
			    break;
			}
			
		}
	}
	return pathValid;
}

/**
 * Determines whether a path between the two vertices exists.
 */
bool WeightedDigraph::DoesPathExist(int from, int to) const 
{
    std::list<int> checkedPoints;
    // Checks whether a directed path exists between two verticies.
	return _DoesPathExist(from, to, checkedPoints);
}

/**
 * Checks whether the given path goes over existing arcs.
 */
bool WeightedDigraph::IsPathValid(const list<int> & path) const 
{
    
    auto nextPosition = path.begin();
	auto previousPosition = nextPosition;
	++nextPosition;
	for (; nextPosition != path.end(); ++nextPosition)
	{
	    // Determines whether an arc exists along each step of the path.
		if (IsLinked(*previousPosition, *nextPosition) != 0)
		{
		    // Swap the next position with previous position.
		    previousPosition = nextPosition;
		}
		else
		{
		    return 0;
		}
	}
	return 1;
}

/**
 * Checks whether the given link is a valid arc.
 */
bool WeightedDigraph::IsLinked(int previousPosition, int nextPosition) const 
{
    // Seach through each list of pair key for nextPosition parameter, storing pointer if found. If not found, return the end pointer of the list of pair.
    auto linkedPosition = std::find_if(weightedArc[previousPosition].begin(), weightedArc[previousPosition].end(), [nextPosition](std::pair<int, double> const &a) { return a.first == nextPosition; });
    // Check if pointer is at the end of the end pointer of the list of pair.
	if (linkedPosition == weightedArc[previousPosition].end())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


/**
 * Finds a path of minimum weight between the two nodes.
 * The behavior is undefined if no such path exists
 * (you may assume that such a path does exist).
 */
list<int> WeightedDigraph::FindMinimumWeightedPath(int from, int to) const 
{
    // Fill worst case vector at numVertices size with 0's
    vector<int> worstCase(numVertices,0);
    // Fill vector at numVertices size with infinities
	vector<double> checkedPairs(numVertices,std::numeric_limits<double>::infinity());
	checkedPairs[from] = 0;
	std::list<int> Result;
	// Used priority queue to help select minimum weight edges to add to your path. 
	set<pair<int, double>> worstCasePath;
	// where the distance is the key and the vertex index is the value.  Set insertion takes O(log n) time.
	
	// Insert as pairs the parameter from and vector filled with infinities.
	worstCasePath.insert(std::make_pair(from, checkedPairs[from]));

	if (from != to)
	{
	    // Means path is not valid here. As the previous and next verticy is not the same.
	}
    else
    {
        // Path is valid, increment each from into result list.
        Result.push_front(from);
		return Result;
    }
    

	while (worstCasePath.empty() == 0)
	{
	    // Fill worst case path with each key and value found in adhacent paths.
		int currentPosition = worstCasePath.begin()->first;
		double lengthWeight = worstCasePath.begin()->second;
		auto adjacentPaths = weightedArc[currentPosition];
		worstCasePath.erase(worstCasePath.begin());
		for (auto a = adjacentPaths.begin(); a != adjacentPaths.end(); ++a)
		{
			int ele = a->first;
			double currentWeight = a->second;
			double currentLength = lengthWeight + currentWeight;
			if (currentLength >= checkedPairs[ele])
			{
			}
            else
            {
                // Erase the paths that are valid. Changing checkedPairs and worst case pairs key and value placements.
                worstCasePath.erase(std::make_pair(ele, checkedPairs[ele]));
				checkedPairs[ele] = currentLength;
				worstCase[ele] = currentPosition;
				worstCasePath.insert(std::make_pair(ele, checkedPairs[ele]));
            }
		}
	}
    // Add each element in worst case into result, starting from the initial parameter to position.
	for (auto ele = to; ele != 0; ele = worstCase[ele])
    {
		Result.push_front(ele);
    }
	return Result;
}