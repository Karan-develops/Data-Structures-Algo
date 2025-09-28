// GFG - Longest Bounded-Difference Subarray
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> longestSubarray(vector<int>&arr,int x){
    int n=arr.size();
    
    deque<int>maxdq,mindq;
    int i=0,left=0,bestL=0;

    for(int j=0;j<n;j++){
        while(!maxdq.empty() && arr[maxdq.back()]<=arr[j]){
            maxdq.pop_back();
        }
        maxdq.push_back(j);

        while(!mindq.empty() && arr[mindq.back()]>=arr[j]){
            mindq.pop_back();
        }
        mindq.push_back(j);

        while(arr[maxdq.front()]-arr[mindq.front()]>x){
            if(maxdq.front()==i) maxdq.pop_front();
            if(mindq.front()==i) mindq.pop_front();
            i++;
        }

        if(j-i+1>bestL){
            bestL=j-i+1;
            left=i;
        }
    }

    return vector<int>(begin(arr)+left,begin(arr)+left+bestL);
}
int main(){
    // Output: [4, 5, 6, 7]
    vector<int>arr={8,4,5,6,7};
    int x=3;
    // Output: [12, 13, 14]
    vector<int>arr2={1,10,12,13,14};
    int x2=2;
    return 0;
}