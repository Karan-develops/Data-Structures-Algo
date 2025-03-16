// LC - 2594 - Medium - Minimum Time to Repair Cars
// This is binary search on Time
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
bool isPossible(vector<int>&ranks,int &cars,ll &mid){
    int carsFixed=0;
    for(int i=0;i<ranks.size();i++){
        carsFixed+=sqrt(mid/ranks[i]);
    }
    return carsFixed>=cars;
}
long long repairCars(vector<int>&ranks,int cars){
    int n=ranks.size();
    ll l=1;
    ll maxWork=*max_element(ranks.begin(),ranks.end());
    ll r=1ll*maxWork*cars*cars;
    ll ans=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(isPossible(ranks,cars,mid)){
            ans=mid;
            r=mid-1;
        } else{
            l=mid+1;
        }
    }
    return ans;
}
int main(){
    // OP - 16
    vector<int>ranks1={4,2,3,1};
    int cars1=10;
    // OP - 16
    vector<int>ranks2={5,1,8};
    int cars2=6;
    cout<<repairCars(ranks1,cars1)<<endl;
    cout<<repairCars(ranks2,cars2);
    return 0;
}