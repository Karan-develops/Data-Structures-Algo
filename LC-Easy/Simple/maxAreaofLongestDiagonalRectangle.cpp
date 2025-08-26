// LC - 3000 - Easy - Maximum Area of Longest Diagonal Rectangle
#include<iostream>
#include<vector>
using namespace std;
int areaOfMaxDiagonal(vector<vector<int>>&dimensions){
    int maxArea=0;
    int maxDiagonal=0;

    for(auto &vec:dimensions){
        int l=vec[0];
        int w=vec[1];
        int area=l*w;
        int diagonal=l*l+w*w;

        if(diagonal>maxDiagonal){
            maxDiagonal=diagonal;
            maxArea=area;
        } else if(diagonal==maxDiagonal){
            maxArea=max(maxArea,area);
        }
    }
    return maxArea;
}
int main(){
    // Output: 48
    vector<vector<int>>dimensions={{9,3},{8,6}};
    // Output: 12
    vector<vector<int>>dimensions2={{3,4},{4,3}};
    cout<<areaOfMaxDiagonal(dimensions)<<endl;
    cout<<areaOfMaxDiagonal(dimensions2);
    return 0;
}