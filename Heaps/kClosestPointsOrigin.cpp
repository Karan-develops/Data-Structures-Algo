// GFG - K Closest Points to Origin
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>>&points,int k){
    int n=points.size();
    
    priority_queue<pair<int,int>>pq;
    
    for(int i=0;i<n;i++){
        int x=points[i][0];
        int y=points[i][1];
        
        // Since we are only comparing, We don't need to apply √
        int dist=(x*x+y*y);
        
        pq.push({dist,i});
        
        if(pq.size()>k) pq.pop();
    }
    
    vector<vector<int>>ans;
    
    while(!pq.empty()){
        ans.push_back(points[pq.top().second]);
        pq.pop();
    }
    
    return ans;
}
int main(){
    // Output: [[-2, 2], [0, 1]]
    int k=2;
    vector<vector<int>>points={{1,3},{-2,2},{5,8},{0,1}};
    // Output: [[0, 0]]
    int k2=1;
    vector<vector<int>>points2={{2, 4},{-1,-1},{0,0}};
    return 0;
}