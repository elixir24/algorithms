$ cat interval.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class interval{
    public:
        int beg;
        int end;
    interval(int x, int y){
        this->beg = x;
        this->end = y;
    }
};

bool compare(interval a , interval b){
    return a.beg <  b.beg;
}

void printInterval(vector<interval> arg){
    for(int i = 0; i < arg.size(); i++){
        cout<<arg[i].beg<<" "<<arg[i].end<<endl;
    }
    cout<<endl;
    return;
}

vector<interval> mergeInterval(vector<interval> arg){
   sort(arg.begin(), arg.end(), compare);

   if(arg.size()==1)
       return arg;

    interval init = arg[0];
    vector<interval> ans;//vector to return
    for(int i = 1; i < arg.size(); i++){
        interval next = arg[i];
        if( next.beg > init.end){
            ans.push_back(init);
            init = next;
        }else{
            init = interval(init.beg, max(init.end,next.end));
        }
    }
   ans.push_back(init);
   return ans;
}


int main(){
    vector<interval> v;
    v.push_back(interval(5,10));
    v.push_back(interval(9,10));
    v.push_back(interval(8,11));
    v.push_back(interval(4,13));
    v.push_back(interval(13,15));
    printInterval(v);
    vector<interval> xx = mergeInterval(v);
    printInterval(xx);
    return 0;
}
