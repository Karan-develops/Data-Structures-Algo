// LC - 3021 - Medium - Alice and Bob Playing Flower Game
#include<iostream>
using namespace std;
long long flowerGame(int n,int m){
    /* Game should always end on odd to make alice win so m*n means all possibilities
        and half of them will have odd*/
    return (1LL*m*n)/2;
}
int main(){
    // Output: 3
    int n=3,m=2;
    // Output: 0
    int n2=1,m2=1;
    cout<<flowerGame(n,m)<<endl;
    cout<<flowerGame(n2,m2);
    return 0;
}