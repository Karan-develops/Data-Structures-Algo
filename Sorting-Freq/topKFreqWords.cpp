// LC - 692 - Medium - Top K Frequent Words
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<string> topKFrequent(vector<string>&words,int k){
    unordered_map<string,int>mp;
    for(auto &s:words) mp[s]++;

    vector<pair<string,int>>temp;
    for(auto it:mp) temp.push_back({it.first,it.second});

    auto lambda=[&](pair<string,int>&p1,pair<string,int>&p2){
        if(p1.second==p2.second) return p1.first<p2.first;
        return p1.second>p2.second;
    };

    sort(begin(temp),end(temp),lambda);

    vector<string>ans;
    for(int i=0;i<k;i++){
        ans.push_back(temp[i].first);
    }
    return ans;
}
int main(){
    // Output: ["i","love"]
    vector<string>words={"i","love","leetcode","i","love","coding"};
    int k=2;
    // Output: ["the","is","sunny","day"]
    vector<string>words2={"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k2=4;
    vector<string>ans=topKFrequent(words,k);
    vector<string>ans2=topKFrequent(words2,k2);
    for(auto &i:ans) cout<<i<<" ";
    cout<<endl;
    for(auto &i:ans2) cout<<i<<" ";
    return 0;
}