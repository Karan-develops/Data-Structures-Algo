// LC - 1046 - Easy - Last Stone Weight
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int lastStoneWeight(vector<int>&stones){
    priority_queue<int>pq(begin(stones),end(stones));

    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();

        if(a!=b) pq.push(abs(a-b));
    }
    
    if(pq.size()>0) return pq.top();
    
    return 0;
}
int main(){
    // Output: 1
    vector<int>stones={2,7,4,1,8,1};
    // Output: 1
    vector<int>stones2={1};
    cout<<lastStoneWeight(stones)<<endl;
    cout<<lastStoneWeight(stones2);
    return 0;
}