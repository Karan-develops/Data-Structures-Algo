// LC - 1834 - Medium - Single-Threaded CPU
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<array>
using namespace std;
class Heap{
    typedef pair<int,int>P;
    public:
    vector<int> getOrder(vector<vector<int>>&tasks){
        int n=tasks.size();

        vector<array<int,3>>sortedTasks;

        for(int i=0;i<n;i++){
            int start_time=tasks[i][0];
            int processing_time=tasks[i][1];
            
            sortedTasks.push_back({start_time,processing_time,i});
        }

        sort(begin(sortedTasks),end(sortedTasks));

        long long currTime=0;
        int idx=0;

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<int>ans;

        while(idx<n || !pq.empty()){
            if(pq.empty() && currTime<sortedTasks[idx][0]){
                currTime=sortedTasks[idx][0];
            }

            while(idx<n && sortedTasks[idx][0]<=currTime){
                pq.push({sortedTasks[idx][1],sortedTasks[idx][2]});
                idx++;
            }

            auto topTask=pq.top();
            pq.pop();

            currTime+=topTask.first;
            ans.push_back(topTask.second);
        }
        return ans;
    }
};
int main(){
    // Output: [0,2,3,1]
    vector<vector<int>>tasks={{1,2},{2,4},{3,2},{4,1}};
    // Output: [4,3,2,0,1]
    vector<vector<int>>tasks2={{7,10},{7,12},{7,5},{7,4},{7,2}};

    Heap sol;
    vector<int>ans=sol.getOrder(tasks);

    for(int &i:ans) cout<<i<<" ";
    return 0;
}