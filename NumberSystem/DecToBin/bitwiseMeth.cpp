#include<iostream>
#include<cmath>
using namespace std;
int decToBin(int n){
    int binaryNo=0;
    int i=0;
    while(n>0){
        int bit=(n&1);
        binaryNo=bit*pow(10,i++)+binaryNo;
        n=n>>1;
    }
    return binaryNo;
}
int main(){
    short n;
    cout<<"Enter a decimal number:";
    cin>>n;
    int ans=decToBin(n);
    cout<<"The binary representation of "<<n<<" is: "<<ans;
    return 0;
}