// GFG - Equalize the Towers
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    int n;
    typedef long long ll;
    bool checkPrice(vector<int>&heights,vector<int>&cost,int mid){
        ll costMid=0;
        ll costMidP1=0; // Plus 1 Index

        for(int i=0;i<n;i++){
            costMid+=(abs(heights[i]-(mid))*cost[i]);
            costMidP1+=(abs(heights[i]-(mid+1))*cost[i]);
        }
        return costMid<costMidP1;
    }
    public:
    int minCost(vector<int>&heights,vector<int>&cost){
        n=heights.size();
        int l=*min_element(begin(heights),end(heights));
        int r=*max_element(begin(heights),end(heights));

        int targetH=0;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(checkPrice(heights,cost,mid)){
                targetH=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=(ll) (abs(heights[i]-targetH)*cost[i]);
        }
        return (int)ans;
    }
};
int main(){
    // Output: 120
    vector<int>heights={1,2,3},cost={10,100,1000};
    // Output: 6
    vector<int>heights2={7,1,5},cost2={1,1,1};

    BinarySearch sol;
    cout<<sol.minCost(heights,cost)<<endl;
    cout<<sol.minCost(heights2,cost2);
    return 0;
}