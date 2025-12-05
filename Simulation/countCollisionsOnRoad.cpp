// LC - 2211 - Medium - Count Collisions on a Road
#include<iostream>
#include<vector>
using namespace std;
int countCollisions(string directions){
    int n=directions.length();

    // left boundary
    int i=0;
    while(i<n && directions[i]=='L'){
        i++;
    }

    int j=n-1;
    while(j>=0 && directions[j]=='R'){
        j--;
    }

    int collisions=0;
    while(i<=j){
        if(directions[i]!='S'){
            collisions++;
        }
        i++;
    }

    return collisions;
}
int main(){
    // Output: 5
    string directions="RLRSLL";
    // Output: 0
    string directions2="LLRR";
    cout<<countCollisions(directions)<<endl;
    cout<<countCollisions(directions2);
    return 0;
}