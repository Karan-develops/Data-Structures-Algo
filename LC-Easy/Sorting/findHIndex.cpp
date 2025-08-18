// GFG - Find H-Index
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int hIndex(vector<int>&citations){
    sort(begin(citations),end(citations),greater<>());
    
    int i=0;
    while(citations[i]>=i+1 && i<citations.size()) i++;
    
    return i;
}
int main(){
    // Output: 3
    vector<int>citations={3,0,5,3,0};
    // Output: 2
    vector<int>citations2={5,1,2,4,1};
    // Output: 0
    vector<int>citations3={0,0};
    cout<<hIndex(citations)<<endl;
    cout<<hIndex(citations2)<<endl;
    cout<<hIndex(citations3);
    return 0;
}