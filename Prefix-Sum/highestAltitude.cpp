// LC - 1732 - Easy - Find the Highest Altitude
#include<iostream>
#include<vector>
using namespace std;
int largestAltitude(vector<int>& gain) {
    int n=gain.size();
    int ans=0,curr=0;
    for(int &i:gain){
        curr+=i;
        ans=max(ans,curr);
    }
    return ans;
}
int main(){
    // Output: 1
    vector<int>gain={-5,1,5,0,-7};
    // Output: 0
    vector<int>gain2={-4,-3,-2,-1,4,3,2};
    cout<<largestAltitude(gain)<<endl;
    cout<<largestAltitude(gain2);
    return 0;
}