// LC - 1688 - Easy - Count of Matches in Tournament
#include<iostream>
using namespace std;
int numberOfMatches(int n){
    return n-1;
}
int main(){
    // Output: 6
    int n=7;
    // Output: 13
    int n2=14;
    cout<<numberOfMatches(n)<<endl;
    cout<<numberOfMatches(n2);
    return 0;
}