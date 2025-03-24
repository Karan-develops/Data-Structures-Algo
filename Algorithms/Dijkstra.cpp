// Using min-heap(priority queue)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dijkstra(vector<vector<pair<int,int>>>&adj,int V,int src){
    vector<int>ans(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    ans[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int currD=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto &vec:adj[node]){
            int ngbr=vec.first;
            int w=vec.second;
            if(currD+w<ans[ngbr]){
                ans[ngbr]=currD+w;
                pq.push({currD+w,ngbr});
            }
        }
    }
    cout<<"Shortest distances from source "<<src<<endl;
    for(int i=0;i<V;i++){
        cout<<"To "<<i<<"->"<<(ans[i]==INT_MAX?-1:ans[i])<<endl;
    }
}
int main(){
    int V=5;
    vector<vector<pair<int,int>>>adj(V);
    adj[0]={{1,2},{2,4}};
    adj[1]={{2,1},{3,7}};
    adj[2]={{4,3}};
    adj[3]={{4,2}};
    adj[4]={};
    int src=0;
    dijkstra(adj,V,src);
    return 0;
}
/*
// Using Set - erase unwanted entries
#include<iostream>
#include<vector>
#include<set>
using namespace std;
void dijkstra(vector<vector<pair<int,int>>>&adj,int src,int V){
    vector<int>ans(V,INT_MAX);
    set<pair<int,int>>st;
    ans[src]=0;
    st.insert({0,src});
    while(!st.empty()){
        auto &it=*st.begin();
        int d=it.first;
        int node=it.second;
        st.erase(it);
        for(auto &vec:adj[node]){
            int ngbr=vec.first;
            int w=vec.second;
            if(d+w<ans[ngbr]){
                if(ans[ngbr]!=INT_MAX){
                    st.erase({ans[ngbr],ngbr});
                }
                ans[ngbr]=d+w;
                st.insert({ans[ngbr],ngbr});
            }
        }
    }
    cout<<"Shortest distances from source "<<src<<endl;
    for(int i=0;i<V;i++){
        cout<<"To "<<i<<"->"<<(ans[i]==INT_MAX?-1:ans[i])<<endl;
    }
}
int main(){
    int V=5;
    vector<vector<pair<int,int>>>adj(V);
    adj[0]={{1,2},{2,4}};
    adj[1]={{2,1},{3,7}};
    adj[2]={{4,3}};
    adj[3]={{4,2}};
    adj[4]={};
    int src=0;
    dijkstra(adj,src,V);
    return 0;
}

-----------------------------------------------------------
(2D)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,pair<int,int>>P;
vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
int dijkstra(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();

    auto isSafe=[&](int x,int y){
        return x>=0 && y>=0 && x<m && y<n;
    };

    priority_queue<P,vector<P>,greater<P>>pq;
    vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
    ans[0][0]=grid[0][0];
    pq.push({grid[0][0],{0,0}});
    while(!pq.empty()){
        int d=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();

        if(i==m-1 && j==n-1) return ans[m-1][n-1];

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            if(isSafe(i_,j_)){
                int newCost=d+grid[i_][j_];
                if(newCost<ans[i_][j_]){
                    ans[i_][j_]=newCost;
                    pq.push({newCost,{i_,j_}});
                }
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
    cout<<"Min Cost:"<<dijkstra(grid);
    return 0;
}
*/