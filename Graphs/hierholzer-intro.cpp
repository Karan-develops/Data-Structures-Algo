// Pick any vertex with edges.
// Follow edges, storing visited edges in a stack.
// Backtrack when no edges remain.
#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
using namespace std;
class EulerPath{
    int V;
    vector<vector<int>>adj;
    public:
    EulerPath(int V){
        this->V=V;
        adj.resize(V);
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void findEulerPath(){
        stack<int>st;
        vector<int>path;
        vector<vector<int>>temp=adj;
        int startNode=adj[0][0];
        for(int i=0;i<V;i++){
            if(temp[i].size()%2!=0){
                startNode=i;
                break;
            }
        }
        st.push(startNode);
        while(!st.empty()){
            int curr=st.top();
            if(!temp[curr].empty()){
                int ngbr=temp[curr].back();
                temp[curr].pop_back();
                // Remove the reverse edge from v (since it is an undirected graph).
                temp[ngbr].erase(find(temp[ngbr].begin(),temp[ngbr].end(),curr));
                st.push(ngbr);
            } else{
                path.push_back(curr);
                st.pop();
            }
        }
        cout<<"Eulerian Path/Circuit: ";
        for(int v:path) cout<<v<<" ";
        cout<<endl;
    }
};
int main(){
    EulerPath g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.findEulerPath();
    return 0;
}