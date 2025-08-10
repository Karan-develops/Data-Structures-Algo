// LC - 808 - Medium - Soup Servings
#include<iostream>
#include<vector>
using namespace std;
class DP{
    vector<vector<double>>dp;
    vector<pair<int,int>>serves{{100,0},{75,25},{50,50},{25,75}};
    double solve(double A,double B){
        if(A<=0 && B<=0) return 0.5;
        
        if(A<=0) return 1.0;
        if(B<=0) return 0.0;
        
        if(dp[A][B]!=-1.0) return dp[A][B];
        
        double probability=0.0;
        
        for(auto &p:serves){
            double A_serve=p.first;
            double B_serve=p.second;
            
            probability+=0.25*solve(A-A_serve,B-B_serve);
        }
        return dp[A][B]=probability;
    }
    public:
    double soupServings(int n){
        if(n>=5000) return 1.0;
        
        dp.resize(n+1,vector<double>(n+1,-1.0));

        return solve(n,n);
    }
};
int main(){
    // Output: 0.62500
    int n=50;
    // Output: 0.71875
    int n2=100;

    DP sol;
    cout<<sol.soupServings(n)<<endl;
    cout<<sol.soupServings(n2);
    return 0;
}