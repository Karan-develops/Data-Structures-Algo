#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter rows:";
    cin>>n;
    cout<<"Here's the pattern"<<endl;
    for(int i=0;i<n;i++){
        // spaces
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
            for(int k=0;k<i+1;k++){
                cout<<"* ";
            }
            cout<<endl;
    }
}