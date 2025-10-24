// LC - 2048 - Medium - Next Greater Numerically Balanced Number
// Topics : Hash Table, Math, Backtracking, Counting, Enumeration
// 3 Approaches
// Approach 1 & 2 → https://github.com/Karan-develops/Data-Structures-Algo/blob/main/Maths/nextGreaterNumericallyBalancedNumber.cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 3 - BackTracking
class BackTracking{
    vector<int>digitsCount{0,1,2,3,4,5,6,7,8,9};
    int solve(int n,int curr,int count){
        if(count==0){
            for(int i=1;i<=9;i++){
                if(digitsCount[i]!=0 && digitsCount[i]!=i){
                    return 0;
                }
            }
            return curr>n?curr:0;
        }

        int ans=0;

        for(int i=1;i<=9;i++){
            if(digitsCount[i]>0 && digitsCount[i]<=count){
                digitsCount[i]--;

                ans=solve(n,curr*10+i,count-1);

                digitsCount[i]++;
            }

            if(ans!=0) break;
        }

        return ans;
    }
    public:
    int nextBeautifulNumber(int n){
        int digits=to_string(n).length();

        int ans=solve(n,0,digits);

        if(ans==0) return solve(n,0,digits+1);

        return ans;
    }
};
int main(){
    // Output: 22
    int n=1;
    // Output: 1333
    int n2=1000;
    // Output: 3133
    int n3=3000;

    BackTracking sol;
    cout<<sol.nextBeautifulNumber(n)<<endl;
    cout<<sol.nextBeautifulNumber(n2)<<endl;
    cout<<sol.nextBeautifulNumber(n3);
    return 0;
}