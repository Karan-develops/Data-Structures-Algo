// LC - 2951 - Easy - Find the Peaks
#include<iostream>
#include<vector>
using namespace std;
vector<int> findPeaks(vector<int>&mountain){
    int n=mountain.size();
    vector<int>ans;
    for(int i=1;i<n-1;i++){
        if(mountain[i]>mountain[i-1] && mountain[i]>mountain[i+1]){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    // Output: []
    vector<int>mountain={2,4,4};
    // Output: [1,3]
    vector<int>mountain2={1,4,3,8,5};
    return 0;
}