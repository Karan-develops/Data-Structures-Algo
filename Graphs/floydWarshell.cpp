// Bellman-Ford and Dijkstra find the shortest path from a single source.
// Floyd-Warshall finds the shortest paths between all pairs of nodes.
#include<iostream>
#include<vector>
#define INF INT_MAX
using namespace std;
void floydWarshall(vector<vector<int>>&graph,int V){
    vector<vector<int>>dist=graph;
    for(int via=0;via<V;via++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][via]!=INF && dist[via][j]!=INF){
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
    }
    // Check for negative weight cycles
    for(int i=0;i<V;i++){
        if(dist[i][i]<0){
            cout<<"Negative Cycle!"<<endl;
            return;
        }
    }
    cout<<"All-Pairs Shortest Paths:"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF) cout<<"INF ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int V=4;
    vector<vector<int>>graph={{0,3,INF,7},{8,0,2,INF},{5,INF,0,1},{2,INF,INF,0}};
    floydWarshall(graph,V);
    return 0;
}