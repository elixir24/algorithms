/*
 * segmentTree.cpp
 *
 *  Created on: May 7, 2013
 *      Author: piyushm
 */

/*
 * Segment tree is useful for finding max, min, sum of values between range
 * of indexes in an array.
 *
 * If size of array is N
 * Approx size of segment array is 2*N-1
 */

#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<math.h>

using namespace std;

typedef vector<int>::iterator vit;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef vector<int> vi;
typedef long long ll;

#define rep(i,a) repab(i,0,a)
#define repab(i,a,b) repabc(i,a,b,1)
#define repabc(i,a,b,c) for(int i=a;i<b;i+=c)
#define foreach(i,a) for((typeof(a).begin()) i=(a).begin();i!=(a).end();i++)
#define mod(x) ((x>0)?x:(-x))
#define SS ({int x;scanf("%d",&x);x;})
#define mp make_pair
#define pb push_back
#define pvar(i)   cout<<i<<endl;



/* Constants*/
#define left(x) (2*x+1)
#define right(x) (2*x+2)


int makeSegTree(int burnrates[], int start, int end, int segTree[], int node){

	if(start==end){ return segTree[node]=burnrates[start];}

	int mid = (start+end)/2; //find mid

	int left = makeSegTree(burnrates,start, mid,segTree, left(node));
	int right = makeSegTree(burnrates,mid+1,end,segTree,right(node));
	if (left>=right)
		return segTree[node]=left;
	else
		return segTree[node]=right;
}

int query(int start, int end, int segTree[],int l, int r, int index){

	if(l<=start && r>=end){
		return segTree[index];}

	if(r<start || l>end){
		return -1;}

	int mid = (start+end)/2;
	int left = query(start,mid,segTree,l,r,left(index));
	int right= query(mid+1,end,segTree,l,r,right(index));

	if(left==-1) return right;
	else if (right==-1) return left;
	else if (left>=right) return left;
	else return right;

}


int main(){

	int arr[18]= {3, 4, 2, 1, 5 ,7 ,9, 7, 10, 5, 12, 3, 1, 1, 2, 1, 3, 2};
	int segMax[64];
	memset(segMax,-1,64);
	makeSegTree(arr,0,17,segMax,0);

	cout<<query(0,17,segMax,0,1,0);

}
