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
#define prime 13

int mod(int x){
    while( x < 0)
        x+= prime;
    return (x%prime) ;
}

vector<int> rabin_karp(string text, string pattern, int radix, char fc){

    vector<int> shifts;
    int m = pattern.length();
    int n = text.length();
    int h = 1;
    rep(i,0,m-1) h=mod(h*radix);
    int patternhash = 0;
    int texthash = 0;

    rep(i,0,m){
        patternhash = mod(mod(patternhash*radix) + (pattern[i]-fc+1));
        texthash = mod(mod(texthash*radix) + (text[i]-fc+1));
    }  
    
    rep(i,m,n+1){
        if(patternhash == texthash){
            bool match = true;
            rep(j,0,m){
                if(text[i - m + j] != pattern[j]){
                    match = false; 
                    break;
                }
            }
            if(match) 
                shifts.push_back(i-m);
        }
        if(i != n){
            texthash = mod(mod(mod(texthash - (text[i-m]-fc+1)*h)*radix) + (text[i]-fc+1));
        }
    }
    return shifts;
}

int main(){

    string text ="2359023141526739921";
    string pattern = "31415";
    vector<int> shifts = rabin_karp(text, pattern,10,'1');
    rep(i,0, shifts.size())
        cout<<shifts[i]<<endl;
    return 0;
}
