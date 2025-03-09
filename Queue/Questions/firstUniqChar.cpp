#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int firstUniqChar(string s) {
    int n=s.length();
    unordered_map<char,int>freq;
    queue<int>q;
    for(int i=0;i<n;i++){
        freq[s[i]]++;
        q.push(i);
        while(!q.empty() && freq[s[q.front()]]>1){
            q.pop();
        }
    }
    return q.empty()?-1:q.front();
}
int main(){
    // OP- 0
    string s1="leetcode";
    // OP- 2
    string s2="loveleetcode";
    cout<<firstUniqChar(s1)<<endl;
    cout<<firstUniqChar(s2);
    return 0;
}