// LC - 881 - Medium - Boats to Save People
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numRescueBoats(vector<int>&people,int limit){
    int n=people.size();
    sort(people.begin(),people.end());

    int boats=0;
    int i=0,j=n-1;

    while(i<=j){
        if(people[i]+people[j]<=limit) i++,j--;
        else j--;
        boats++;
    }
    return boats;
}
int main(){
    // Output: 1
    vector<int>people={1,2};
    int limit=3;
    // Output: 3
    vector<int>people2={3,2,2,1};
    int limit2=3;
    // Output: 4
    vector<int>people3={3,5,3,4};
    int limit3=5;
    cout<<numRescueBoats(people,limit)<<endl;
    cout<<numRescueBoats(people2,limit2)<<endl;
    cout<<numRescueBoats(people3,limit3);
    return 0;
}