// Hollow diamond
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter rows:";
    cin>>n;
    cout<<"Here's the pattern"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(j<n-i-1) cout<<" ";
            else if(j==n-i-1 || j==n+i-1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(j==i || j==2*n-i-2) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}