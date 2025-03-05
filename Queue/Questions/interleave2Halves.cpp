// interleaving example
// 1 2 3 4 5 6 7 8 => 1 5 2 6 3 7 4 8
#include<iostream>
#include<queue>
using namespace std;
void interleaveQ(queue<int>&mainQ,queue<int>&helperQ){
    bool flag=true;
    while(!helperQ.empty()){
        if(flag){
            mainQ.push(helperQ.front());
            helperQ.pop();
        } else{
            mainQ.push(mainQ.front());
            mainQ.pop();
        }
        flag=!flag;
    }
    if(mainQ.size() & 1){
        mainQ.push(mainQ.front());
        mainQ.pop();
    }
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    queue<int>helperQ;
    int size=q.size();
    while(size/2!=q.size()){
        helperQ.push(q.front());
        q.pop();
    }
    interleaveQ(q,helperQ);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}