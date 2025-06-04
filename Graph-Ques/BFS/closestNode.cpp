// LC - 2359 - Medium - Find Closest Node to Given Two Nodes
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class BFS{
    int n;
    void bfs(vector<int>&edges,vector<int>&dist,int startNode){
        vector<bool>visited(n,false);
        queue<int>q;

        q.push(startNode);
        visited[startNode]=true;
        dist[startNode]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            int ngbr=edges[node];

            if(ngbr!=-1 && !visited[ngbr]){
                visited[ngbr]=true;
                dist[ngbr]=dist[node]+1;
                q.push(ngbr);
            }
        }
    }
    public:
    int closestMeetingNode(vector<int>&edges,int node1,int node2){
        n=edges.size();

        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);

        bfs(edges,dist1,node1);
        bfs(edges,dist2,node2);

        int minDistNode=-1;
        int minDistTillNow=INT_MAX;

        for(int i=0;i<n;i++){
            int maxD=max(dist1[i],dist2[i]);
            
            if(maxD<minDistTillNow){
                minDistTillNow=maxD;
                minDistNode=i;
            }
        }
        return minDistNode;
    }
};
int main(){
    // Output: 2
    vector<int>edges={2,2,3,-1};
    int node1=0,node2=1;
    // Output: 2
    vector<int>edges2={1,2,-1};
    int node3=0,node4=2;

    BFS sol;
    cout<<sol.closestMeetingNode(edges,node1,node2)<<endl;
    cout<<sol.closestMeetingNode(edges2,node3,node4);
    return 0;
}