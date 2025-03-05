#include<iostream>
#include<cmath>
using namespace std;
int decToBin(int n){
    int binaryNo=0;
    int i=0;
    while(n>0){
        int bit=n%2;
        binaryNo=bit*pow(10,i++)+binaryNo;
        n=n/2;
    }
    return binaryNo;
}
int main(){
    short n;
    cout<<"Enter any decimal number:";
    cin>>n;
    int sol=decToBin(n);
    cout<<"The binary representation of "<<n<<" is: "<<sol;
    return 0;
}