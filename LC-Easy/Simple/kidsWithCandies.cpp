// LC - 1431 - Easy - Kids With the Greatest Number of Candies
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool> kidsWithCandies(vector<int>&candies,int extraCandies){
    int n=candies.size();
    vector<bool>ans;
    int max=*max_element(begin(candies),end(candies));

    for(int i=0;i<n;i++){
        if(candies[i]+extraCandies>=max) ans.push_back(true);
        else ans.push_back(false);
    }
    return ans;
}
int main(){
    // Output: [true,true,true,false,true] 
    vector<int>candies={2,3,5,1,3};
    int extraCandies=3;
    // Output: [true,false,false,false,false] 
    vector<int>candies2={4,2,1,1,2};
    int extraCandies2=1;
    // Output: [true,false,true]
    vector<int>candies3={12,1,12};
    int extraCandies3=10;
    return 0;
}