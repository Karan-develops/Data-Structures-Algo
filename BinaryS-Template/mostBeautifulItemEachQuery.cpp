// LC - 2070 - Medium - Most Beautiful Item for Each Query
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    int binaryS(vector<vector<int>>&items,int qP){
        int l=0,r=items.size()-1;
        int maxBeauty=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(items[mid][0]>qP){
                r=mid-1;
            } else{
                maxBeauty=max(maxBeauty,items[mid][1]);
                l=mid+1;
            }
        }
        return maxBeauty;
    }
    public:
    vector<int> maximumBeauty(vector<vector<int>>&items,vector<int>&queries){
        int m=items.size(),n=queries.size();

        sort(items.begin(),items.end());

        int maxBeauty=items[0][1];
        for(int i=1;i<m;i++){
            maxBeauty=max(maxBeauty,items[i][1]);
            items[i][1]=maxBeauty;
        }

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=binaryS(items,queries[i]);
        }
        return ans;
    }
};
int main(){
    // Output: [2,4,5,5,6,6]
    vector<vector<int>>items={{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int>queries={1,2,3,4,5,6};
    // Output: [4]
    vector<vector<int>>items2={{1,2},{1,2},{1,3},{1,4}};
    vector<int>queries2={1};
    // Output: [0]
    vector<vector<int>>items3={{10,1000}};
    vector<int>queries3={5};
    return 0;
}