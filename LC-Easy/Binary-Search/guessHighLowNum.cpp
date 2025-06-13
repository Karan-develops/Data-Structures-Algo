// LC - 374 - Easy - Guess Number Higher or Lower
/*
You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
*/
#include<iostream>
#include<math.h>
using namespace std;
// Demo Function
int guess(int mid){
    return rand();
}
int guessNumber(int n){
    int l=0,r=n;

    while(l<=r){
        // Mid is our guessed Number.
        int mid=l+(r-l)/2;

        if(guess(mid)==0) return mid;
        else if(guess(mid)==1) l=mid+1;
        else r=mid-1;
    }
    return -1;
}
int main(){
    // Output: 6
    int n=10,pick=6;
    // Output: 1
    int n2=1,pick=1;
    // Output: 1
    int n3=2,pick=1;
    cout<<guessNumber(n)<<endl;
    cout<<guessNumber(n2)<<endl;
    cout<<guessNumber(n3);
    return 0;
}