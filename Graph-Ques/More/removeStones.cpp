// LC - 947 - Medium - Most Stones Removed with Same Row or Column
#include<iostream>
#include<vector>
using namespace std;
class DFS{
    int n;
    void dfs(vector<vector<int>>&stones,vector<bool>&visited,int idx){
        visited[idx]=true;

        for(int i=0;i<n;i++){
            int r=stones[idx][0];
            int c=stones[idx][1];

            if(!visited[i] && (stones[i][0]==r || stones[i][1]==c)){
                dfs(stones,visited,i);
            }
        }
    }
    public:
    int removeStones(vector<vector<int>>&stones){
        int count=0;
        n=stones.size();
        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(stones,visited,i);
                count++;
            }
        }
        return n-count;
    }
};
class DSU{
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x!=parent_y){
            if(rank[parent_x]<rank[parent_y]) parent[parent_x]=parent_y;
            else if(rank[parent_x]>rank[parent_y]) parent[parent_y]=parent_x;
            else{
                parent[parent_x]=parent_y;
                rank[parent_y]++;
            }
        }
    }
    public:
    int removeStones(vector<vector<int>>&stones){
        int n=stones.size();
        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j);
                }
            }
        }
        int groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) groups++;
        }
        return n-groups;
    }
};
int main(){
    // OP - 5
    vector<vector<int>>stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    // OP - 3
    vector<vector<int>>stones2={{0,0},{0,2},{1,1},{2,0},{2,2}};
    DSU obj;
    cout<<obj.removeStones(stones)<<endl;
    cout<<obj.removeStones(stones2);
    return 0;
}