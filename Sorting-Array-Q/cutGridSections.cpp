// LC - 3394 - Medium - Check if Grid can be Cut into Sections
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>&intervals){
    sort(begin(intervals),end(intervals));

    int n=intervals.size();
    vector<vector<int>>ans;
    ans.push_back(intervals[0]);

    for(int i=1;i<n;i++){
        // Overlapping
        if(intervals[i][0]<ans.back()[1]){
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        } else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
bool checkValidCuts(int n,vector<vector<int>>&rectangles){
    vector<vector<int>>hori;
    vector<vector<int>>verti;

    for(auto &vec:rectangles){
        int x1=vec[0];
        int y1=vec[1];
        int x2=vec[2];
        int y2=vec[3];

        hori.push_back({x1,x2});
        verti.push_back({y1,y2});
    }
    vector<vector<int>>ans1=merge(hori);
    if(ans1.size()>=3) return true;

    vector<vector<int>>ans2=merge(verti);
    return ans2.size()>=3;
}
int main(){
    // Output: true
    int n=5;
    vector<vector<int>>rectangles={{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
    // Output: true
    int n2=4;
    vector<vector<int>>rectangles2={{0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}};
    cout<<checkValidCuts(n,rectangles)<<endl;
    cout<<checkValidCuts(n2,rectangles2);
    return 0;
}