// LC - 1526 - HARD - Minimum Number of Increments on Subarrays to Form a Target Array
// Harder Version → https://github.com/Karan-develops/Data-Structures-Algo/blob/main/Array-Ques/Prev-Curr/minOperationsToMakeArrayEqualTarget.cpp
#include<iostream>
#include<vector>
using namespace std;
int minNumberOperations(vector<int>&target){
    int n=target.size();

    long long ans=0;

    int curr=0,prev=0;

    for(int i=0;i<n;i++){
        curr=target[i];

        if(abs(curr)>abs(prev)){
            ans+=abs(curr-prev);
        }

        prev=curr;
    }

    return ans;
}
int main(){
    // Output: 3
    vector<int>target={1,2,3,2,1};
    // Output: 4
    vector<int>target2={3,1,1,2};
    // Output: 7
    vector<int>target3={3,1,5,4,2};
    cout<<minNumberOperations(target)<<endl;
    cout<<minNumberOperations(target2)<<endl;
    cout<<minNumberOperations(target3);
    return 0;
}