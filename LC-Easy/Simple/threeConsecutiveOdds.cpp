// LC - 1550 - Easy - Three Consecutive Odds
#include<iostream>
#include<vector>
using namespace std;
bool threeConsecutiveOdds(vector<int>& arr) {
    int n=arr.size();
    for(int i=0;i<n-2;i++){
        if(arr[i]%2!=0 && arr[i+1]%2!=0 && arr[i+2]%2!=0) return true;
    }
    return false;
}
int main(){
    // Output: false
    vector<int>arr={2,6,4,1};
    // Output: true
    vector<int>arr2={1,2,34,3,4,5,7,23,12};
    cout<<threeConsecutiveOdds(arr)<<endl;
    cout<<threeConsecutiveOdds(arr2);
    return 0;
}