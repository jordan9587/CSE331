/**
 * \file UnweightedGraph.h
 *
 * \author Jordan Hybki
 */

#ifndef UnweightedGraph_H
#define UnweightedGraph_H
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class UnweightedGraph
{
public:
    UnweightedGraph(const string& t);
    void DisplayInfo() const;
    bool IsConnected() const;
    bool IsEulerian() const;
    bool IsEvenSize(std::list<int> element) const;
    std::list<int> FindEulerianCycle() const;

    bool VerifyEulerCycle(const list<int>& cycle) const;
    int quickCheckEulerCycle(const list<int>& cycle) const;

private:
    std::vector<std::list<int>> adj_list;

    //Add any attribute or method that can help complete your implementation

};
#endif

