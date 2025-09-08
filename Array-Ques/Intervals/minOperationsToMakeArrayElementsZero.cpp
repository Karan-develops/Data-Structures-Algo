// LC - 3495 - HARD - Minimum Operations to Make Array Elements Zero
#include<iostream>
#include<vector>
using namespace std;
class Interval{
    long long solve(int l,int r){
        // L, R
        // 1 to 3 : 1 steps
        // 4 to 15 : 2 steps

        long long L=1; // R = 4*L-1
        long long S=1;

        long long steps=0;

        while(L<=r){
            long long R=4*L -1;

            long long start=max(L,(long long)l);
            long long end  =min(R,(long long)r);

            if(start<=end){
                steps+=(end-start+1)*S;
            }

            S+=1;
            L*=4;
        }
        return steps;
    }
    public:
    long long minOperations(vector<vector<int>>&queries){
        long long ans=0;

        for(auto &vec:queries){
            int l=vec[0];
            int r=vec[1];

            long long steps=solve(l,r);

            ans+=(steps+1)/2;
        }
        return ans;
    }
};
int main(){
    // Output: 3
    vector<vector<int>>queries={{1,2},{2,4}};
    // Output: 4
    vector<vector<int>>queries2={{2,6}};
    
    Interval sol;
    cout<<sol.minOperations(queries)<<endl;
    cout<<sol.minOperations(queries2);
    return 0;
}