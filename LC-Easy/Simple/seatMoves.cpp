// LC - 2037 - Medium - Minimum Number of Moves to Seat Everyone
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(begin(seats),end(seats));
    sort(begin(students),end(students));
    int ans=0;

    for(int i=0;i<seats.size();i++){
        ans+=abs(seats[i]-students[i]);
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>seats={3,1,5},students={2,7,4};
    // Output: 7
    vector<int>seats2={4,1,5,9},students2={1,3,2,6};
    // Output: 4
    vector<int>seats3={2,2,6,6},students3={1,3,2,6};
    cout<<minMovesToSeat(seats,students)<<endl;
    cout<<minMovesToSeat(seats2,students2)<<endl;
    cout<<minMovesToSeat(seats3,students3);
    return 0;
}