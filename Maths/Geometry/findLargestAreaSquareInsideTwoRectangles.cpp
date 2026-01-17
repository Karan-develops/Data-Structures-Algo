// LC - 3047 - Medium - Find the Largest Area of Square Inside Two Rectangles
#include<iostream>
#include<vector>
using namespace std;
long long largestSquareArea(vector<vector<int>>&bottomLeft,vector<vector<int>>&topRight){
    int n=bottomLeft.size();
    int maxSide=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int topRightX=min(topRight[i][0],topRight[j][0]);
            int bottomLeftX=max(bottomLeft[i][0],bottomLeft[j][0]);

            int width=topRightX-bottomLeftX;

            int topRightY=min(topRight[i][1],topRight[j][1]);
            int bottomLeftY=max(bottomLeft[i][1],bottomLeft[j][1]);

            int height=topRightY-bottomLeftY;

            int side=min(width,height);

            maxSide=max(maxSide,side);
        }
    }

    return 1LL*maxSide*maxSide;
}
int main(){
    // Output: 1
    vector<vector<int>>bottomLeft={{1,1},{2,2},{3,1}},topRight={{3,3},{4,4},{6,6}};
    // Output: 4
    vector<vector<int>>bottomLeft2={{1,1},{1,3},{1,5}},topRight2={{5,5},{5,7},{5,9}};
    // Output: 1
    vector<vector<int>>bottomLeft3={{1,1},{2,2},{1,2}},topRight3={{3,3},{4,4},{3,4}};
    // Output: 0
    vector<vector<int>>bottomLeft4={{1,1},{3,3},{3,1}},topRight4={{2,2},{4,4},{4,2}};
    cout<<largestSquareArea(bottomLeft,topRight)<<endl;
    cout<<largestSquareArea(bottomLeft2,topRight2)<<endl;
    cout<<largestSquareArea(bottomLeft3,topRight3)<<endl;
    cout<<largestSquareArea(bottomLeft4,topRight4);
    return 0;
}