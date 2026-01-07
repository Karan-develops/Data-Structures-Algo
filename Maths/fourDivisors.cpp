// LC - 1390 - Medium - Four Divisors
#include<iostream>
#include<vector>
using namespace std;
class Maths{
    int sumIfFourDivisors(int num){
        int divisors=0;
        int sum=0;

        for(int div=1;div*div<=num;div++){
            if(num%div==0){
                int other=num/div;

                if (div==other){
                    divisors++;
                    sum+=div;
                } else{
                    divisors+=2;
                    sum+=(div+other);
                }
            }
            if(divisors>4) return 0;
        }

        return divisors==4?sum:0;
    }
    public:
    int sumFourDivisors(vector<int>&nums){
        int ans=0;

        for (int &i:nums){
            ans+=sumIfFourDivisors(i);
        }

        return ans;
    }
};
int main(){
    // Output: 32
    vector<int>nums={21,4,7};
    // Output: 64
    vector<int>nums2={21,21};
    // Output: 0
    vector<int>nums3={1,2,3,4,5};

    Maths sol;
    cout<<sol.sumFourDivisors(nums)<<endl;
    cout<<sol.sumFourDivisors(nums2)<<endl;
    cout<<sol.sumFourDivisors(nums3);
    return 0;
}