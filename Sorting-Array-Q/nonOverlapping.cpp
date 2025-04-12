// LC - 435 - Medium - Non-overlapping Intervals
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(begin(intervals),end(intervals));
    int ans=0;
    int last=intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(last>intervals[i][0]){
            last=min(last,intervals[i][1]);
            ans++;
        } else{
            last=intervals[i][1];
        }
    }
    return ans;
}
int main(){
    // Output: 1
    vector<vector<int>>intervals={{1,2},{2,3},{3,4},{1,3}};
    // Output: 2
    vector<vector<int>>intervals2={{1,2},{1,2},{1,2}};
    // Output: 0
    vector<vector<int>>intervals3={{1,2},{2,3}};
    cout<<eraseOverlapIntervals(intervals)<<endl;
    cout<<eraseOverlapIntervals(intervals2)<<endl;
    cout<<eraseOverlapIntervals(intervals3);
    return 0;
}