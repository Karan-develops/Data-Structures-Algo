// LC - 319 - Medium - Bulb Switcher
#include<iostream>
#include<math.h>
using namespace std;
/* Reason:
Take Example: n=20
- Only number which are perfect square will remain turned ON bcoz
1) Firstly, bulb agar odd times toggle krenge toh ON rhega
2) 20 ke multiples hi 20 ko toggle kr skte h
(1,20) - (20,1)
(5,4) - (4,5)
- mtlb same number of opposite pairs honge toh even times toggle hoga
3) There will be a perfect square pair jaise (4,4) jo 4 ka multiple h.
- (4,4) ka koi opposite pair nhi h toh even times toggle hoga.
*/
int bulbSwitch(int n){
    // We can also use loop to find perfect 'sq' in range 1-n but sqrt also returns the same.
    return sqrt(n);
}
int main(){
    // Output: 1
    int n=3;
    // Output: 0
    int n2=0;
    // Output: 1
    int n3=1;
    cout<<bulbSwitch(n)<<endl;
    cout<<bulbSwitch(n2)<<endl;
    cout<<bulbSwitch(n3);
    return 0;
}