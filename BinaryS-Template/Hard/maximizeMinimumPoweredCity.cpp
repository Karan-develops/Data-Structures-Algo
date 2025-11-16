// LC - 2528 - HARD - Maximize the Minimum Powered City
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class BinarySearch{
    int n,R;
    typedef long long ll;
    bool isPossible(vector<int>stations,ll extra,ll mid){
        ll power=accumulate(begin(stations),begin(stations)+R,0L);

        for(int i=0;i<n;i++){
        if(i+R<n) power+=stations[i+R];
        
        if(power<mid){
            ll requiredPower=mid-power;
            
            if(requiredPower>extra) return false;
            
            stations[min(n-1,i+R)]+=requiredPower;
            
            extra-=requiredPower;
            
            power+=requiredPower;
        }
        
        if(i-R>=0) power-=stations[i-R];
        }
        return true;
    }
    public:
    long long maxPower(vector<int>&stations,int r,int k){
        n=stations.size();
        R=r;

        ll l=*min_element(begin(stations),end(stations));
        ll r_=accumulate(begin(stations),end(stations),0LL)+k+1;

        while(l<r_){
            ll mid=l+(r_-l)/2;

            if(isPossible(stations,k,mid)){
                l=mid+1;
            } else{
                r_=mid;
            }
        }
        return l-1;
    }
};
int main(){
    // Output: 5
    vector<int>stations={1,2,4,5,0};
    int r=1,k=2;
    // Output: 4
    vector<int>stations2={4,4,4,4};
    int r2=0,k2=3;

    BinarySearch sol;
    cout<<sol.maxPower(stations,r,k)<<endl;
    cout<<sol.maxPower(stations2,r2,k2);
    return 0;
}