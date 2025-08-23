// GFG - Medium - Allocate Minimum Pages
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class BinarySearch{
    int n;
    bool isPossibleSolution(vector<int>&arr,int k,int mid){
        int count=1;
        int pageSum=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>mid) return false;
            
            if(pageSum+arr[i]>mid){
                count++;
                pageSum=arr[i];
                
                if(count>k) return false;
            }
            else pageSum+=arr[i];
        }
        return true;
    }
    public:
    int findPages(vector<int>&arr,int k){
        n=arr.size();
        
        if(n<k) return -1;
        
        int l=0;
        int r=accumulate(begin(arr),end(arr),0);
        int ans=-1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(isPossibleSolution(arr,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 113
    vector<int>arr={12,34,67,90};
    int k=2;
    // Output: -1
    vector<int>arr2={15,17,20};
    int k2=5;

    BinarySearch sol;
    cout<<sol.findPages(arr,k)<<endl;
    cout<<sol.findPages(arr2,k2);
    return 0;
}