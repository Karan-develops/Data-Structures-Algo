// LC - 1534 - Easy - Count Good Triplets
#include<iostream>
#include<vector>
using namespace std;
int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int n=arr.size();
    int ans=0;
    for(int i=0;i<=n-3;i++){
        for(int j=i+1;j<=n-2;j++){
            if(abs(arr[i]-arr[j])<=a){
                for(int k=j+1;k<=n-1;k++){
                    if(abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c){
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>arr={3,0,1,1,9,7};
    int a=7,b=2,c=3;
    // Output: 0
    vector<int>arr2={1,1,2,2,3};
    int a2=0,b2=0,c2=1;
    cout<<countGoodTriplets(arr,a,b,c)<<endl;
    cout<<countGoodTriplets(arr2,a2,b2,c2);
    return 0;
}