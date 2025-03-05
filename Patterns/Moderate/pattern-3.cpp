// Hollow Pyramid
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter row:";
    cin>>n;
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<2*n-1;j++){
            if(j<n-i-1){
                cout<<" ";
            }
            else if(k==n-i-1 || k==n+i-1 || i==n-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
            k++;
        }
        cout<<endl;
    }
}