// LC - 1513 - Medium - Number of Substrings With Only 1s
// 2 Approaches
#include<iostream>
using namespace std;
// Approach 1 - Using Formula
class Formula{
    const int M=1e9+7;
    public:
    int numSub(string s){
        long long ans=0;
        long long count1=0;

        for(char &ch:s){
            if(ch=='1'){
                count1++;
            } else {
                ans=(ans+count1*(count1+1)/2)%M;
                count1=0;
            }
        }

        // Adding the last group of 1s
        ans=(ans+count1*(count1+1)/2)%M;

        return (int)ans;
    }
};
// Approach 2 - Simple
class Maths{
    const int M=1e9+7;
    public:
    int numSub(string s){
        int ans=0;
        int curr=0;

        for(char &ch:s){
            if(ch=='1'){
                curr++;
                ans=(ans+curr)%M;
            } else{
                curr=0;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 9
    string s="0110111";
    // Output: 2
    string s2="101";
    // Output: 21
    string s3="111111";

    Maths sol;
    cout<<sol.numSub(s)<<endl;
    cout<<sol.numSub(s2)<<endl;
    cout<<sol.numSub(s3);
    return 0;
}