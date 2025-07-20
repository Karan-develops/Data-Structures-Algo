// GFG - Count Numbers Containing Specific Digits
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int countValid(int n,vector<int>&arr){
    int N=arr.size();
    
    bool zeroes=find(begin(arr),end(arr),0)!=arr.end();
    
    if(n==1) return N-(zeroes?1:0);
    
    int not_have_cnt=9-N+zeroes;
    
    for(int i=1;i<n;i++){
        not_have_cnt*=(10-N);
    }

    int total_num=pow(10,n-1)*9;
    
    return total_num-not_have_cnt;
}
int main(){
    // Output: 3
    int n=1;
    vector<int>arr={1,2,3};
    // Output: 34
    int n2=2;
    vector<int>arr2={3,5};
    cout<<countValid(n,arr)<<endl;
    cout<<countValid(n2,arr2);
    return 0;
}