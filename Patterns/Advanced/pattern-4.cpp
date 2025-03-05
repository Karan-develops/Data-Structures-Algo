// Fancy Pattern-2
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter rows:";
    cin>>n;
    int count=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j!=i) cout<<count++<<"*";
            else cout<<count++;
        }
        cout<<endl;
    }
    int start=count-n;
    for(int i=0;i<n;i++){
        int k=start;
        for(int j=0;j<n-i;j++){
            if(j!=n-i-1) cout<<k++<<"*";
            else cout<<k++;
        }
        start=start-(n-i-1);
        cout<<endl;
    }
}