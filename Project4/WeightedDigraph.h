/**
 * \file WeightedDigraph.h
 *
 * \author Jordan Hybki
 */

#ifndef WeightedDigraph_H
#define WeightedDigraph_H

#include<list>
#include<vector>
#include<string>

class WeightedDigraph {
public:
	WeightedDigraph(const std::string& filename);
	~WeightedDigraph();
	WeightedDigraph(const WeightedDigraph&) = delete;
	WeightedDigraph& operator=(const WeightedDigraph&) = delete;
	
	int GetOrder() const { return numVertices; };
	int GetSize() const { return numArcs; };
	double GetPathWeight(const std::list<int> & path) const;
	bool DoesPathExist(int from, int to) const;
	bool IsPathValid(const std::list<int> & path) const;
	bool IsLinked(int previousPosition, int nextPosition) const;
	std::list<int> FindMinimumWeightedPath(int from, int to) const;
	
private:
	int numVertices = 0;
	int numArcs = 0;
    bool _DoesPathExist(int from, int to, std::list<int>& checkedPoints) const;
	std::vector<std::list<std::pair<int, double>>> weightedArc;
	void InsertArc(int from, int to, double weight);
};

#endif
