/*
 * graph.h
 *
 *  Created on: May 18, 2013
 *      Author: piyushm
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;

class graph{

private :
	vector< vector< pair<int,int> > > g;
	/* Size if the graph */
	int size;

public :

	/* Please set/reset this vector while using it.
	 * This is public so that it can read in other scopes.
	 */
	vector<int> visited;
	graph(int size);
	void addEdge(int source, int dest, int val);
	void printGraph();
};


#endif /* GRAPH_H_ */
