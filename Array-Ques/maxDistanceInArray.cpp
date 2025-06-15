// LC - 624 - Medium - Maximum Distance in Arrays
#include<iostream>
#include<vector>
using namespace std;
int maxDistance(vector<vector<int>>& arrays) {
    int MIN=arrays[0].front();
    int MAX=arrays[0].back();

    int ans=0;

    for(int i=1;i<arrays.size();i++){
        int currMin=arrays[i].front();
        int currMax=arrays[i].back();

        ans=max(ans,max(abs(currMin-MAX),abs(currMax-MIN)));

        MAX=max(MAX,currMax);
        MIN=min(MIN,currMin);
    }
    return ans;
}
int main(){
    // Output: 4
    vector<vector<int>>arrays={{1,2,3},{4,5},{1,2,3}};
    // Output: 0
    vector<vector<int>>arrays2={{1},{1}};
    cout<<maxDistance(arrays)<<endl;
    cout<<maxDistance(arrays2);
    return 0;
}