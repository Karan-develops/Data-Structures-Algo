// GFG - Difference Check
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    int timeToSeconds(const string &timeStr){
        int h=stoi(timeStr.substr(0,2));
        int m=stoi(timeStr.substr(3,2));
        int s=stoi(timeStr.substr(6,2));

        return h*3600+m*60+s;
    }
    public:
    int minDifference(vector<string>&arr){
        vector<int>temp;
        
        for(string &timeStr:arr){
            temp.push_back(timeToSeconds(timeStr));
        }
    
        sort(begin(temp),end(temp));
    
        int n=temp.size();
        int ans=INT_MAX;
    
        for(int i=1;i<n;i++){
            ans=min(ans,temp[i]-temp[i-1]);
        }
        
        // 24*60*60
        // Example -> ["23:59","00:01"]
        int wrapAroundDiff=86400-temp[n-1]+temp[0];
        ans=min(ans,wrapAroundDiff);
    
        return ans;
    }
};
int main(){
    // Output: 30
    vector<string>arr={"12:30:15","12:30:45"};
    // Output: 2
    vector<string>arr2={"00:00:01","23:59:59","00:00:05"};

    Solution sol;
    cout<<sol.minDifference(arr)<<endl;
    cout<<sol.minDifference(arr2);
    return 0;
}