// Check if a number is prime
#include<iostream>
using namespace std;
bool checkPrime(int num){
    if(num<2) return false;
    if(num%2==0) return num==2;

    for(int i=3;i*i<=num;i+=2){
        if(num%i==0) return false;
    }
    return true;
}
int main(){
    int n1=15;
    int n2=17;
    cout<<checkPrime(n1)<<endl;
    cout<<checkPrime(n2);
    return 0;
}