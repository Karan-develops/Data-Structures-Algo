// GFG - Trail of ones
#include<iostream>
using namespace std;
int countConsec(int n){
    if(n==2) return 1;

    int first=0,second=1,third;
    int ans=1;

    for(int i=3;i<=n;i++){
        third=first+second;
        ans=ans*2+third;
        
        first=second;
        second=third;
    }
    return ans;
}
int main(){
    // Output: 1
    int n=2;
    // Output: 3
    int n2=3;
    // Output: 19
    int n3=5;
    cout<<countConsec(n)<<endl;
    cout<<countConsec(n2)<<endl;
    cout<<countConsec(n3);
    return 0;
}