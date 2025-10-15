// LC - 3539 - HARD - Find Sum of Array Product of Magical Sequences
// You Got This
// 3 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
// Approach 1 - Just Recursion without Memo - TLE
class Rec_DP{
    int N,M,K;
    const int MOD=1e9+7;
    typedef long long ll;
    ll solve(vector<int>&nums,ll count,int sum){
        if(count==M){
            if(__builtin_popcountll(sum)==K){
                return 1;
            }
            return 0;
        }

        ll totalSum=0;

        for(int i=0;i<N;i++){
            // 1<<i ==> pow(2,i);
            ll newSum=sum+(1<<i);

            ll prod=(nums[i]*solve(nums,count+1,newSum))%MOD;

            totalSum=(totalSum+prod)%MOD;
        }

        return totalSum;
    }
    public:
    int magicalSum(int m,int k,vector<int>&nums){
        N=nums.size();
        M=m,K=k;

        return (int)(solve(nums,0,0)%MOD);
    }
};
// Approach 2 - Rec+Memo - TLE
class DP{
    int N,M,K;
    const int MOD=1e9+7;
    typedef long long ll;
    unordered_map<string,int>mp;
    ll solve(vector<int>&nums,int count,ll sum){
        if(count==M){
            if(__builtin_popcountll(sum)==K){
                return 1;
            }
            return 0;
        }

        string key=to_string(count)+"_"+to_string(sum);

        if(mp.count(key)){
            return mp[key];
        }

        ll totalSum=0;

        for(int i=0;i<N;i++){
            // 1<<i ==> pow(2,i);
            ll newSum=sum+(1LL<<i);

            ll prod=(nums[i]*solve(nums,count+1,newSum))%MOD;

            totalSum=(totalSum+prod)%MOD;
        }

        return mp[key]=totalSum;
    }
    public:
    int magicalSum(int m,int k,vector<int>&nums){
        N=nums.size();
        M=m,K=k;
        mp.clear();

        return (int)(solve(nums,0,0)%MOD);
    }
};
// Approach 3 - Optimized - ACCEPTED
class DigitDP{
    int N;
    const int MOD=1e9+7;
    typedef long long ll;
    vector<ll>fact;
    vector<ll>invFact;
    map<tuple<ll,int,int,int>,ll>memo;
    ll findPower(ll a,ll b){
        if(b==0) return 1;

        ll half=findPower(a,b/2);
        ll ans=(half*half)%MOD;

        if(b&1) ans=(ans*a)%MOD;

        return ans;
    }
    // nCr % MOD
    ll nCr(int n,int r){
        // nCr =  n! * inv(r!) * inv(n-r)!
        return (((fact[n]*invFact[r])%MOD)*invFact[n-r])%MOD;
    }
    ll solve(vector<int>&nums,int m,int k,ll binarySum,int i){
        if(m==0 && __builtin_popcountll(binarySum)==k){
            return 1;
        }
        if(m==0 || i>=N){
            return 0;
        }

        auto key=make_tuple(binarySum,m,k,i);

        if(memo.count(key)){
            return memo[key];
        }

        ll totalSum=0;

        // skip
        totalSum=(totalSum+solve(nums,m,k-(binarySum&1),(binarySum>>1),i+1))%MOD;

        // Take index i freq times
        for(int freq=1;freq<=m;freq++){
            ll newBinarySum=binarySum+freq;

            ll prod=solve(nums,m-freq,k-(newBinarySum&1),(newBinarySum>>1),i+1);

            prod=(findPower(nums[i],freq)%MOD*prod%MOD)%MOD;

            prod=(prod*nCr(m,freq))%MOD;

            totalSum=(totalSum+prod)%MOD;
        }

        return memo[key]=totalSum;
    }
    public:
    int magicalSum(int m,int k,vector<int>&nums){
        N=nums.size();
        fact.assign(m+1,1);
        invFact.assign(m+1,1);
        memo.clear();
        
        for(int i=2;i<=m;i++){
            fact[i]=(fact[i-1]*i)%MOD;
        }
        for(int i=0;i<=m;i++){
            invFact[i]=findPower(fact[i],MOD-2);
        }

        return (int)(solve(nums,m,k,0,0)%MOD);
    }
};
int main(){
    // Output: 991600007
    int m=5,k=5;
    vector<int>nums={1,10,100,10000,1000000};
    // Output: 170
    int m2=2,k2=2;
    vector<int>nums2={5,4,3,2,1};
    // Output: 28
    int m3=1,k3=1;
    vector<int>nums3={28};

    DigitDP sol;
    cout<<sol.magicalSum(m,k,nums)<<endl;
    cout<<sol.magicalSum(m2,k2,nums2)<<endl;
    cout<<sol.magicalSum(m3,k3,nums3);
    return 0;
}