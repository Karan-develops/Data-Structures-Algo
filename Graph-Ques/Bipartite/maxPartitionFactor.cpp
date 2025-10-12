// LC - 3710 - HARD - Maximum Partition Factor
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Bipartite{
    typedef long long ll;
    ll manhattanDist(vector<int>&v1,vector<int>&v2){
        return (ll)abs(v1[0]-v2[0])+(ll)abs(v1[1]-v2[1]);
    }
    bool isPossible(vector<vector<int>>&points,ll mid){
        int n=points.size();

        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(manhattanDist(points[i],points[j])<mid){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>colors(n,-1);

        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                queue<int>q;

                q.push(i);
                colors[i]=0;

                while(!q.empty()){
                    int u=q.front();
                    q.pop();

                    for(int v:adj[u]){
                        if(colors[v]==-1){
                            colors[v]=colors[u]^1;
                            q.push(v);
                        } else if(colors[u]==colors[v]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    public:
    int maxPartitionFactor(vector<vector<int>>&points){
        int n=points.size();
        if(n<=2) return 0;

        ll l=0;
        ll r=4000000000;
        int ans=0;

        while(l<=r){
            ll mid=l+(r-l)/2;

            if(isPossible(points,mid)){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return (int)ans;
    }
};
int main(){
    // Output: 4
    vector<vector<int>>points={{0,0},{0,2},{2,0},{2,2}};
    // Output: 11
    vector<vector<int>>points2={{0,0},{0,1},{10,0}};

    Bipartite sol;
    cout<<sol.maxPartitionFactor(points)<<endl;
    cout<<sol.maxPartitionFactor(points2);
    return 0;
}