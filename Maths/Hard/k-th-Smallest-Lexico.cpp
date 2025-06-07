// LC - 440 - HARD - K-th Smallest in Lexicographical Order
#include<iostream>
using namespace std;
class K_th{
    int Count(long curr,long next,int n){
        int countNum=0;

        while(curr<=n){
            countNum+=(next-curr);

            curr*=10;
            next*=10;

            next=min(next,long(n+1));
        }
        return countNum;
    }
    public:
    int findKthNumber(int n, int k){
        int curr=1;
        k-=1; // Since we start from the first number (1), we need k-1 more numbers

        while(k>0){
            int count=Count(curr,curr+1,n);

            if(count<=k){
                curr++;
                k-=count;
            } else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};
int main(){
    // Output: 10
    int n=13,k=2;
    // Output: 1
    int n2=1,k2=1;
    
    K_th sol;
    cout<<sol.findKthNumber(n,k)<<endl;
    cout<<sol.findKthNumber(n2,k2);
    return 0;
}