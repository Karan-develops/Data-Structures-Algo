// LC - 1306 - Medium - Jump Game III
// 2 Approaches
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Approach 1 - DFS
class DFS{
    int n;
    bool solve(vector<int>&arr,int start){
        if(start<0 || start>=n || arr[start]<0){
            return false;
        }

        if(arr[start]==0) return true;

        // Using Actual Array as visited
        arr[start]=-arr[start];

        int left=solve(arr,start-arr[start]);
        int right=solve(arr,start+arr[start]);

        return left || right;
    }
    public:
    bool canReach(vector<int>&arr,int start){
        n=(int)arr.size();

        return solve(arr,start);
    }
};
// Approach 2 - BFS
class BFS{
    int n;
    bool bfs(vector<int>&arr,int start){
        queue<int>q;
        q.push(start);

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            if(arr[curr]==0) return true;

            int left=curr-arr[curr];
            int right=curr+arr[curr];

            if(left>=0 && arr[curr]>0){
                q.push(left);
            }
            if(right<n && arr[curr]>0){
                q.push(right);
            }

            arr[curr]=-arr[curr];
        }
        return false;
    }
    public:
    bool canReach(vector<int>&arr,int start){
        n=(int)arr.size();

        return bfs(arr,start);
    }
};
int main(){
    // Output: true
    vector<int>arr={4,2,3,0,3,1,2};
    int start=5;
    // Output: true 
    vector<int>arr2={4,2,3,0,3,1,2};
    int start2=0;
    // Output: false
    vector<int>arr3={3,0,2,1,2};
    int start3=2;

    DFS sol;
    cout<<sol.canReach(arr,start)<<endl;
    cout<<sol.canReach(arr2,start2)<<endl;
    cout<<sol.canReach(arr3,start3);
    return 0;
}