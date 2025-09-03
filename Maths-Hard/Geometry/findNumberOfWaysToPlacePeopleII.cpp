// LC - 3027 - HARD - Find the Number of Ways to Place People II
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numberOfPairs(vector<vector<int>>&points){
    int n=points.size();
    int ans=0;

    auto lambda=[&](const auto &vec1,const auto &vec2){
        if(vec1[0]==vec2[0]) return vec1[1]>vec2[1];

        return vec1[0]<vec2[0];
    };

    sort(begin(points),end(points),lambda);

    for(int i=0;i<n;i++){
        int temp=INT_MIN;

        for(int j=i+1;j<n;j++){
            int y=points[j][1];

            if(temp<y && y<=points[i][1]){
                ans++;
                temp=y;
                if(temp==points[i][1]) break;
            }
        }
    }
    return ans;
}
int main(){
    // Output: 0
    vector<vector<int>>points={{1,1},{2,2},{3,3}};
    // Output: 2
    vector<vector<int>>points2={{6,2},{4,4},{2,6}};
    // Output: 2
    vector<vector<int>>points3={{3,1},{1,3},{1,1}};
    cout<<numberOfPairs(points)<<endl;
    cout<<numberOfPairs(points2)<<endl;
    cout<<numberOfPairs(points3);
    return 0;
}