/*
 * graph.cpp
 *
 *  Created on: May 5, 2013
 *      Author: piyushm
 */

#include "graph.h"

graph::graph(int size){
	this->size=size;
	vector< vector< pair<int,int> > > v(size, -1);
	g = v;
}

void graph::addEdge(int source, int dest, int val){
	g[source].push_back(make_pair(dest,val));
}

void graph::printGraph(){
	for(int i=0;i<size;i++){
		if(g[i].size()!=0){
			printf("%d ->",i);
			for(int j=0;j<(int)g[i].size();j++)
				printf("%d ",g[i][j].first);
			printf("\n");
		}
	}
}





