// LC - 1046 - Easy
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int>pq;
    for(auto i:stones) pq.push(i);
    while(pq.size()>1){
        int topVal=pq.top(); pq.pop();
        if(!pq.empty()){
            if(pq.top()==topVal) pq.pop();
            else{
                pq.pop();
                pq.push(topVal-pq.top());
            }
        }
    }
    return pq.top()?pq.top():0;
}
int main(){
    // OP - 1
    vector<int>stones1={2,7,4,1,8,1};
    // OP - 1
    vector<int>stones2={1};
    cout<<lastStoneWeight(stones1)<<endl;
    cout<<lastStoneWeight(stones2);
    return 0;
}