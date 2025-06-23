// LC - 1870 - Medium - Minimum Speed to Arrive on Time
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class BinarySearch{
    bool getSpeed(vector<int>&dist,double &hour,int mid){
        int n=dist.size();
        double time_at_currSpeed=0.0;

        for(int i=0;i<n-1;i++){
            time_at_currSpeed+=ceil((double) dist[i]/(double) mid);
        }

        time_at_currSpeed+=(double)dist[n-1]/(double) mid;
        return time_at_currSpeed<=hour;
    }
    public:
    int minSpeedOnTime(vector<int>&dist,double hour){
        int l=1;
        int r=1e7;

        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(getSpeed(dist,hour,mid)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 1
    vector<int>dist={1,3,2};
    double hour=6;
    // Output: 3
    vector<int>dist2={1,3,2};
    double hour2=2.7;
    // Output: -1
    vector<int>dist3={1,3,2};
    double hour3=1.9;

    BinarySearch sol;
    cout<<sol.minSpeedOnTime(dist,hour)<<endl;
    cout<<sol.minSpeedOnTime(dist2,hour2)<<endl;
    cout<<sol.minSpeedOnTime(dist3,hour3);
    return 0;
}