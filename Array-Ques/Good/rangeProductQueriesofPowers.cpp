// LC - 2438 - Medium - Range Product Queries of Powers
// Topics -> Array, Bit Manipulation, Prefix Sum
#include<iostream>
#include<vector>
using namespace std;
const int M=1e9+7;
vector<int> productQueries(int n,vector<vector<int>>&queries){
    vector<int>powers;
    vector<int>ans;

    for(int i=0;i<32;i++){
        if(((1<<i)&n)!=0){
            powers.push_back(1<<i);
        }
    }

    for(auto &vec:queries){
        int start=vec[0];
        int end=vec[1];

        long product=1;
        
        for(int i=start;i<=end;i++){
            product=(product*powers[i])%M;
        }
        ans.push_back(product);
    }
    return ans;
}
int main(){
    // Output: [2,4,64]
    int n=15;
    vector<vector<int>>queries={{0,1},{2,2},{0,3}};
    // Output: [2]
    int n=2;
    vector<vector<int>>queries2={{0,0}};
    return 0;
}