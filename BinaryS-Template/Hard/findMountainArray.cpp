// LC - 1095 - HARD - Find in Mountain Array
// Find Smallest Index
#include<iostream>
#include<vector>
using namespace std;
// ************************
// Demo API - Class
class MountainArray{
    public:
    int len;
    int get(int idx){
        return 0;
    }
    int length(){
        return len;
    }
};
// ************************
class BinarySearch{
    int n;
    int findPeakIdx(MountainArray &mountainArr){
        int l=0,r=n-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return l;
    }
    int binarySearch(MountainArray &mountainArr,int peak,int target){
        int l=0,r=peak;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(mountainArr.get(mid)==target){
                return mid;
            } else if(mountainArr.get(mid)>target){
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return -1;
    }
    int reverseBinarySearch(MountainArray &mountainArr,int peak,int target){
        int l=peak,r=n-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(mountainArr.get(mid)==target){
                return mid;
            } else if(mountainArr.get(mid)<target){
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return -1;
    }
    public:
    int findInMountainArray(int target,MountainArray &mountainArr){
        n=mountainArr.length();

        int peak=findPeakIdx(mountainArr);

        int ans=binarySearch(mountainArr,peak,target);
        
        if(ans==-1){
            return reverseBinarySearch(mountainArr,peak,target);
        }
        return ans;
    }
};