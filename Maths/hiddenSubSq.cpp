// LC - 2145 - Medium - Count the Hidden Sequences
#include<iostream>
#include<vector>
using namespace std;
int numberOfArrays(vector<int>&differences,int lower,int upper){
    int curr=0;
    int minVal=0;
    int maxVal=0;
    for(int &d:differences){
        curr+=d;
        minVal=min(minVal,curr);
        maxVal=max(maxVal,curr);

        if((upper-maxVal)-(lower-minVal)+1<=0){
            return 0;
        }
    }
    return (upper-maxVal)-(lower-minVal)+1;
}
int main(){
    // Output: 2
    vector<int>differences={1,-3,4};
    int lower=1,upper=6;
    // Output: 4
    vector<int>differences2={3,-4,5,1,-2};
    int lower2=-4,upper2=5;
    // Output: 0
    vector<int>differences3={4,-7,2};
    int lower3=3,upper3=6;
    cout<<numberOfArrays(differences,lower,upper)<<endl;
    cout<<numberOfArrays(differences2,lower2,upper2)<<endl;
    cout<<numberOfArrays(differences3,lower3,upper3);
    return 0;
}