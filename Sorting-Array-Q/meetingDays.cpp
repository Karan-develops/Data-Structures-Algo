// LC - 3169 -Medium - Count Days Without Meetings
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countDays(int days,vector<vector<int>>&meetings){
    sort(meetings.begin(),meetings.end());

    int start=0,end=0,ans=0;

    for(auto &meet:meetings){
        if(meet[0]>end){
            ans+=meet[0]-end-1;
        }
        end=max(end,meet[1]);
    }
    if(days>end) ans+=days-end;
    return ans;
}
int main(){
    // Output: 2
    int days=10;
    vector<vector<int>>meetings={{5,7},{1,3},{9,10}};
    // Output: 1
    int days2=5;
    vector<vector<int>>meetings2={{2,4},{1,3}};
    cout<<countDays(days,meetings)<<endl;
    cout<<countDays(days2,meetings2);
    return 0;
}