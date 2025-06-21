// GFG - Police and Thieves
#include<iostream>
#include<vector>
using namespace std;
int catchThieves(vector<char>&arr,int k){
    int n=arr.size();
    int ans=0;
    
    int i=0,j=0;

    while(i<n && j<n){
        while(i<n && arr[i]!='P') i++;
        while(j<n && arr[j]!='T') j++;

        if(i<n && j<n && abs(i-j)<=k){
            ans++;
            i++,j++;
        } else if(j<n && j<i){
            j++;
        } else if(i<n && i<j){
            i++;
        }
    }
    return ans;
}
int main(){
    // Output: 2
    vector<char>arr={'P','T','T','P','T'};
    int k=1;
    // Output: 3
    vector<char>arr2={'T','T','P','P','T', 'P'};
    int k2=2;
    cout<<catchThieves(arr,k)<<endl;
    cout<<catchThieves(arr2,k2);
    return 0;
}