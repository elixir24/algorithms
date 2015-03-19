#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class interval {
    public:
        int beg;
        int end;
        interval(int x, int y){
            this->beg = x;
            this->end = y;
        }
};

bool compare(interval* a, interval* b){
    return a->beg < b->beg;
}

interval* makeInterval(int beg, int end){
    return new interval(beg, end);
}

vector<interval*> mergeInterval(vector<interval*> arg){
    if(arg.size() == 0) return arg;
    sort(arg.begin(), arg.end(), compare);
    interval* prev = arg[0];
    vector<interval*> ans; //list to return
    for( int i = 1; i < arg.size(); i++){
        interval* curr = arg[i];
        if( curr-> beg > prev->end){//disjoint intervals
            ans.push_back(prev);
            prev = curr;
        }else{//merge these intervals
            interval* temp = makeInterval(prev->beg, max(prev->end, curr->end));
            free(prev);
            free(curr);
            prev = temp;
        }
    }
    ans.push_back(prev);
    return ans;
}

void printInterval(vector<interval*> arg){
    for(int i = 0; i < arg.size(); i++){
        cout<<arg[i]->beg<<"->"<<arg[i]->end<<", ";
    }
    cout<<endl;
    return;
}

int main(){
    vector<interval*> v;
    v.push_back(makeInterval(5,10));
    v.push_back(makeInterval(9,10));
    v.push_back(makeInterval(4,13));
    v.push_back(makeInterval(13,15));
    printInterval(v);
    vector<interval*> merged = mergeInterval(v);
    printInterval(merged);
    for(int i = 0; i < merged.size(); i++){
        free(merged[i]);
    }
    return 0;
}
}
