#include<iostream>
#include<queue>
using namespace std;
int main(){
    // creation
    queue<int>q;
    // insertion
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    // front element
    cout<<q.front()<<endl;
    // removal
    q.pop();
    cout<<q.front()<<endl;
    // empty or not
    cout<<q.empty()<<endl;
    q.push(10);
    // size
    cout<<q.size()<<endl;
    // printing
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<q.empty();
    return 0;
}