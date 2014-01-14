#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory.h>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#define eps 1e-9
typedef long long ll;
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)


int main(){
    
    string pattern = "AABA";
    string text = "AABAACAADAABAAABAA";
    int n = text.length();
    int m = pattern.length();

    map<char,int> mapping;
    rep(i,0,m) mapping[pattern[i]]=i;
    int shift = 0;
    int i = m-1;
    while(i < n){
        int j;
        for(j = 0; j < m; j++){
            if(pattern[m-1-j] != text[i-j]){
                map<char,int>::iterator it = mapping.find(text[i-j]);
                if( it == mapping.end()){
                    shift = m - j;
                }else{
                    shift = max(1,m-1-mapping[text[i-j]]);
                }
                break;
            }
        }
        if( j == m){
            cout<<"Match found starting at index "<< (i - m + 1)<<endl;
            i++;
        }else{
            i += shift;
        }
    }
}
