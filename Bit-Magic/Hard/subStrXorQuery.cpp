// LC - 2564 - Medium - Substring XOR Queries
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    typedef long long ll;
    typedef pair<int,int>P;
    vector<vector<int>> substringXorQueries(string s,vector<vector<int>>&queries){
        int n=s.length();

        vector<vector<int>>ans;
        unordered_map<ll,P>mp;

        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(!mp.count(0)) mp[0]={i,i};
                continue;
            }

            ll bit=0;
            for(int j=i;j<min(i+33,n);j++){
                bit=(bit<<1)+(s[j]-'0');
                if(!mp.count(bit)) mp[bit]={i,j};
            }
        }

        for(auto &vec:queries){
            ll num=vec[0]^vec[1];

            if(mp.count(num)) ans.push_back({mp[num].first,mp[num].second});
            else ans.push_back({-1,-1});
        }
        return ans;
    }
};
int main(){
    // Output: [[0,2],[2,3]]
    string s="101101";
    vector<vector<int>>queries={{0,5},{1,2}};
    // Output: [[-1,-1]]
    string s2="0101";
    vector<vector<int>>queries2={{12,8}};
    // Output: [[0,0]]
    string s3="1";
    vector<vector<int>>queries3={{4,5}};
    return 0;
}