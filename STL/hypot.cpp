// Hypot
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    // 1. Instead of using sqrt(x*x + y*y)
    // Use hypot(x,y)

    // OP - 5
    double a=3.0,b=4.0;
    double ans=hypot(a,b);
    cout<<ans;

    // 2. Distance Between 2 points (x1,y1) & (x2,y2)
    // Instead of using ((x2-x1)^2 + (y2-y1)^2)
    // Use hypot(x2-x1,y2-y1)
    
    // 2. 3D Plane
    // Instead of using ((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2)
    // Use hypot(x2-x1,y2-y1,z2-z1)
    return 0;
}