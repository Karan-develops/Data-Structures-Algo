// LC - 3695 - HARD - Maximize Alternating Sum Using Swaps
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Graph{
    int n;
    long long solve(vector<vector<int>>&adj,vector<int>&nums){
        vector<bool>visited(n,false);
        long long ans=0;

        for(int i=0;i<n;i++){
            if(visited[i]) continue;

            vector<int>idx;
            queue<int>q;

            q.push(i);
            visited[i]=true;

            while(!q.empty()){
                int u=q.front();
                q.pop();

                idx.push_back(u);

                for(int &ngbr:adj[u]){
                    if(!visited[ngbr]){
                        visited[ngbr]=true;
                        q.push(ngbr);
                    }
                }
            }

            vector<int>temp;
            for(int &i:idx) temp.push_back(nums[i]);
            sort(begin(temp),end(temp),greater<int>());

            sort(begin(idx),end(idx));

            int l=0,r=temp.size()-1;
            for(int &i:idx){
                if(i%2==0){
                    ans+=temp[l++];
                } else{
                    ans-=temp[r--];
                }
            }
        }
        return ans;
    }
    public:
    long long maxAlternatingSum(vector<int>&nums,vector<vector<int>>&swaps){
        n=nums.size();
        vector<vector<int>>adj(n);

        for(auto &vec:swaps){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return solve(adj,nums);
    }
};
int main(){
    // Output: 4
    vector<int>nums={1,2,3};
    vector<vector<int>>swaps={{0,2},{1,2}};
    // Output: 2
    vector<int>nums2={1,2,3};
    vector<vector<int>>swaps2={{1,2}};
    // Output: -2999999997
    vector<int>nums3={1,1000000000,1,1000000000,1,1000000000};
    vector<vector<int>>swaps3={};

    Graph sol;
    cout<<sol.maxAlternatingSum(nums,swaps)<<endl;
    cout<<sol.maxAlternatingSum(nums2,swaps2)<<endl;
    cout<<sol.maxAlternatingSum(nums3,swaps3);
    return 0;
}