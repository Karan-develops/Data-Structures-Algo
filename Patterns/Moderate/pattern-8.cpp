// Numeric Hollow Half Pyramid
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter rows:";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(i==j || j==0 || i==n-1) cout<<j+1;
            else cout<<" ";
        }
        cout<<endl;
    }
}