// GFG - Design MinMax Queue
// 2 Approaches
#include<iostream>
#include<queue>
using namespace std;
// Approach 1 - Using Queue O(n)
class Design{
    queue<int>q;
    public:
    void enqueue(int x){
        q.push(x);
    }
    void dequeue(){
        q.pop();
    }
    int getFront(){
        return q.front();
    }
    int getMin(){
        int n=q.size();
        int minE=INT_MAX;
        
        for(int i=0;i<n;i++){
            minE=min(minE,q.front());
            q.push(q.front());
            q.pop();
        }
        return minE;
    }
    int getMax(){
        int n=q.size();
        int maxE=INT_MIN;
        
        for(int i=0;i<n;i++){
            maxE=max(maxE,q.front());
            q.push(q.front());
            q.pop();
        }
        return maxE;
    }
};
// Approach 2 - Using Deque O(1)
class Deque{
    queue<int>q;
    deque<int>minDq;
    deque<int>maxDq;
    public:
    void enqueue(int x){
        q.push(x);
        
        while(!minDq.empty() && minDq.back()>x){
            minDq.pop_back();
        }
        minDq.push_back(x);
        
        while(!maxDq.empty() && maxDq.back()<x){
            maxDq.pop_back();
        }
        maxDq.push_back(x);
    }
    void dequeue(){
        int val=q.front();
        q.pop();

        if(!minDq.empty() && val==minDq.front()){
            minDq.pop_front();
        }
        if (!maxDq.empty() && val==maxDq.front()){
            maxDq.pop_front();
        }
    }
    int getFront(){
        return q.front();
    }
    int getMin(){
        return minDq.front();
    }
    int getMax(){
        return maxDq.front();
    }
};