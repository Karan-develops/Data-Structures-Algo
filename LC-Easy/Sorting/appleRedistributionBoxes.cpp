// LC - 3074 - Easy - Apple Redistribution into Boxes
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int minimumBoxes(vector<int>&apple,vector<int>&capacity){
    int total=accumulate(begin(apple),end(apple),0);

    sort(begin(capacity),end(capacity),greater<>());

    int ans=0;

    for(int &i:capacity){
        total-=i;
        ans++;

        if(total<=0) return ans;
    }

    return -1;
}
int main(){
    // Output: 2
    vector<int>apple={1,3,2},capacity={4,3,1,5,2};
    // Output: 4
    vector<int>apple2={5,5,5},capacity2={2,4,2,7};
    cout<<minimumBoxes(apple,capacity)<<endl;
    cout<<minimumBoxes(apple2,capacity2);
    return 0;
}