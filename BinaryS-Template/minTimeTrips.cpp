// LC - 2187 - Medium - Minimum Time to Complete Trips
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    bool possible(vector<int>&time,int &totalTrips,long long givenTime){
        long long actualTripsCount=0;

        for(int &t:time){
            actualTripsCount+=(givenTime/t);
        }
        return actualTripsCount>=totalTrips;
    }
    public:
    long long minimumTime(vector<int>&time,int totalTrips){
        long long l=1;
        // Right Bound => Fastest Bus Complete All Trips
        long long r=*min_element(begin(time),end(time))*totalTrips;

        while(l<r){
            int mid=l+(r-l)/2;

            if(possible(time,totalTrips,mid)){
                r=mid;
            } else{
                l=mid+1;
            }
        }
        return l;
    }
};
int main(){
    // Output: 3
    vector<int>time={1,2,3};
    int totalTrips=5;
    // Output: 2
    vector<int>time2={2};
    int totalTrips2=1;

    BinarySearch sol;
    cout<<sol.minimumTime(time,totalTrips)<<endl;
    cout<<sol.minimumTime(time2,totalTrips2);
    return 0;
}