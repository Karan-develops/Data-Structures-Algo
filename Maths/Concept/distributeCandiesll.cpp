// LC - 2929 - Medium - Distribute Candies Among Children II
// Range --> [a,b] => b-a+1
#include<iostream>
using namespace std;
long long distributeCandies(int n,int limit){
    long long ways=0;

    // Child 1
    int minCh1=max(0,n- 2*limit);
    int maxCh1=min(n,limit);

    // Fixing child1 assignment of candies
    for(int i=minCh1;i<=maxCh1;i++){
        // Candies for Child 2 and 3
        int N=n-i;

        int minCh2=max(0,N-limit);
        int maxCh2=min(N,limit);

        ways+=(maxCh2-minCh2+1);
    }
    return ways;
}
int main(){
    // Output: 3
    int n=5,limit=2;
    // Output: 10
    int n2=3,limit2=3;
    cout<<distributeCandies(n,limit)<<endl;
    cout<<distributeCandies(n2,limit2);
    return 0;
}