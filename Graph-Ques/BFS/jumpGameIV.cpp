// LC - 1345 - HARD - Jump Game IV
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class BFS{
    int n;
    int bfs(vector<int>&arr){
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        queue<int>q;
        vector<bool>visited(n,false);

        q.push(0);
        visited[0]=true;
        int steps=0;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int curr=q.front();
                q.pop();

                if(curr==n-1) return steps;

                int left=curr-1;
                int right=curr+1;

                if(left>=0 && !visited[left]){
                    visited[left]=true;
                    q.push(left);
                }
                if(right<n && !visited[right]){
                    visited[right]=true;
                    q.push(right);
                }

                for(const int &ngbr:mp[arr[curr]]){
                    if(!visited[ngbr]){
                        visited[ngbr]=true;
                        q.push(ngbr);
                    }
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
    public:
    int minJumps(vector<int>&arr){
        n=arr.size();
        if(n==1) return 0;

        return bfs(arr);
    }
};
int main(){
    // Output: 3
    vector<int>arr={100,-23,-23,404,100,23,23,23,3,404};
    // Output: 0
    vector<int>arr2={7};
    // Output: 1
    vector<int>arr3={7,6,9,6,9,6,9,7};

    BFS sol;
    cout<<sol.minJumps(arr)<<endl;
    cout<<sol.minJumps(arr2)<<endl;
    cout<<sol.minJumps(arr3);
    return 0;
}