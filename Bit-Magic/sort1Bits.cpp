// LC - 1356 - Easy - Sort Integers by The Number of 1 Bits
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sortByBits(vector<int>& arr) {
    auto lambda=[&](int &x,int &y){
        int xC=__builtin_popcount(x);
        int yC=__builtin_popcount(y);
        return xC==yC ? x<y : xC<yC;
    };

    sort(begin(arr),end(arr),lambda);
    return arr;
}
int main(){
    // Output: [0,1,2,4,8,3,5,6,7]
    vector<int>arr={0,1,2,3,4,5,6,7,8};
    // Output: [1,2,4,8,16,32,64,128,256,512,1024]
    vector<int>arr2={1024,512,256,128,64,32,16,8,4,2,1};
    return 0;
}