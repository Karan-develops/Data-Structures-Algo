// LC - 3480 - HARD - Maximize Subarrays After Removing One Conflicting Pair
#include<iostream>
#include<vector>
#include<algorithm>
#define ALL(x) begin(x),end(x)
using namespace std;
long long maxSubarrays(int n,vector<vector<int>>&conflictingPairs){
    long long valid=0;

    vector<vector<int>>conflitingPoints(n+1);

    for(auto &vec:conflictingPairs){
        int minP=min(vec[0],vec[1]);
        int maxP=max(vec[0],vec[1]);

        conflitingPoints[maxP].push_back(minP);
    }

    int maxConflict=0;
    int secondMaxConflict=0;
    vector<long long>extra(n+1,0);

    for(int end=1;end<=n;end++){
        // Check all conflicting points of end
        for(int &start:conflitingPoints[end]){
            if(start>=maxConflict){
                secondMaxConflict=maxConflict;
                maxConflict=start;
            } else if(start>secondMaxConflict){
                secondMaxConflict=start;
            }
        }

        valid+=end-maxConflict;
        extra[maxConflict]+=maxConflict-secondMaxConflict;
    }

    // return valid+*max_element(begin(extra),end(extra));
    return valid+*max_element(ALL(extra));
}
int main(){
    // Output: 9
    int n=4;
    vector<vector<int>>conflictingPairs={{2,3},{1,4}};
    // Output: 12
    int n2=5;
    vector<vector<int>>conflictingPairs2={{1,2},{2,5},{3,5}};
    cout<<maxSubarrays(n,conflictingPairs)<<endl;
    cout<<maxSubarrays(n2,conflictingPairs2);
    return 0;
}