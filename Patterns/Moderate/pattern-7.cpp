// Alphabet Palindrome Pyramid
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter rows:";
    cin>>n;
    for(int i=0;i<n;i++){
        char c=65;
        for(int j=0;j<2*i+1;j++){
            if(j<i) cout<<c++;
            else cout<<c--;
        }
        cout<<endl;
    }
}