// Numeric Hollow Pyramid
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter rows:";
    cin>>n;
    for(int i=0;i<n;i++){
        short a=1;
        for(int j=0;j<2*n-1;j++){
            if(i==n-1 && j%2==0) cout<<a++;
            else if(j==n-i-1) cout<<1;
            else if(j==n+i-1) cout<<i+1;
            else cout<<" ";
        }
        cout<<endl;
    }
}