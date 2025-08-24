// GFG - Medium - Minimum days to make M bouquets
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    bool canMake(vector<int>&arr,int m,int k,int day){
        int count=0,bouquets=0;
        
        for(int &i:arr){
            if(i<=day){
                count++;
                if(count==k){
                    bouquets++;
                    count=0;
                }
            }
            else count=0;
        }
        return bouquets>=m;
    }
    public:
    int minDaysBloom(vector<int>&arr,int k,int m){
        int l=*min_element(begin(arr),end(arr));
        int r=*max_element(begin(arr),end(arr));
        int ans=-1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(canMake(arr,m,k,mid)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 8
    int m=3,k=2;
    vector<int>arr={3,4,2,7,13,8,5};
    // Output: 10
    int m2=2,k2=3;
    vector<int>arr2={5,5,5,5,10,5,5};
    // Output: -1
    int m3=3,k3=2;
    vector<int>arr3={1,10,3,10,2};

    BinarySearch sol;
    cout<<sol.minDaysBloom(arr,k,m)<<endl;
    cout<<sol.minDaysBloom(arr2,k2,m2)<<endl;
    cout<<sol.minDaysBloom(arr3,k3,m3);
    return 0;
}