// LC - 779 - Medium - K-th Symbol in Grammar
#include<iostream>
#include<math.h>
using namespace std;
/*
0
01
0110
01101001
*/
int kthGrammar(int n,int k){
    if(k==1 && n==1) return 0;

    int length=pow(2,n-1);
    int mid=length/2;

    if(k>mid) return !kthGrammar(n-1,k-mid);
    return kthGrammar(n-1,k);
}
int main(){
    // Output: 0
    int n=1,k=1;
    // Output: 0
    int n2=2,k2=1;
    // Output: 1
    int n3=2,k3=2;
    cout<<kthGrammar(n,k)<<endl;
    cout<<kthGrammar(n2,k2)<<endl;
    cout<<kthGrammar(n3,k3);
    return 0;
}