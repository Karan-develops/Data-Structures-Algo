// LC - 3170 - Medium - Lexicographically Minimum String After Removing Stars
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>P;
string clearStars(string s) {
    priority_queue<P,vector<P>,greater<P>>pq;

    for(int i=0;i<s.length();i++){
        if(s[i]=='*'){
            int topIdx=-pq.top().second;
            s[topIdx]=-1;
            s[i]=-1;
            pq.pop();
        } else{
            pq.push({s[i]-'a',-i});
        }
    }

    string ans;
    for(int i=0;i<s.length();i++){
        if(s[i]!=-1) ans+=s[i];
    }
    return ans;
}
int main(){
    // Output: "aab"
    string s="aaba*";
    // Output: "abc"
    string s2="abc";
    cout<<clearStars(s)<<endl;
    cout<<clearStars(s2);
    return 0;
}