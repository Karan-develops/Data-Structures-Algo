// This is to Find 2nd Largest Or Smallest Element.
#include<iostream>
#include<vector>
using namespace std;
int find2ndLargest(vector<int>&nums){
    int largest=0;
    int ans=0;

    for(int &i:nums){
        if(i>largest){
            ans=largest;
            largest=i;
        } else if(i>ans && i!=largest){
            ans=i;
        }
    }
    return ans;
}
int find2ndSmallest(vector<int>&nums){
    int smallest=INT_MAX;
    int ans=INT_MAX;

    for(int &i:nums){
        if(i<smallest){
            ans=smallest;
            smallest=i;
        } else if(i<ans && i!=smallest){
            ans=i;
        }
    }
    return ans==INT_MAX?-1:ans;
}
int main(){
    vector<int>nums={5,2,7,2,51,13,1,6};
    cout<<find2ndLargest(nums)<<endl;
    cout<<find2ndSmallest(nums);
    return 0;
}