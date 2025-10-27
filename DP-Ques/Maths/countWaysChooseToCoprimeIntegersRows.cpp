// LC - 3725 - HARD - Count Ways to Choose Coprime Integers from Rows
#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
class DP{
    typedef long long ll;
    const int MOD=1e9+7;
    public:
    int countCoprime(vector<vector<int>>&mat){
        unordered_map<int,int>dp;

        for(int &i:mat[0]) dp[i]++;

        for(int i=1;i<mat.size();i++){
            unordered_map<int,int>newDp;

            for(auto [g,count]:dp){
                for(int x:mat[i]){
                    int newG=gcd(g,x);
                    newDp[newG]=(newDp[newG]+count)%MOD;
                }
            }

            dp=move(newDp);
        }

        return dp[1]%MOD;
    }
};
int main(){
    // Output: 3
    vector<vector<int>>mat={{1,2},{3,4}};
    // Output: 0
    vector<vector<int>>mat2={{2,2},{2,2}};

    DP sol;
    cout<<sol.countCoprime(mat)<<endl;
    cout<<sol.countCoprime(mat2);
    return 0;
}