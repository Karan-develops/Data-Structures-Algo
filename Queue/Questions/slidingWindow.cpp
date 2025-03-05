// **VI** Pattern
// return vector of elements that contains the first -ve number of every sliding window of size k.
// pattern -> read comments in code.
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void slidingWindow(vector<int>&v,int k){
    int size=v.size();
    queue<int>q;
    // process first window
    for(int i=0;i<k;i++){
        if(v[i]<0) q.push(i);
    }
    // remaining window process karo
    for(int i=k;i<size;i++){
        // purani window ka answer nikalo
        if(!q.empty()) cout<<v[q.front()]<<" ";
        else cout<<0<<" ";
        // out of window elements remove krdo
        while(!q.empty() && i-q.front()>=k){
            q.pop();
        }
        // check current element for insertion
        if(v[i]<0) q.push(i);
    }
    // last window toh process hi nhi hui
    // answer print karo last window ka
    if(!q.empty()) cout<<v[q.front()];
    else cout<<0<<" ";
}
int main(){
    vector<int>v{12,-1,-7,8,-15,30,16,28};
    slidingWindow(v,3);
    return 0;
}