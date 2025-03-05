// Numeric Full Pyramid
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter rows:";
    cin>>n;
    for(int i=0;i<n;i++){
        short k=i+1;
        for(int j=0;j<2*n-1;j++){
            if(j<n-i-1 || j>n+i-1) cout<<" ";
            else if(j>=n-i+1) cout<<k--;
            else cout<<k++;
        }
        cout<<endl;
    }
}