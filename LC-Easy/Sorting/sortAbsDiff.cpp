// GFG - Sort by Absolute Difference
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rearrange(vector<int>&arr,int x){
    auto lambda=[&](int a,int b){
        return abs(x-a)<abs(x-b);
    };
    
    stable_sort(begin(arr),end(arr),lambda);
}
int main(){
    // Output: [5, 9, 10, 3, 2]
    int x=7;
    vector<int>arr={10,5,3,9,2};
    // Output: [5, 4, 3, 2, 1]
    int x2=6;
    vector<int>arr2={1,2,3,4,5};
    rearrange(arr,x);
    rearrange(arr2,x2);
    return 0;
}