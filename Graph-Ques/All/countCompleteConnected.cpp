// LC - 2685 - Medium - Count the Number of Complete Components
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class DFS{
    void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int &e,int &v,int i){
        visited[i]=true;
        v++;
        e+=adj[i].size();

        for(auto &ngbr:adj[i]){
            if(!visited[ngbr]){
                dfs(adj,visited,e,v,ngbr);
            }
        }
    }
    public:
    int countCompleteComponents(int n,vector<vector<int>>&edges){
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=0;
        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }

            int e=0,v=0;
            dfs(adj,visited,e,v,i);

            if(v*(v-1)==e){
                ans++;
            }
        }
        return ans;
    }
};
class BFS{
    int N;
    void bfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int &e,int &v,int i){
        queue<int>q;

        q.push(i);
        visited[i]=true;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            v++;
            e+=adj[node].size();

            for(auto &ngbr:adj[node]){
                if(!visited[ngbr]){
                    q.push(ngbr);
                    visited[ngbr]=true;
                }
            }
        }
    }
    public:
    int countCompleteComponents(int n,vector<vector<int>>&edges){
        N=n;
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }

            int e=0,v=0;
            bfs(adj,visited,e,v,i);

            if(v*(v-1)==e){
                ans++;
            }
        }
        return ans;
    }
};
class DSU{
    vector<int>parent;
    vector<int>size;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x==parent_y) return;

        if(size[parent_x]<size[parent_y]){
            parent[parent_x]=parent_y;
            size[parent_y]+=size[parent_x];
        } else if(size[parent_x]>size[parent_y]){
            parent[parent_y]=parent_x;
            size[parent_x]+=size[parent_y];
        } else{
            parent[parent_x]=parent_y;
            size[parent_y]+=size[parent_x];
        }
    }
    public:
    int countCompleteComponents(int n,vector<vector<int>>&edges){
        parent.resize(n);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            Union(u,v);
        }

        //Count the edges for each root
        unordered_map<int,int>mp;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            int root=find(u);
            // incrementing for edge count
            mp[root]++;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(find(i)==i){
                int v=size[i];
                int e=mp[i];

                if((v*(v-1)/2)==e){
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main(){
    // OP - 3
    int n=6;
    vector<vector<int>>edges={{0,1},{0,2},{1,2},{3,4}};
    // OP - 1
    int n2=6;
    vector<vector<int>>edges2={{0,1},{0,2},{1,2},{3,4},{3,5}};
    DSU obj;
    cout<<obj.countCompleteComponents(n,edges)<<endl;
    cout<<obj.countCompleteComponents(n2,edges2);
    return 0;
}