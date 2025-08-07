// LC - 539 - Medium - Minimum Time Difference
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMinDifference(vector<string>&timePoints){
    vector<int>minutes;

    for(string &time:timePoints){
        string hStr=time.substr(0,2);
        string mStr=time.substr(3);

        int h=stoi(hStr);
        int m=stoi(mStr);

        minutes.push_back(60*h+m);
    }

    sort(begin(minutes),end(minutes));

    int n=minutes.size();
    int ans=INT_MAX;
    
    for(int i=1;i<n;i++){
        ans=min(ans,minutes[i]-minutes[i-1]);
    }

    int wrapAroundTime=24*60-minutes[n-1]+minutes[0];

    return min(ans,wrapAroundTime);
}
int main(){
    // Output: 1
    vector<string>timePoints={"23:59","00:00"};
    // Output: 0
    vector<string>timePoints2={"00:00","23:59","00:00"};
    cout<<findMinDifference(timePoints)<<endl;
    cout<<findMinDifference(timePoints2);
    return 0;
}