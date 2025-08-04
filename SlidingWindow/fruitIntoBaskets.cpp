// LC - 904 - Medium - Fruit Into Baskets
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int totalFruit(vector<int>&fruits){
    int n=fruits.size();

    int ans=0;
    int i=0,j=0;
    unordered_map<int,int>mp;

    while(j<n){
        mp[fruits[j]]++;

        while(mp.size()>2){
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0){
                mp.erase(fruits[i]);
            }
            i++;
        }
        
        ans=max(ans,j-i+1);
        j++;
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>fruits={1,2,1};
    // Output: 3
    vector<int>fruits2={0,1,2,2};
    // Output: 4
    vector<int>fruits3={1,2,3,2,2};
    cout<<totalFruit(fruits)<<endl;
    cout<<totalFruit(fruits2)<<endl;
    cout<<totalFruit(fruits3);
    return 0;
}