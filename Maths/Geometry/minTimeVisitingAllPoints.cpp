// LC - 1266 - Easy - Minimum Time Visiting All Points
#include<iostream>
#include<vector>
using namespace std;
int minTimeToVisitAllPoints(vector<vector<int>>&points){
    int ans=0;

    for(int i=1;i<points.size();i++){
        int dx=abs(points[i][0]-points[i-1][0]);
        int dy=abs(points[i][1]-points[i-1][1]);
        
        ans+=max(dx,dy);
    }
    return ans;
}
int main(){
    // Output: 7
    vector<vector<int>>points={{1,1},{3,4},{-1,0}};
    // Output: 5
    vector<vector<int>>points2={{3,2},{-2,2}};
    cout<<minTimeToVisitAllPoints(points)<<endl;
    cout<<minTimeToVisitAllPoints(points2);
    return 0;
}