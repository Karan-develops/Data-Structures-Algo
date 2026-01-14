// LC - 3454 - HARD - Separate Squares II
#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    public:
    double separateSquares(vector<vector<int>>&squares){

    }
};
int main(){
    // Output: 1.00000
    vector<vector<int>>squares={{0,0,1},{2,2,1}};
    // Output: 1.00000
    vector<vector<int>>squares2={{0,0,2},{1,1,1}};

    BinarySearch sol;
    cout<<sol.separateSquares(squares)<<endl;
    cout<<sol.separateSquares(squares2);
    return 0;
}