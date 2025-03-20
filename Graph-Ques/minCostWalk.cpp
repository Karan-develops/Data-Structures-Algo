// LC - 3108 - HARD - Minimum Cost Walk in Weighted 
/* TIPS:
1) Jitna zyada and(&) value choti hoti rhegi ya same rhegi, increase mhi hogi
2) -1 se & krne se same value aati h
Ex- (x & -1) => x
*/
#include<iostream>
#include<vector>
using namespace std;
class DSU{
    vector<int>parent;
    vector<int>cost;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        parent[y]=x;
    }
    public:
    vector<int> minimumCost(int n,vector<vector<int>>&edges,vector<vector<int>>&query){
        parent.resize(n);
        cost.assign(n,-1);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];

            int parent_u=find(u);
            int parent_v=find(v);

            if(parent_u!=parent_v){
                cost[parent_u]&=cost[parent_v];
                Union(parent_u,parent_v);
            }

            cost[parent_u]&=w;
        }
        
        vector<int>ans;
        for(auto &q:query){
            int start=q[0];
            int end=q[1];

            int p1=find(start);
            int p2=find(end);

            if(start==end) ans.push_back(0);
            else if(p1!=p2) ans.push_back(-1);
            else ans.push_back(cost[p1]);
        }
        return ans;
    }
};
int main(){
    // OP - {1,-1}
    int n=5;
    vector<vector<int>>edges={{0,1,7},{1,3,7},{1,2,1}},query={{0,3},{3,4}};
    // OP - {0}
    int n2=3;
    vector<vector<int>>edges2={{0,2,7},{0,1,15},{1,2,6},{1,2,1}},query2={{1,2}};
    DSU obj;
    vector<int>ans1=obj.minimumCost(n,edges,query);
    vector<int>ans2=obj.minimumCost(n2,edges2,query2);

    for(int &i:ans1) cout<<i<<" ";
    cout<<endl;
    for(int &i:ans2) cout<<i<<" ";
    return 0;
}