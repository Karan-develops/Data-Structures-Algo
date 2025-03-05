// Fancy pattern-3
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter rows:";
    cin>>n;
    for(int i=0;i<n;i++){
        int cond=i<=n/2?2*i:2*(n-i-1);
        int count=1;
        cout<<"*";
        for(int j=0;j<=cond;j++){
            if(j<cond/2) cout<<count++;
            else cout<<count--;
        }
        cout<<"*"<<endl;
    }
}