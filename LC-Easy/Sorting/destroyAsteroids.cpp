// LC - 2126 - Medium - Destroying Asteroids
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool asteroidsDestroyed(int mass,vector<int>&asteroids){
    sort(begin(asteroids),end(asteroids));
    
    long long M=mass;

    for(int &i:asteroids){
        if(i>M) return false;
        M+=i;
    }
    return true;
}
int main(){
    // Output: true
    int mass=10;
    vector<int>asteroids={3,9,19,5,21};
    // Output: false
    int mass2=5;
    vector<int>asteroids2={4,9,23,4};
    cout<<asteroidsDestroyed(mass,asteroids)<<endl;
    cout<<asteroidsDestroyed(mass2,asteroids2);
    return 0;
}