// LC - 1545 - Medium - Find Kth Bit in Nth Binary String
#include<iostream>
#include<math.h>
using namespace std;
class Recursion{
    public:
    char findKthBit(int n,int k){
        if(n==1) return '0';

        // pow(2,n)-1
        int len=(1<<n)-1;

        if(k<ceil(len/2.0)) return findKthBit(n-1,k);
        else if(k==ceil(len/2.0)) return '1';
        
        // Reverse
        char ch=findKthBit(n-1,len-k+1);
        // Flip
        return ch=='0'?'1':'0';
    }
};
int main(){
    // Output: "0"
    int n=3,k=1;
    // Output: "1"
    int n2=4,k2=11;

    Recursion sol;
    cout<<sol.findKthBit(n,k)<<endl;
    cout<<sol.findKthBit(n2,k2);
    return 0;
}