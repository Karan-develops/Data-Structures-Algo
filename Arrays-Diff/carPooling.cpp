// LC - 1094 - Medium - Car Pooling
#include<iostream>
#include<vector>
using namespace std;
bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int>diff(1001,0);
    
    for(auto &vec:trips){
        int passangers=vec[0];
        int start_time=vec[1];
        int end_time=vec[2];

        diff[start_time]+=passangers;
        diff[end_time]-=passangers;
    }

    int total=0;
    for(int &i:diff){
        total+=i;
        if(total>capacity) return false;
    }
    return true;
}
int main(){
    // Output: false
    vector<vector<int>>trips={{2,1,5},{3,3,7}};
    int capacity=4;
    // Output: true
    vector<vector<int>>trips2={{2,1,5},{3,3,7}};
    int capacity2=5;
    cout<<carPooling(trips,capacity)<<endl;
    cout<<carPooling(trips2,capacity2);
    return 0;
}