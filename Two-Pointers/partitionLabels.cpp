// LC - 763 - Medium - Partition Labels
#include<iostream>
#include<vector>
using namespace std;
vector<int> partitionLabels(string s){
    int n=s.length();
    vector<int>ans;

    vector<int>mp(26,-1);
    for(int i=0;i<n;i++) mp[s[i]-'a']=i;

    int i=0,start=0,end=0;
    while(i<n){
        end=max(end,mp[s[i]-'a']);
        if(i==end){
            ans.push_back(end-start+1);
            start=end+1;
        }
        i++;
    }
    return ans;
}
int main(){
    // Output: [9,7,8]
    string s="ababcbacadefegdehijhklij";
    // Output: [10]
    string s2="eccbbbbdec";
    vector<int>ans=partitionLabels(s);
    vector<int>ans2=partitionLabels(s2);
    for(int &i:ans) cout<<i<<" ";
    cout<<endl;
    for(int &i:ans2) cout<<i<<" ";
    return 0;
}