// LC - 2106 - HARD - Maximum Fruits Harvested After at Most K Steps
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxTotalFruits(vector<vector<int>>&fruits,int startPos,int k){
    int n=fruits.size();

    vector<int>prefixSum(n);
    vector<int>fruitPositions(n);

    for(int i=0;i<n;i++){
        fruitPositions[i]=fruits[i][0];

        prefixSum[i]=fruits[i][1]+((i>0)?prefixSum[i-1]:0);
    }

    int ans=0;

    for(int d=0;d<=k/2;d++){
        // Case 1 : Left Side
        int i=startPos-d;
        int remainingSteps=k-2*d;
        int j=startPos+remainingSteps;

        int left=lower_bound(begin(fruitPositions),end(fruitPositions),i)-begin(fruitPositions);
        int right=upper_bound(begin(fruitPositions),end(fruitPositions),j)-begin(fruitPositions)-1;

        if(left<=right){
            ans=max(ans,prefixSum[right]-(left>0?prefixSum[left-1]:0));
        }

        // Case 2 : Right Side
        i=startPos-remainingSteps;
        j=startPos+d;

        left=lower_bound(begin(fruitPositions),end(fruitPositions),i)-begin(fruitPositions);
        right=upper_bound(begin(fruitPositions),end(fruitPositions),j)-begin(fruitPositions)-1;

        if(left<=right){
            ans=max(ans,prefixSum[right]-(left>0?prefixSum[left-1]:0));
        }
    }
    return ans;
}
int main(){
    // Output: 9
    vector<vector<int>>fruits={{2,8},{6,3},{8,6}};
    int startPos=5,k=4;
    // Output: 14
    vector<vector<int>>fruits2={{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}};
    int startPos2=5,k2=4;
    // Output: 0
    vector<vector<int>>fruits3={{0,3},{6,4},{8,5}};
    int startPos3=3,k3=2;
    cout<<maxTotalFruits(fruits,startPos,k)<<endl;
    cout<<maxTotalFruits(fruits2,startPos2,k2)<<endl;
    cout<<maxTotalFruits(fruits3,startPos3,k3);
    return 0;
}