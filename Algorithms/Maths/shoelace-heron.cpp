// Shoelace & Heron's Formula
/* Used in Qn https://github.com/Karan-develops/Data-Structures-Algo/blob/main/Maths/Concept/largestTriangleArea.cpp 
*/
#include<iostream>
#include<math.h>
using namespace std;
// Use: To find the area of a triangle when you know the lengths of all three sides.
double heron(double a,double b,double c){
    // double s=(a+b+c)/2.0;
    double s=(a+b+c)*0.5;
    
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
// Use: Area of any polygon from vertex coordinates.
double shoelace(int x1,int x2,int x3,int y1,int y2,int y3){
    double a=hypot(x2-x1,y2-y1);
    double b=hypot(x3-x2,y3-y2);
    double c=hypot(x3-x1,y3-y1);

    double shoelace=0.5*abs(x1*(y2-y3)+
                            x2*(y3-y1)+
                            x3*(y1-y2));

    return shoelace;
}
int main(){
    double a=3,b=4,c=5;
    cout<<heron(a,b,c);
    return 0;
}