// LC - 575 - Easy - Distribute Candies
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int distributeCandies(vector<int>&candyType){
    int half=candyType.size()/2;
    
    unordered_set<int>st;

    for(int &i:candyType){
        if(st.size()==half) return st.size();
        st.insert(i);
    }
    return st.size();
}
int main(){
    // Output: 3
    vector<int>candyType={1,1,2,2,3,3};
    // Output: 2
    vector<int>candyType2={1,1,2,3};
    // Output: 1
    vector<int>candyType3={6,6,6,6};
    cout<<distributeCandies(candyType)<<endl;
    cout<<distributeCandies(candyType2)<<endl;
    cout<<distributeCandies(candyType3);
    return 0;
}