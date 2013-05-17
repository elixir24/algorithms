/*
 * disjoint-set.cpp
 *
 *  Created on: May 17, 2013
 *      Author: piyushm
 */
#include<iostream>
using namespace std;

int p[1000]; //memset this to -1
int rank[1000];//memset this to 0

void makeSet(int x){ p[x]=x; rank[x]=0;}

int findSet(int x){ if(p[x]==-1)return -1; if(p[x]!=x) p[x] =findSet(p[x]); return p[x];}

void unionSet(int x, int y){
	x =findSet(x); y =findSet(y);
	if(x!= y){
		if(rank[x]>rank[y]) p[y]=x;
		else {p[x]=y;
			if(rank[x]==rank[y])rank[y]++;
		}
	}
}
