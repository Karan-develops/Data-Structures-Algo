// LC - 757 - HARD - Set Intersection Size At Least Two
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int intersectionSizeTwo(vector<vector<int>>&intervals){
    int n=intervals.size();

    auto lambda=[](auto &vec1,auto &vec2){
        if(vec1[1]!=vec2[1]) return vec1[1]<vec2[1];
        return vec1[0]>vec2[0];
    };

    sort(begin(intervals),end(intervals),lambda);

    int ans=0;
    int first=-1,second=-1;

    for(int i=0;i<n;i++){
        int l=intervals[i][0];
        int r=intervals[i][1];

        if(l<=first) continue;

        if(l>second){
            ans+=2;
            second=r;
            first=r-1;
        } else{
            ans+=1;
            first=second;
            second=r;
        }
    }
    return ans;
}
int main(){
    // Output: 5
    vector<vector<int>>intervals={{1,3},{3,7},{8,9}};
    // Output: 3
    vector<vector<int>>intervals2={{1,3},{1,4},{2,5},{3,5}};
    // Output: 5
    vector<vector<int>>intervals3={{1,2},{2,3},{2,4},{4,5}};
    cout<<intersectionSizeTwo(intervals)<<endl;
    cout<<intersectionSizeTwo(intervals2)<<endl;
    cout<<intersectionSizeTwo(intervals3);
    return 0;
}