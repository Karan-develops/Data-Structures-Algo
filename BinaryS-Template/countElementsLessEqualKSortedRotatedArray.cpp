// GFG - Medium - Count elements less than or equal to k in a sorted rotated array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    int findPivot(vector<int>&arr){
        int l=0,r=arr.size()-1;
    
        while(l<r){
            int mid=l+(r-l)/2;
            // Chote elements right side h
            if(arr[mid]>arr[r]) l=mid+1;
            else r=mid;
        }
        
        return r;
    }
    public:
    int countLessEqual(vector<int>&arr,int x){
        int pivot=findPivot(arr);
        
        int ans=0;
        
        ans+=upper_bound(begin(arr)+pivot,end(arr),x)-(begin(arr)+pivot);
        ans+=upper_bound(begin(arr),begin(arr)+pivot,x)-begin(arr);
        
        return ans;
    }
};
int main(){
    // Output: 4
    int x=6;
    vector<int>arr={4,5,8,1,3};
    // Output: 6
    int x2=14;
    vector<int>arr2={6,10,12,15,2,4,5};

    BinarySearch sol;
    cout<<sol.countLessEqual(arr,x)<<endl;
    cout<<sol.countLessEqual(arr2,x2);
    return 0;
}