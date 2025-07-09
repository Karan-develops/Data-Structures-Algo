// LC - 3439 - Medium - Reschedule Meetings for Maximum Free Time I
#include<iostream>
#include<vector>
using namespace std;
int maxFreeTime(int eventTime,int k,vector<int>&startTime,vector<int>&endTime){
    vector<int>gapArray;
    gapArray.push_back(startTime[0]);

    for(int i=1;i<startTime.size();i++){
        gapArray.push_back(startTime[i]-endTime[i-1]);
    }
    
    gapArray.push_back(eventTime-endTime.back());

    int ans=0;
    int currSum=0;

    int i=0,j=0;
    int n=gapArray.size();

    while(j<n){
        currSum+=gapArray[j];

        while(i<n && j-i+1>k+1){
            currSum-=gapArray[i];
            i++;
        }

        ans=max(ans,currSum);
        j++;
    }
    return ans;
}
int main(){
    // Output: 2
    int eventTime=5,k=1;
    vector<int>startTime={1,3},endTime={2,5};
    // Output: 6
    int eventTime2=10,k2=1;
    vector<int>startTime2={0,2,9},endTime2={1,4,10};
    // Output: 0
    int eventTime3=5,k3=2;
    vector<int>startTime3={0,1,2,3,4},endTime3={1,2,3,4,5};
    cout<<maxFreeTime(eventTime,k,startTime,endTime)<<endl;
    cout<<maxFreeTime(eventTime2,k2,startTime2,endTime2)<<endl;
    cout<<maxFreeTime(eventTime3,k3,startTime3,endTime3);
    return 0;
}