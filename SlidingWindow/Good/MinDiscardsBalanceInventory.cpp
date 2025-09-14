// LC - 3679 - Medium - Minimum Discards to Balance Inventory
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int minArrivalsToDiscard(vector<int>&arrivals,int w,int m){
    int n=arrivals.size();

    unordered_map<int,int>mp;
    queue<pair<int,int>>q;

    int ans=0;

    for(int i=0;i<n;i++){
        int day=i+1;
        int type=arrivals[i];

        while(!q.empty() && q.front().first<=day-w){
            int oldType=q.front().second;
            q.pop();

            mp[oldType]--;
            if(mp[oldType]==0) mp.erase(oldType);
        }

        if(mp[type]<m){
            mp[type]++;
            q.push({day,type});
        } else{
            ans++;
        }
    }
    return ans;
}
int main(){
    // Output: 0
    vector<int>arrivals={1,2,1,3,1};
    int w=4,m=2;
    // Output: 1
    vector<int>arrivals2={1,2,3,3,3,4};
    int w2=3,m2=2;
    cout<<minArrivalsToDiscard(arrivals,w,m)<<endl;
    cout<<minArrivalsToDiscard(arrivals2,w2,m2);
    return 0;
}