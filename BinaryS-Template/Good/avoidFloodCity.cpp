// LC - 1488 - Medium - Avoid Flood in The City
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
vector<int> avoidFlood(vector<int>&rains){
    int n=rains.size();

    // Lake->day
    unordered_map<int,int>mp;
    set<int>dryDays;
    vector<int>ans(n,1);

    for(int i=0;i<n;i++){
        int lake=rains[i];

        if(lake==0){
            dryDays.insert(i);
        } else{
            ans[i]=-1;

            if(mp.count(lake)){
                auto it=dryDays.lower_bound(mp[lake]+1);

                if(it==dryDays.end()){
                    return {};
                }

                ans[*it]=lake;
                dryDays.erase(it);
            }
        }
        mp[lake]=i;
    }
    return ans;
}
int main(){
    // Output: [-1,-1,-1,-1]
    vector<int>rains={1,2,3,4};
    // Output: [-1,-1,2,1,-1,-1]
    vector<int>rains2={1,2,0,0,2,1};
    // Output: []
    vector<int>rains3={1,2,0,1,2};
    return 0;
}