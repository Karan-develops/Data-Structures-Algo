// LC - 1232 - Easy - Check If It Is a Straight Line
#include<iostream>
#include<vector>
using namespace std;
bool checkStraightLine(vector<vector<int>>&coordinates){
    int n=coordinates.size();

    // dx=x2-x1 and dy=y2-y1
    int dx=coordinates[1][0]-coordinates[0][0];
    int dy=coordinates[1][1]-coordinates[0][1];

    for(int i=2;i<n;i++){
        int dx_i=coordinates[i][0]-coordinates[0][0];
        int dy_i=coordinates[i][1]-coordinates[0][1];

        // if(dy/dx!=dy_i/dx_i) return false;
        // To handle zero denominator
        if(dy*dx_i!=dy_i*dx) return false;
    }
    return true;
}
int main(){
    // Output: true
    vector<vector<int>>coordinates={{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    // Output: false
    vector<vector<int>>coordinates2={{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    cout<<checkStraightLine(coordinates)<<endl;
    cout<<checkStraightLine(coordinates2);
    return 0;
}