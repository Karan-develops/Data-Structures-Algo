// LC - 3304 - Easy - Find the K-th Character in String Game I
#include<iostream>
using namespace std;
char kthCharacter(int k){
    return 'a'+__builtin_popcount(k-1);
}
int main(){
    // Output: "b"
    int k=5;
    // Output: "c"
    int k2=10;
    cout<<kthCharacter(k)<<endl;
    cout<<kthCharacter(k2);
    return 0;
}