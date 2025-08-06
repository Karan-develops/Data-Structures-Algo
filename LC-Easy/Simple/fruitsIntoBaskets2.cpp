// LC - 3477 - Easy - Fruits Into Baskets II
// Also in Segment Tree
#include<iostream>
#include<vector>
using namespace std;
int numOfUnplacedFruits(vector<int>&fruits,vector<int>&baskets){
    int n=fruits.size();
    int ans=0;

    for(int &i:fruits){
        bool placed=false;
        for(int j=0;j<n;j++){
            if(baskets[j]>=i){
                baskets[j]=INT_MIN;
                placed=true;
                break;
            }
        }
        if(!placed) ans++;
    }
    return ans;
}
int main(){
    // Output: 1
    vector<int>fruits={4,2,5},baskets={3,5,4};
    // Output: 0
    vector<int>fruits2={3,6,1},baskets2={6,4,7};
    cout<<numOfUnplacedFruits(fruits,baskets)<<endl;
    cout<<numOfUnplacedFruits(fruits2,baskets2);
    return 0;
}