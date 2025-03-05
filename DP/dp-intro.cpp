// Dynamic Programming (DP) is a technique to solve optimization problems by breaking them into overlapping subproblems and solving each subproblem only once, storing the results to avoid redundant computations.
// Approaches to DP
// 1. Top-Down (Memoization): Solve the problem recursively and store results in a table to avoid recomputation.
// 2. Bottom-Up (Tabulation): Build the solution iteratively from base cases using a table.

// 1. Recursion (Exponential Time Complexity)
// Time Complexity: O(2ⁿ) (exponential)
/*#include<iostream>
using namespace std;
int fib(int n){
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}
int main(){
    cout<<fib(10);
    return 0;
}*/

// 2. Top-Down DP (Memoization)
// Time Complexity: O(n) (solves each subproblem once)
// Space Complexity: O(n) (recursion stack + DP table)
/*#include <iostream>
#include <vector>
using namespace std;
// Initialize DP table
vector<int> dp(100, -1);
int fib(int n){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fib(n-1)+fib(n-2);
}
int main(){
    cout<<fib(10)<<endl;
    return 0;
}*/

// 3. Bottom-Up DP (Tabulation)
// Time Complexity: O(n)
// Space Complexity: O(n) (DP table)
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=10;
    vector<int>dp(n+1);
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    return 0;
}*/

// 4. Optimized DP (Space-Optimized)
// Time Complexity: O(n)
// Space Complexity: O(1) (constant space)
#include<iostream>
using namespace std;
int main(){
    int n=10;
    int a=0,b=1,c=a+b;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    cout<<c;
    return 0;
}