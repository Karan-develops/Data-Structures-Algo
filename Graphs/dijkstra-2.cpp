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