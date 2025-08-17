// LC - 3648 - Medium - Minimum Sensors to Cover Grid
#include<iostream>
#include<math.h>
using namespace std;
int minSensors(int n,int m,int k){
    /* k=2 -> Sensor will cover 5 blocks so -> (2*k+1)
    . . . . .
    . . . . .
    . . S . .
    . . . . .
    . . . . .
    */
    int cover=2*k+1;

    int rows=ceil((double)n/cover);
    int cols=ceil((double)m/cover);

    return rows*cols;
}
int main(){
    // Output: 4
    int n=5,m=5,k=1;
    // Output: 1
    int n2=2,m2=2,k2=2;
    cout<<minSensors(n,m,k)<<endl;
    cout<<minSensors(n2,m2,k2);
    return 0;
}