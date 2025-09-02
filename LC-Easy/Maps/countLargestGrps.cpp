// LC - 1399 - Easy - Count Largest Group
#include<iostream>
#include<unordered_map>
using namespace std;
int countLargestGroup(int n){
    unordered_map<int,int>mp;

    int sum=0,j=0;
    
    for(int i=1;i<=n;i++){
        sum=0,j=i;
        
        while(j){
            sum+=j%10;
            j/=10;
        }
        mp[sum]++;
    }
    
    int ans=0,maxi=0;
    
    for(auto &it:mp){
        if(it.second>maxi){
            ans=1;
            maxi=it.second;
        }
        else if(it.second==maxi) ans++;
    }
    return ans;
}
int main(){
    // Output: 4
    int n=13;
    // Output: 2
    int n2=2;
    cout<<countLargestGroup(n)<<endl;
    cout<<countLargestGroup(n2);
    return 0;
}