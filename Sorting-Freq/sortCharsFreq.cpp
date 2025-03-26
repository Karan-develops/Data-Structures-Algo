// LC - 451 - Medium - Sort Characters By Frequency
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
string frequencySort(string s){
    unordered_map<char,int>mp;
    for(auto &ch:s) mp[ch]++;

    vector<pair<char,int>>temp;
    for(auto it:mp) temp.push_back({it.first,it.second});

    auto lambda=[&](pair<char,int>&p1,pair<char,int>&p2){
        return p1.second>p2.second;
    };

    sort(begin(temp),end(temp),lambda);

    string ans="";
    int i=0,n=temp.size();
    for(int i=0;i<n;i++){
        while(temp[i].second--){
            ans.push_back(temp[i].first);
        }
    }
    return ans;
}
int main(){
    // Output: "eert"
    string s="tree";
    // Output: "aaaccc"
    string s2="cccaaa";
    // Output: "bbAa"
    string s3="Aabb";
    cout<<frequencySort(s)<<endl;
    cout<<frequencySort(s2)<<endl;
    cout<<frequencySort(s3);
    return 0;
}