#include<iostream>
#include<queue>
using namespace std;
void reverse(queue<int>&q){
    if(q.empty()) return;
    int temp=q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    reverse(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
// or put elements in stack and then push in queue to reverse.