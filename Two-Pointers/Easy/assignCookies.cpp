// LC - 455 - Easy - Assign Cookies
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findContentChildren(vector<int>&g,vector<int>&s){
    sort(begin(g),end(g));
    sort(begin(s),end(s));

    int ans=0;
    int i=0,j=0;
    int m=g.size(),n=s.size();
    while(i<m && j<n){
        if(g[i]<=s[j]){
            ans++;
            i++,j++;
        }
        else j++;
    }
    return ans;
}
int main(){
    // Output: 1
    vector<int>g={1,2,3},s={1,1};
    // Output: 2
    vector<int>g2={1,2},s2={1,2,3};
    cout<<findContentChildren(g,s)<<endl;
    cout<<findContentChildren(g2,s2);
    return 0;
}