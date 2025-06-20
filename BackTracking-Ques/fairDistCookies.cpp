// LC - 2305 - Medium - Fair Distribution of Cookies
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BackTracking{
    int n;
    int ans=INT_MAX;
    void solve(vector<int>&cookies,vector<int>&children,int k,int idx){
        if(idx>=n){
            int maxCandies=*max_element(begin(children),end(children));
            ans=min(ans,maxCandies);
            return;
        }

        for(int i=0;i<k;i++){
            children[i]+=cookies[idx];
            solve(cookies,children,k,idx+1);
            children[i]-=cookies[idx];
        }
    }
    public:
    int distributeCookies(vector<int>&cookies,int k){
        n=cookies.size();
        vector<int>children(k,0);

        solve(cookies,children,k,0);
        return ans;
    }
};
int main(){
    // Output: 31
    vector<int>cookies={8,15,10,20,8};
    int k=2;
    // Output: 7
    vector<int>cookies2={6,1,3,2,2,4,1,2};
    int k2=3;

    BackTracking sol;
    cout<<sol.distributeCookies(cookies,k)<<endl;
    cout<<sol.distributeCookies(cookies2,k2);
    return 0;
}