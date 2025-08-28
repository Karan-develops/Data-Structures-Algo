// LC - 2614 - Easy - Prime In Diagonal
#include<iostream>
#include<vector>
using namespace std;
class Matrix{
    bool checkPrime(int num){
        if(num<2) return false;
        if(num%2==0) return num==2;

        for(int i=3;i*i<=num;i+=2){
            if(num%i==0) return false;
        }
        return true;
    }
    public:
    int diagonalPrime(vector<vector<int>>&nums){
        int n=nums.size();

        int ans=0;

        for(int i=0;i<n;i++){
            if(nums[i][i]>ans && checkPrime(nums[i][i])) ans=nums[i][i];
            if(nums[i][n-i-1]>ans && checkPrime(nums[i][n-i-1])) ans=nums[i][n-i-1];
        }
        return ans;
    }
};
int main(){
    // Output: 11
    vector<vector<int>>nums={{1,2,3},{5,6,7},{9,10,11}};
    // Output: 17
    vector<vector<int>>nums2={{1,2,3},{5,17,7},{9,11,10}};

    Matrix sol;
    cout<<sol.diagonalPrime(nums)<<endl;
    cout<<sol.diagonalPrime(nums2);
    return 0;
}