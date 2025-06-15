// LC - 2300 - Medium - Successful Pairs of Spells and Potions
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class BinarySearch{
    int binarySearch(vector<int>&potions,int minPotion,int l,int r){
        int idx=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(minPotion<=potions[mid]){
                idx=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return idx;
    }
    public:
    vector<int> successfulPairs(vector<int>&spells,vector<int>&potions,long long success){
        int m=spells.size();
        int n=potions.size();

        sort(begin(potions),end(potions));
        int maxPotion=potions[n-1];

        vector<int>ans;

        for(int i=0;i<m;i++){
            long long minPotion=ceil((1.0*success)/spells[i]);

            if(minPotion>maxPotion){
                ans.push_back(0);
                continue;
            }

            // Make Binary Search Fn If u want :)
            int index=lower_bound(begin(potions),end(potions),minPotion)-begin(potions);
            ans.push_back(n-index);
        }
        return ans;
    }
};
int main(){
    // Output: [4,0,3]
    vector<int>spells={5,1,3},potions={1,2,3,4,5};
    int success=7;
    // Output: [2,0,2]
    vector<int>spells2={3,1,2},potions2={8,5,8};
    int success2=16;

    BinarySearch sol;
    vector<int>ans=sol.successfulPairs(spells,potions,success);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}