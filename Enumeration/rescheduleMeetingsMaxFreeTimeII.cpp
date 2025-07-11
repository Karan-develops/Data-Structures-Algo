// LC - 3440 - Medium - Reschedule Meetings for Maximum Free Time II
// Topics - Array, Greedy, Enumeration
#include<iostream>
#include<vector>
using namespace std;
int maxFreeTime(int eventTime,vector<int>&startTime,vector<int>&endTime){
    int N=startTime.size();
    vector<int>gaps;

    gaps.push_back(startTime[0]-0);

    for(int i=1;i<N;i++){
        gaps.push_back(startTime[i]-endTime[i-1]);
    }

    gaps.push_back(eventTime-endTime[N-1]);

    int n=gaps.size();
    vector<int>maxRight(n,0);
    vector<int>maxLeft(n,0);

    for(int i=n-2;i>=0;i--){
        maxRight[i]=max(maxRight[i+1],gaps[i+1]);
    }

    for(int i=1;i<n;i++){
        maxLeft[i]=max(maxLeft[i-1],gaps[i-1]);
    }

    int ans=0;
    for(int i=1;i<n;i++){
        int currMeetingDuration=endTime[i-1]-startTime[i-1];

        // Move the meeting to another free spot
        if(currMeetingDuration<=max(maxLeft[i-1],maxRight[i])){
            ans=max(ans,currMeetingDuration+gaps[i-1]+gaps[i]);
        }

        // Merge left and right free time
        ans=max(ans,gaps[i-1]+gaps[i]);
    }
    return ans;
}
int main(){
    // Output: 2
    int eventTime=5;
    vector<int>startTime={1,3},endTime={2,5};
    // Output: 7
    int eventTime2=10;
    vector<int>startTime2={0,7,9},endTime2={1,8,10};
    // Output: 6
    int eventTime3=10;
    vector<int>startTime3={0,3,7,9},endTime3={1,4,8,10};
    // Output: 0
    int eventTime4=5;
    vector<int>startTime4={0,1,2,3,4},endTime4={1,2,3,4,5};
    cout<<maxFreeTime(eventTime,startTime,endTime)<<endl;
    cout<<maxFreeTime(eventTime2,startTime2,endTime2)<<endl;
    cout<<maxFreeTime(eventTime3,startTime3,endTime3)<<endl;
    cout<<maxFreeTime(eventTime4,startTime4,endTime4);
    return 0;
}