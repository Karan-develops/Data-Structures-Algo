// LC - 1854 - Easy - Maximum Population Year
#include<iostream>
#include<vector>
using namespace std;
int maximumPopulation(vector<vector<int>>& logs) {
    vector<int>diff(101,0);

    for(auto &vec:logs){
        int l=vec[0]-1950;
        int r=vec[1]-1950;

        diff[l]++;
        diff[r]--;
    }
    int ans=1950,maxPop=diff[0];
    for(int i=1;i<101;i++){
        diff[i]+=diff[i-1];
        if(diff[i]>maxPop){
            maxPop=diff[i];
            ans=1950+i;
        }
    }
    return ans;
}
int main(){
    // Output: 1993
    vector<vector<int>>logs={{1993,1999},{2000,2010}};
    // Output: 1960
    vector<vector<int>>logs2={{1950,1961},{1960,1971},{1970,1981}};
    cout<<maximumPopulation(logs)<<endl;
    cout<<maximumPopulation(logs2);
    return 0;
}