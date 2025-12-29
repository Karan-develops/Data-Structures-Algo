// LC - 756 - Medium - Pyramid Transition Matrix
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class BackTracking{
    unordered_map<string,bool>dp;
    bool solve(unordered_map<string,vector<char>>&mp,string curr,string above,int i){
        if(curr.length()==1){
            return true;
        }

        string key=curr+"_"+to_string(i)+"_"+above;

        if(dp.count(key)) return dp[key];

        if(i==curr.length()-1){
            return dp[key]=solve(mp,above,"",0);
        }

        string pair=curr.substr(i,2);
        if(mp.find(pair)==mp.end()){
            return dp[key]=false;
        }

        for(char &ch:mp[pair]){
            above.push_back(ch);

            if(solve(mp,curr,above,i+1)==true){
                return dp[key]=true;
            }

            above.pop_back();
        }

        return dp[key]=false;
    }
    public:
    bool pyramidTransition(string bottom,vector<string>&allowed){
        unordered_map<string,vector<char>>mp;
        dp.clear();

        for(auto &pattern:allowed){
            mp[pattern.substr(0,2)].push_back(pattern[2]);
        }

        return solve(mp,bottom,"",0);
    }
};
int main(){
    // Output: true
    string bottom="BCD";
    vector<string>allowed={"BCC","CDE","CEA","FFF"};
    // Output: false
    string bottom2="AAAA";
    vector<string>allowed2={"AAB","AAC","BCD","BBE","DEF"};

    BackTracking sol;
    cout<<sol.pyramidTransition(bottom,allowed)<<endl;
    cout<<sol.pyramidTransition(bottom2,allowed2);
    return 0;
}