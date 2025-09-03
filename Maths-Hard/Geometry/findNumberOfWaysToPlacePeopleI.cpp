// LC - 3025 - Medium - Find the Number of Ways to Place People I
// 2 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 1 - Brute Force
int numberOfPairs(vector<vector<int>>&points){
    int n=points.size();
    int ans=0;

    for(int i=0;i<n;i++){
        // A Point (Upper)
        int x1=points[i][0];
        int y1=points[i][1];

        for(int j=0;j<n;j++){
            if(i==j) continue;
            
            // B Point (Lower)
            int x2=points[j][0];
            int y2=points[j][1];

            // Condition: (x1, y1) must be upper-left of (x2, y2)
            if(x1<=x2 && y1>=y2){
                bool hasPointInside=false;

                // Check if some point lies inside or on the rectangle
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;

                    int x3=points[k][0];
                    int y3=points[k][1];

                    if(x3>=x1 && x3<=x2 && y3<=y1 && y3>=y2){
                        hasPointInside=true;
                        break;
                    }
                }
                if(!hasPointInside) ans++;
            }
        }
    }
    return ans;
}
// Approach 2 - Sorting
int numberOfPairs(vector<vector<int>>&points){
    int n=points.size();

    // Sort: x ascending, if x same then sort as y descending
    auto lambda=[](vector<int>&point1,vector<int>&point2){
        if(point1[0]==point2[0]){
            return point1[1]>point2[1];
        }
        return point1[0]<point2[0];
    };

    sort(begin(points),end(points),lambda);

    int ans=0;

    for(int i=0;i<n;i++){
        // A Point (Upper)
        int x1=points[i][0];
        int y1=points[i][1];

        int bestY=INT_MIN;

        for(int j=i+1;j<n;j++){
            // B Point (Lower)
            int x2=points[j][0];
            int y2=points[j][1];

            // Condition: (x2, y2) must be above (x1, y1)
            if(y2>y1){ //not lower right
                continue;
            }

            if(y2>bestY){
                ans++;
                bestY=y2;
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