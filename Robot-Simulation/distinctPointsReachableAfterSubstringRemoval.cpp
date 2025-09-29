// LC - 3694 - Medium - Distinct Points Reachable After Substring Removal
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Grid{
    pair<int,int> getMove(char &ch){
        if(ch=='U') return {0,1};
        if(ch=='D') return {0,-1};
        if(ch=='L') return {-1,0};
        return {1,0};
    }
    public:
    int distinctPoints(string s,int k){
        int n=s.length();

        vector<pair<int,int>>pref(n+1,{0,0});
        vector<pair<int,int>>suff(n+2,{0,0});

        for(int i=1;i<=n;i++){
            auto nextMove=getMove(s[i-1]);
            pref[i]={pref[i-1].first+nextMove.first,pref[i-1].second+nextMove.second};
        }

        for(int i=n;i>=1;i--){
            auto nextMove=getMove(s[i-1]);
            suff[i]={suff[i+1].first+nextMove.first,suff[i+1].second+nextMove.second};
        }

        set<pair<int,int>>st;

        for(int i=0;i+k<=n;i++){
            auto left=pref[i];
            auto right=suff[i+k+1];

            st.insert({left.first+right.first,left.second+right.second});
        }

        return (int)st.size();
    }
};
int main(){
    // Output: 2
    string s="LUL";
    int k=1;
    // Output: 1
    string s2="UDLR";
    int k2=4;
    // Output: 1
    string s3="UU";
    int k3=1;

    Grid sol;
    cout<<sol.distinctPoints(s,k)<<endl;
    cout<<sol.distinctPoints(s2,k2)<<endl;
    cout<<sol.distinctPoints(s3,k3);
    return 0;
}