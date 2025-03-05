#include<iostream>
#include<queue>
using namespace std;
void reverseQ(queue<int>&q,int k){
    if(q.empty() || !k) return;
    int temp=q.front();
    q.pop();
    reverseQ(q,k-1);
    q.push(temp);
}
void kReverse(queue<int>&q,int k){
    reverseQ(q,k);
    int n=q.size()-k;
    while(n--){
        int temp=q.front();
        q.pop();
        q.push(temp);
    }
}
int main(){
    int k=3;
    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);
    kReverse(q,k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}