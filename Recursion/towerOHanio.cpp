//T.C : O(2^n)
//S.C : O(n) - Recursion Stack Space
#include<iostream>
using namespace std;
int toh(int n,int from,int to,int aux){
    if(n==0) return 0;
    if(n==1) return 1;
    // How it Works
    // (Disk, konsi rod se uthani h,konsi rod pe daalni h, kis rod ki help se)
    int count=toh(n-1,from,aux,to);
    count++;
    // (Disk, konsi rod se uthani h,konsi rod pe daalni h, kis rod ki help se)
    count+=toh(n-1,aux,to,from);
    return count;
}
int main(){
    // OP - 3
    int x1=2;
    // OP - 7
    int x=3;
    cout<<toh(x,x,x,x);
    return 0;
}