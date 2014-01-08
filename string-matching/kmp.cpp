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

//Make sure that array size atleast as much as the pattern length
int suffix[1000];

void preprocess(string pattern){
    pattern = "$" + pattern;
    memset(suffix, 0, sizeof(suffix));
    int m = pattern.length();
    suffix[1] = 0;
    int k = 0;
    rep(i,2,m){
        while((k > 0) && (pattern[i]!=pattern[k+1]))
            k = suffix[k];
        if( pattern[i] == pattern[k+1])
            k+=1;
        suffix[i] = k;
    }
}

vector<int> kmp_match(string pattern,string text){
    vector<int> shifts;
    int m = pattern.length();
    int n = text.length();
    int k = 0;
    pattern = "$" + pattern;
    text = "$" + text;
    rep(i,1,text.length()){
        while( k>0 && (text[i]!= pattern[k+1]))
            k = suffix[k];
        if(text[i] == pattern[k+1])
            k+=1;
        if( k == m){
            shifts.push_back(i-m);
            k = suffix[k];
        }
    }
    return shifts;
}

int main(){
    string text ="91231231238";
    string pattern = "1231238";
    preprocess(pattern);
    vector<int> shifts = kmp_match(pattern, text);
    rep(i,0,shifts.size())cout<<shifts[i]<<" ";
    return 0;
}
