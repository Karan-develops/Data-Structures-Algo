// LC - 2561 - HARD - Rearranging Fruits
// Topics -> Array, Hash Table, Greedy, Sorting
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
long long minCost(vector<int>&basket1,vector<int>&basket2){
    int n=basket1.size();

    unordered_map<int,int>mp;
    int minE=INT_MAX;

    for(int i=0;i<n;i++){
        mp[basket1[i]]++;
        mp[basket2[i]]--;
        minE=min({minE,basket1[i],basket2[i]});
    }

    vector<int>extraFruits;

    for(auto &it:mp){
        int cost=it.first;
        int freq=it.second;

        if(freq==0) continue;

        // Odd Freq can't be distributed
        if(freq&1) return -1;

        for(int i=1;i<=abs(freq/2);i++){
            extraFruits.push_back(cost);
        }
    }

    // sort(begin(extraFruits),end(extraFruits));
    // Since we need only first half the array so
    nth_element(begin(extraFruits),begin(extraFruits)+extraFruits.size()/2,end(extraFruits));

    long long ans=0;
    for(int i=0;i<extraFruits.size()/2;i++){
        /* Either use minimum cost fruit 2 times to swap fruits
            or use current fruit bcoz we sorted the extraFruits */
        ans+=min(extraFruits[i],2*minE);
    }
    return ans;
}
int main(){
    // Output: 1
    vector<int>basket1={4,2,2,2},basket2={1,4,1,2};
    // Output: -1
    vector<int>basket3={2,3,4,1},basket4={3,2,5,1};
    cout<<minCost(basket1,basket2)<<endl;
    cout<<minCost(basket3,basket4);
    return 0;
}