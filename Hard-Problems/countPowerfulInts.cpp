// LC - 2999 - HARD - Count the Number of Powerful Integers
#include<iostream>
#include<math.h>
using namespace std;
class Solution{
    long long solve(string &str,string &inputSuffix,int limit){
        if(str.length()<inputSuffix.length()) return 0;

        long long ans=0;
        string remainingTrailingString=str.substr(str.length()-inputSuffix.length());
        int remainingL=str.length()-remainingTrailingString.length();

        for(int i=0;i<remainingL;i++){
            int currNum=str[i]-'0';
            if(currNum<=limit){
                ans+=currNum*pow(limit+1,remainingL-i-1);
            } else{
                ans+=pow(limit+1,remainingL-i);
                return ans;
            }
        }

        if(remainingTrailingString>=inputSuffix) ans++;
        return ans;
    }
    public:
    long long numberOfPowerfulInt(long long start,long long finish,int limit,string s){
        string start_str=to_string(start-1);
        string finish_str=to_string(finish);
        return solve(finish_str,s,limit)-solve(start_str,s,limit);
    }
};
int main(){
    // Output: 5
    int start=1,finish=6000,limit=4;
    string s="124";
    // Output: 2
    int start2=15,finish2=215,limit2=6;
    string s2="10";
    // Output: 0
    int start3=1000,finish3=2000,limit3=4;
    string s3="3000";
    Solution sol;
    cout<<sol.numberOfPowerfulInt(start,finish,limit,s)<<endl;
    cout<<sol.numberOfPowerfulInt(start2,finish2,limit2,s2)<<endl;
    cout<<sol.numberOfPowerfulInt(start3,finish3,limit3,s3);
    return 0;
}