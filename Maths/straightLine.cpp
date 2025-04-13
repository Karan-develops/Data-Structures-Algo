// LC - 1232 - Easy - Check If It Is a Straight Line
#include<iostream>
#include<vector>
using namespace std;
bool checkStraightLine(vector<vector<int>>&coordinates){
    int n=coordinates.size();
    int x0=coordinates[0][0];
    int x1=coordinates[1][0];
    int y0=coordinates[0][1];
    int y1=coordinates[1][1];
    for(int i=2;i<n;i++){
        int x=coordinates[i][0];
        int y=coordinates[i][1];
        if((x-x0)*(y1-y0) != (y-y0)*(x1-x0)) return false;
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