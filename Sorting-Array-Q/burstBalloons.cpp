// LC - 452 - Medium - Minimum Number of Arrows to Burst Balloons
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMinArrowShots(vector<vector<int>>& points) {
    sort(begin(points),end(points),[](vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    });
    int ans=1;
    int last=points[0][1];
    for(int i=1;i<points.size();i++){
        if(last<points[i][0]){
            ans++;
            last=points[i][1];
        }
    }
    return ans;
}
int main(){
    // Output: 2
    vector<vector<int>>points={{10,16},{2,8},{1,6},{7,12}};
    // Output: 4
    vector<vector<int>>points2={{1,2},{3,4},{5,6},{7,8}};
    // Output: 2
    vector<vector<int>>points3={{1,2},{2,3},{3,4},{4,5}};
    cout<<findMinArrowShots(points)<<endl;
    cout<<findMinArrowShots(points2)<<endl;
    cout<<findMinArrowShots(points3);
    return 0;
}