#include <iostream>
#include <algorithm>
#include <stdio.h>
 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAX 100
#define N 7

int main() {
  
  int input[MAX]= {1,3,8,4,6,5,8};
	int best[N];
	memset(best, 0, sizeof(best));
	
	best[0]= input[0];
	int len =1;

	for( int i=1; i<N; i++){
		int j= len-1;
		for(; j>=0;j--)
			if(input[i] < best[j]) 
			break;
		if(j == len-1) {j++;len++;}
		else if( j== -1) j=0;
		else j++;
		best[j] = input[i];
	}
	
	cout<<len<<endl;
    return 0;
}
