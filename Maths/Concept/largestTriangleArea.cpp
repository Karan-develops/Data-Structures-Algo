// LC - 812 - Easy - Largest Triangle Area
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
double largestTriangleArea(vector<vector<int>>&points){
    int n=points.size();
    double ans=0.0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int x3=points[k][0];
                int y3=points[k][1];

                double a=hypot(x2-x1,y2-y1);
                double b=hypot(x3-x2,y3-y2);
                double c=hypot(x3-x1,y3-y1);

                double s=(a+b+c)*0.5;

                double heron=sqrt(s*(s-a)*(s-b)*(s-c));

                double shoelace=0.5*abs(x1*(y2-y3)+
                                        x2*(y3-y1)+
                                        x3*(y1-y2));

                // Use either heron's OR shoelace
                ans=max({ans,heron,shoelace});
            }
        }
    }
    return ans;
}
int main(){
    // Output: 2.00000
    vector<vector<int>>points={{0,0},{0,1},{1,0},{0,2},{2,0}};
    // Output: 0.50000
    vector<vector<int>>points2={{1,0},{0,0},{0,1}};
    cout<<largestTriangleArea(points)<<endl;
    cout<<largestTriangleArea(points2);
    return 0;
}