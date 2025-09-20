// LC - 3408 - Medium - Design Task Manager
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Design{
public:
    // tasks sorted by priority, then taskId
    priority_queue<pair<int,int>>maxHeap;
    // taskId -> current priority
    unordered_map<int,int>taskPriorityMap;
    // taskId -> userId
    unordered_map<int,int>taskOwnerMap;
    Design(vector<vector<int>>&tasks){
        for(const auto &task:tasks){
            add(task[0],task[1],task[2]);
        }
    }
    
    void add(int userId,int taskId,int priority){
        maxHeap.push({priority,taskId});
        taskPriorityMap[taskId]=priority;
        taskOwnerMap[taskId]=userId;
    }
    
    void edit(int taskId,int newPriority){
        maxHeap.push({newPriority,taskId});
        taskPriorityMap[taskId]=newPriority;
    }
    
    void rmv(int taskId){
        taskPriorityMap[taskId]=-1;
    }
    
    int execTop(){
        while(!maxHeap.empty()){
            auto[priority,taskId]=maxHeap.top();
            maxHeap.pop();

            if(priority==taskPriorityMap[taskId]){
                taskPriorityMap[taskId]=-1; // mark as executed
                return taskOwnerMap[taskId];
            }
        }

        return -1;
    }
};