// GFG - Count the number of possible triangles
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countTriangles(vector<int>&arr){
    int n=arr.size();

    sort(begin(arr),end(arr));
    int ans=0;

    for(int k=n-1;k>=2;k--){
        int i=0,j=k-1;
        
        while(i<j){
            if(arr[i]+arr[j]>arr[k]){
                ans+=(j-i);
                j--;
            }
            else i++;
        }
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>arr={4,6,3,7};
    // Output: 6
    vector<int>arr2={10,21,22,100,101,200,300};
    // Output: 0
    vector<int>arr3={1,2,3};
    cout<<countTriangles(arr)<<endl;
    cout<<countTriangles(arr2)<<endl;
    cout<<countTriangles(arr3);
    return 0;
}