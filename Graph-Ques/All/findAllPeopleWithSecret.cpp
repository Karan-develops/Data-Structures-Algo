// LC - 2092 - HARD - Find All People With Secret
// 4 Approaches
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;
// Approach 1 - Basic
class Graph{
    typedef pair<int,int>P;
    public:
    vector<int> findAllPeople(int n,vector<vector<int>>&meetings,int firstPerson){
        map<int,vector<P>>timeMeetings;

        for(auto &vec:meetings){
            int person1=vec[0];
            int person2=vec[1];
            int time=vec[2];

            timeMeetings[time].push_back({person1,person2});
        }

        vector<int>knowsSecret(n,false);
        knowsSecret[0]=true;
        knowsSecret[firstPerson]=true;

        for(auto &it:timeMeetings){
            int time=it.first;
            vector<P> meets=it.second;

            unordered_map<int,vector<int>>adj;
            queue<int>q;
            unordered_set<int>alreadyAdded;

            // Make Graph
            for(auto &[person1,person2]:meets){
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if(knowsSecret[person1] && !alreadyAdded.count(person1)){
                    q.push(person1);
                    alreadyAdded.insert(person1);
                }
                if(knowsSecret[person2] && !alreadyAdded.count(person2)){
                    q.push(person2);
                    alreadyAdded.insert(person2);
                }
            }

            // Now I know who meet who based on increasing time
            // Let's hit the BFS to spread the secret
            while(!q.empty()){
                int person=q.front();
                q.pop();

                for(auto &nextPerson:adj[person]){
                    if(!knowsSecret[nextPerson]){
                        knowsSecret[nextPerson]=true;
                        q.push(nextPerson);
                    }
                }
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(knowsSecret[i]==true){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// Approach 2 - Direct BFS - TLE
class BFS{
    typedef pair<int,int>P;
    public:
    vector<int> findAllPeople(int n,vector<vector<int>>&meetings,int firstPerson){
        unordered_map<int,vector<P>>adj;

        for(auto &vec:meetings){
            int person1=vec[0];
            int person2=vec[1];
            int time=vec[2];

            adj[person1].push_back({person2,time});
            adj[person2].push_back({person1,time});
        }
        // {person,time when person knew the secret}
        queue<P>q;
        q.push({0,0});
        q.push({firstPerson,0});

        vector<int>earlySecretTime(n,INT_MAX);
        earlySecretTime[0]=0;
        earlySecretTime[firstPerson]=0;

        while(!q.empty()){
            int person=q.front().first;
            int time=q.front().second;
            q.pop();

            for(auto &ngbr:adj[person]){
                int nextPerson=ngbr.first;
                int t=ngbr.second;

                if(t>=time && earlySecretTime[nextPerson]>t){
                    earlySecretTime[nextPerson]=t;
                    q.push({nextPerson,t});
                }
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(earlySecretTime[i]!=INT_MAX){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// Approach 3 - DFS
class DFS{
    typedef pair<int,int>P;
    void dfs(unordered_map<int,vector<P>>&adj,vector<int>&earlySecretTime,int person,int time){
        for(auto &ngbr:adj[person]){
            int nextPerson=ngbr.first;
            int t=ngbr.second;

            if(t>=time && earlySecretTime[nextPerson]>t){
                earlySecretTime[nextPerson]=t;
                dfs(adj,earlySecretTime,nextPerson,t);
            }
        }
    }
    public:
    vector<int> findAllPeople(int n,vector<vector<int>>&meetings,int firstPerson){
        unordered_map<int,vector<P>>adj;

        for(auto &vec:meetings){
            int person1=vec[0];
            int person2=vec[1];
            int time=vec[2];

            adj[person1].push_back({person2,time});
            adj[person2].push_back({person1,time});
        }

        vector<int>earlySecretTime(n,INT_MAX);
        earlySecretTime[0]=0;
        earlySecretTime[firstPerson]=0;

        dfs(adj,earlySecretTime,0,0);
        dfs(adj,earlySecretTime,firstPerson,0);

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(earlySecretTime[i]!=INT_MAX){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// Approach 4 - Heap (Dijkstra)
class Dijkstra{
    typedef pair<int,int>P;
    public:
    vector<int> findAllPeople(int n,vector<vector<int>>&meetings,int firstPerson){
        unordered_map<int,vector<P>>adj;

        for(auto &vec:meetings){
            int person1=vec[0];
            int person2=vec[1];
            int time=vec[2];

            adj[person1].push_back({person2,time});
            adj[person2].push_back({person1,time});
        }

        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});

        vector<bool>visited(n,false);

        while(!pq.empty()){
            auto [time,person]=pq.top();
            pq.pop();
            
            if(visited[person]==true){
                continue;
            }
            visited[person]=true;
            
            for(auto &ngbr:adj[person]){
                int nextPerson=ngbr.first;
                int t=ngbr.second;
                
                if(t>=time && !visited[nextPerson]){
                    pq.push({t,nextPerson});
                }
            }
        }
        
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(visited[i]==true){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
int main(){
    // Output: [0,1,2,3,5]
    int n=6,firstPerson=1;
    vector<vector<int>>meetings={{1,2,5},{2,3,8},{1,5,10}};
    // Output: [0,1,3]
    int n2=4,firstPerson2=3;
    vector<vector<int>>meetings2={{3,1,3},{1,2,2},{0,3,3}};
    // Output: [0,1,2,3,4]
    int n3=5,firstPerson3=1;
    vector<vector<int>>meetings3={{3,4,2},{1,2,1},{2,3,1}};
    return 0;
}