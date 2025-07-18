// Quick-Select Algorithm ( Hoare's selection Algorithm )
// Quick Select algorithm in used to find k-th smallest/Largest element in an unsorted array
// Average T.C => O(n)
// Worst Case => O(n^2)
// LC - 215 - Medium - Kth Largest Element in an Array
#include<iostream>
#include<vector>
using namespace std;
class QuickSelect{
    int partition(vector<int>&nums,int L,int R){
        int P=nums[L]; // Pivot Element
        int i=L+1; // L+1 prevents if there is only 1 element
        int j=R;

        // Left Side all greater element & Right Side Smaller
        // Example : 8, 5, 7, 4(Pivot), 1, 2
        while(i<=j){
            if(P>nums[i] && P<nums[j]){
                swap(nums[i],nums[j]);
                i++,j--;
            }
            
            if(P<=nums[i]) i++;
            if(P>=nums[j]) j--;
        }
        swap(nums[L],nums[j]);
        // P is at jth index
        return j;
    }
    public:
    int quickSelect(vector<int>&nums,int k){
        int n=nums.size();

        int L=0;
        int R=n-1;
        int pivot_idx=0;

        while(true){
            pivot_idx=partition(nums,L,R);

            if(pivot_idx==k-1) break;
            else if(pivot_idx>k-1){
                R=pivot_idx-1;
            } else{
                L=pivot_idx+1;
            }
        }
        return nums[pivot_idx];
    }
};
int main(){
    // Output: 5
    vector<int>nums={3,2,1,5,6,4};
    int k=2;
    // Output: 4
    vector<int>nums2={3,2,3,1,2,4,5,5,6};
    int k2=4;

    QuickSelect sol;
    cout<<sol.quickSelect(nums,k)<<endl;
    cout<<sol.quickSelect(nums2,k2);
    return 0;
}