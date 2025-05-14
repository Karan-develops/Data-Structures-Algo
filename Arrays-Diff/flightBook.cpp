// LC - 1109 - Medium - Corporate Flight Bookings
#include<iostream>
#include<vector>
using namespace std;
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    int N=bookings.size();
    vector<int>diff(n+1,0);
    for(auto &vec:bookings){
        int l=vec[0];
        int r=vec[1];
        int seats=vec[2];

        diff[l-1]+=seats;
        diff[r]-=seats;
    }
    vector<int>ans(n);
    ans[0]=diff[0];
    for(int i=1;i<n;i++){
        ans[i]=ans[i-1]+diff[i];
    }
    return ans;
}
int main(){
    // Output: [10,55,45,25,25]
    vector<vector<int>>bookings={{1,2,10},{2,3,20},{2,5,25}};
    int n=5;
    // Output: [10,25]
    vector<vector<int>>bookings2={{1,2,10},{2,2,15}};
    int n2=2;
    return 0;
}