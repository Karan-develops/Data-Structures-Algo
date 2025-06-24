// LC - 2141 - HARD - Maximum Running Time of N Computers
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class BinarySearch{
    typedef long long ll;
    bool canRun(vector<int>&batteries,int n,ll mid){
        ll target_minutes=mid*n;

        for(int i=0;i<batteries.size();i++){
            target_minutes-=min((ll) batteries[i],mid);

            if(target_minutes<=0) return true;
        }
        return false;
    }
    public:
    long long maxRunTime(int n,vector<int>&batteries){
        ll l=*min_element(begin(batteries),end(batteries));

        ll sum=accumulate(begin(batteries),end(batteries),0LL);
        ll r=sum/n;

        ll ans=0;

        while(l<=r){
            ll mid=l+(r-l)/2;

            if(canRun(batteries,n,mid)){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 4
    int n=2;
    vector<int>batteries={3,3,3};
    // Output: 2
    int n2=2;
    vector<int>batteries2={1,1,1,1};

    BinarySearch sol;
    cout<<sol.maxRunTime(n,batteries)<<endl;
    cout<<sol.maxRunTime(n2,batteries2);
    return 0;
}