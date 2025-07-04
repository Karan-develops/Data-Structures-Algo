// LC - 3333 - HARD - Find the Original Typed String II
// 3 Approaches - Top Down - Bottom Up - Optimized Bottom Up
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Top-Down (Rec+Memo) - TLE
class TopDown{
    const int M=1e9+7;
    vector<vector<int>>dp;
    long long solve(vector<int>&freq,int k,int i,int count){
        if(i>=freq.size()){
            // Found Invalid String
            if(count<k) return 1;
            return 0;
        }

        if(dp[i][count]!=-1) return dp[i][count];

        long long ans=0;

        for(int take=1;take<=freq[i];take++){
            if(count+take<k){
                ans=(ans+solve(freq,k,i+1,count+take))%M;
            } else{
                break;
            }
        }
        return dp[i][count]=ans;
    }
    public:
    int possibleStringCount(string word,int k){
        if(word.length()<k){
            return 0;
        }

        vector<int>freq;
        int count=1;
        for(int i=1;i<word.length();i++){
            if(word[i]==word[i-1]){
                count++;
            } else{
                freq.push_back(count);
                count=1;
            }
        }
        freq.push_back(count);

        // Total possible strings ( Product of All freqs )
        long long P=1;
        for(int &f:freq){
            P=(P*f)%M;
        }

        if(freq.size()>=k){
            return P;
        }

        int n=freq.size();
        // invalid krne k lie count should be less than k < k
        dp.assign(n+1,vector<int>(k+1,-1));

        // Solve fn invalid string count krega
        long long invalidCount=solve(freq,k,0,0);

        // Total - invalid => valid
        return (P-invalidCount+M)%M; // +M to avoid any errors due to -ve numbers
    }
};
// Approach 2 - Bottom Up - TLE
class BottomUp{
    const int M=1e9+7;
    public:
    int possibleStringCount(string word,int k){
        if(word.length()<k){
            return 0;
        }

        vector<int>freq;
        int count=1;
        for(int i=1;i<word.length();i++){
            if(word[i]==word[i-1]){
                count++;
            } else{
                freq.push_back(count);
                count=1;
            }
        }
        freq.push_back(count);

        // Total possible strings ( Product of All freqs )
        long long P=1;
        for(int &f:freq){
            P=(P*f)%M;
        }

        if(freq.size()>=k){
            return P;
        }

        int n=freq.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        
        // Last Row toh 1 hi hogi kyuki nth row count is valid
        for(int count=k-1;count>=0;count--){
            dp[n][count]=1;
        }

        for(int i=n-1;i>=0;i--){
            for(int count=k-1;count>=0;count--){
                long long ans=0;

                for(int take=1;take<=freq[i];take++){
                    if(take+count<k){
                        ans=(ans+dp[i+1][count+take])%M;
                    } else{
                        break;
                    }
                }
                dp[i][count]=ans;
            }
        }

        int invalidCount=dp[0][0];

        // Total - invalid => valid
        return (P-invalidCount+M)%M; // +M to avoid any errors due to -ve numbers
    }
};
// Approach 3 - Optimized Bottom Up - ACCEPTED
class Optimized{
    const int M=1e9+7;
    public:
    int possibleStringCount(string word,int k){
        if(word.length()<k){
            return 0;
        }

        vector<int>freq;
        int count=1;
        for(int i=1;i<word.length();i++){
            if(word[i]==word[i-1]){
                count++;
            } else{
                freq.push_back(count);
                count=1;
            }
        }
        freq.push_back(count);

        // Total possible strings ( Product of All freqs )
        long long P=1;
        for(int &f:freq){
            P=(P*f)%M;
        }

        if(freq.size()>=k){
            return P;
        }

        int n=freq.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        
        // Last Row toh 1 hi hogi kyuki nth row count is valid
        for(int count=k-1;count>=0;count--){
            dp[n][count]=1;
        }

        for(int i=n-1;i>=0;i--){
            vector<int>prefix(k+1,0);

            for(int h=1;h<=k;h++){
                prefix[h]=(prefix[h-1]+dp[i+1][h-1])%M;
            }

            for(int count=k-1;count>=0;count--){
                int l=count+1;
                int r=count+freq[i];

                if(r+1>k){
                    r=k-1;
                }

                if(l<=r){
                    dp[i][count]=(prefix[r+1]-prefix[l]+M)%M;
                }
            }
        }

        int invalidCount=dp[0][0];

        // Total - invalid => valid
        return (P-invalidCount+M)%M; // +M to avoid any errors due to -ve numbers
    }
};
int main(){
    // Output: 5
    string word="aabbccdd";
    int k=7;
    // Output: 1
    string word2="aabbccdd";
    int k2=8;
    // Output: 8
    string word3="aaabbb";
    int k3=3;

    TopDown td;
    cout<<td.possibleStringCount(word,k)<<endl;
    BottomUp bu;
    cout<<bu.possibleStringCount(word2,k2)<<endl;
    Optimized op;
    cout<<op.possibleStringCount(word3,k3);
    return 0;
}