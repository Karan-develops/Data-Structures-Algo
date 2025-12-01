// LC - 717 - Easy - 1-bit and 2-bit Characters
#include<iostream>
#include<vector>
using namespace std;
bool isOneBitCharacter(vector<int>&bits){
    int n=bits.size();
    int i=0;

    while(i<n-1){
        i+=(bits[i]==1)?2:1;
    }

    return i==n-1;
}
int main(){
    // Output: true
    vector<int>bits={1,0,0};
    // Output: false
    vector<int>bits2={1,1,1,0};
    cout<<isOneBitCharacter(bits)<<endl;
    cout<<isOneBitCharacter(bits2);
    return 0;
}