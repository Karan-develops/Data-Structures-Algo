// LC - 621 - Medium - Task Scheduler
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int leastInterval(vector<char>&tasks,int n){
    int ans=0;
    vector<int>v(26,0);

    for(char &ch:tasks) v[ch-'A']++;

    priority_queue<int>pq;
    for(int i=0;i<26;i++){
        if(v[i]>0) pq.push(v[i]);
    }

    while(!pq.empty()){
        vector<int>temp;
        
        // Doing tasks
        for(int i=0;i<n+1;i++){
            if(!pq.empty()){
                int freq=pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }

        for(int &i:temp){
            if(i>0) pq.push(i);
        }

        // Last set of tasks
        if(pq.empty()) ans+=temp.size();
        // Did (n+1) tasks
        else ans+=(n+1);
    }
    return ans;
}
int main(){
    // Output: 8
    vector<char>tasks={'A','A','A','B','B','B'};
    int n=2;
    // Output: 6
    vector<char>tasks2={'A','C','A','B','D','B'};
    int n2=1;
    // Output: 10
    vector<char>tasks3={'A','A','A', 'B','B','B'};
    int n3=3;
    cout<<leastInterval(tasks,n)<<endl;
    cout<<leastInterval(tasks2,n2)<<endl;
    cout<<leastInterval(tasks3,n3);
    return 0;
}