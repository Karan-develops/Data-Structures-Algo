/*The Differnce Array technique is a powerful tool for efficiently performing range update queries on an array. It allows you to update a range of elements in constant time and then compute the final values with a single pass through the array.
--> Theory
1) Create a difference array diff of size n+1 (where n is the size of the original array arr), initialized to 0.
2) Range Update: To increment all elements from index l to r by a value val, do:
diff[l] += val
diff[r+1] -= val
3) Final Array: Compute the final values of the original array by taking the cummulative OR prefix sum of the diff array.*/
// LC*Premium - Range Sum
#include<iostream>
#include<vector>
using namespace std;
void applyDiffArray(vector<int>&arr,const vector<vector<int>>&updates){
    int n=arr.size();
    vector<int>diff(n+1,0);
    // Applying the updates to the difference array
    for(const auto& update:updates){
        int l=update[0];
        int r=update[1];
        int val=update[2];
        diff[l]+=val;
        if(r+1<n){
            diff[r+1]-=val;
        }
    }
    // Constructing the final array using the difference array
    arr[0]=diff[0];
    for (int i=1;i<n;++i){
        arr[i]=arr[i-1]+diff[i];
    }
}
int main(){
    vector<int>arr={0,0,0,0,0};
    vector<vector<int>>updates={{1,3,2},{2,4,3},{0,2,-2}};
    applyDiffArray(arr,updates);
    // Printing the updated array
    for(int i:arr) cout<<i<<" ";
    return 0;
}