/*
 * graph.h
 *
 *  Created on: May 18, 2013
 *      Author: piyushm
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<vector>
#include<assert.h>
using namespace std;

class graph{

private:
	
	//Actual data structure storing the graph
	vector<vector<pair<int, int> > > g;
	//size of the graph
	int vertexSize; 

public:

	graph(int vertexSize){
		this->vertexSize = vertexSize;
		this->g.resize(vertexSize+1);
	}

	
	void addEdge( const int source, const int destination, const int weight){
		assert( (source <= this->vertexSize) && (destination <= this->vertexSize) );
		g[source].push_back(make_pair(destination,weight));
	}

	void printGraph(){
		for(int i=0;i<vertexSize;i++){
		if(g[i].size()!=0){
			printf("%d ->",i);
			for(int j=0;j<(int)g[i].size();j++)
				printf("%d ",g[i][j].first);
			printf("\n");
			}
		}
	}

	/* Returns true if the edge is present and is deleted success
	fully, returns false otherwise*/
	bool removeEdge(const int source, const int destination){
		
		assert( (source <= this->vertexSize) && (destination <= this->vertexSize) );
		vector<pair<int, int> > v = g[source];
		int i;
		for( i = 0; i< (int)v.size(); i++){
			if(v[i].first == destination)
				break;
		}
		//vector<pair<int,int> > co
		if(i!= (int)v.size()){//this means element has been found
			v.erase(v.begin()+i);
			g[source] = v; //reset the vector from which the value has been deleted
			return true;
		}else
			return false;
	}
};


#endif /* GRAPH_H_ */
