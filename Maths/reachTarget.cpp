// LC - 2139 - Medium - Minimum Moves to Reach Target Score
#include<iostream>
using namespace std;
int minMoves(int target, int maxDoubles) {
    int ans=0;
    while(target>1 && maxDoubles>0){
        if(!(target&1)){
            target/=2;
            maxDoubles--;
        }
        else target--;
        ans++;
    }
    return ans+(target-1);
}
int main(){
    // Output: 4
    int target=5,maxDoubles=0;
    // Output: 7
    int target2=19,maxDoubles2=2;
    // Output: 4
    int target3=10,maxDoubles3=4;
    cout<<minMoves(target,maxDoubles)<<endl;
    cout<<minMoves(target2,maxDoubles2)<<endl;
    cout<<minMoves(target3,maxDoubles3);
    return 0;
}