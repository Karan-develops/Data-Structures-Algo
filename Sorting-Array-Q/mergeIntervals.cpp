// LC - 56 - Medium - Merge Intervals
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>&intervals){
    sort(intervals.begin(),intervals.end());

    int n=intervals.size();
    vector<vector<int>>ans;
    ans.push_back(intervals[0]);

    for(int i=1;i<n;i++){
        // Overlapping
        if(intervals[i][0]<=ans.back()[1]){
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        } else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
int main(){
    // Output: [[1,6],[8,10],[15,18]]
    vector<vector<int>>intervals={{1,3},{2,6},{8,10},{15,18}};
    // Output: [[1,5]]
    vector<vector<int>>intervals2={{1,4},{4,5}};
    vector<vector<int>>ans1=merge(intervals);
    vector<vector<int>>ans2=merge(intervals2);

    for(auto &vec:ans1){
        cout<<"{";
        for(auto &i:vec) cout<<i<<" ";
        cout<<"}";
    }
    cout<<endl;
    for(auto &vec:ans2){
        cout<<"{";
        for(auto &i:vec) cout<<i<<" ";
        cout<<"}";
    }
    return 0;
}