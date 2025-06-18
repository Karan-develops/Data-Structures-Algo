// LC - 1802 - Medium - Maximum Value at a Given Index in a Bounded Array
#include<iostream>
using namespace std;
class BinarySearch{
    typedef long long ll;
    ll getSumElements(ll count,ll val){
        return val*count-(count*(count+1))/2;
    }
    public:
    int maxValue(int n,int index,int maxSum){
        ll l=1;
        ll r=maxSum;
        ll mid;
        int ans=0;
        
        while(l<=r){
            mid=l+(r-l)/2;
            // Left
            ll left_count=min((ll) index,mid-1);
            ll left_sum=getSumElements(left_count,mid);
            left_sum+=max((ll) 0,index-mid+1);
            // Right
            ll right_count=min((ll) n-index-1,mid-1);
            ll right_sum=getSumElements(right_count,mid);
            right_sum+=max((ll)0,n-index-1-mid+1);
            
            if(left_sum+right_sum+mid<=maxSum){
                ans=max((ll)ans,mid);
                l=mid+1;
            } else{
                r=mid-1;
            }
            
        }
        return ans;
    }
};
int main(){
    // Output: 2
    int n=4,index=2,maxSum=6;
    // Output: 3
    int n2=6,index2=1,maxSum2=10;

    BinarySearch sol;
    cout<<sol.maxValue(n,index,maxSum)<<endl;
    cout<<sol.maxValue(n2,index2,maxSum2);
    return 0;
}