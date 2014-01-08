#include "graph.h"
#include<iostream>

#define INF 10e7
using namespace std;

void relax( int u, int v , int d[], graph g){

  int w = g.getWeight(u,v);
	if( d[u]!= INF){
		if( d[v] > d[u]+ w){
			d[v] = d[u] + w;
		}
	}
}

void BellMan_Ford( graph g, int source, int d[]){
	
	for( int i =0; i< g.getSize()-1; i++){
		for( int j=1; j< g.getSize()+1;j++){
			vector<pair<int,int> >  edgeList = g.getEdgeListForVertex(j);
			for( int k =0; k< (int)edgeList.size();k++){
				relax(j,  edgeList[k].first, d,g);
			}
		}
	}
}



int main(){
	
	graph g(5);
	g.addEdge(1,2,6); g.addEdge(1,3,7);  g.addEdge(2,4,5);
	g.addEdge(2,3,8); g.addEdge(2,5,-4); g.addEdge(3,4,-3);
	g.addEdge(3,5,9); g.addEdge(4,2,-2); g.addEdge(5,4,7);
	
	int d[6];
	for( int i=1; i<6; i++){
		d[i] = INF;
	}

	d[1] = 0;

	BellMan_Ford(g,1, d);

	for( int i=1; i<6; i++){
		cout<<d[i]<<" ";
	}
}
