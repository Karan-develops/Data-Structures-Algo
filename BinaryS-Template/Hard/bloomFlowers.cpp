// LC - 2251 - HARD - Number of Flowers in Full Bloom
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> fullBloomFlowers(vector<vector<int>>&flowers,vector<int>&people){
    int m=flowers.size();
    int n=people.size();

    vector<int>start_time(m);
    vector<int>end_time(m);

    for(int i=0;i<m;i++){
        start_time[i]=flowers[i][0];
        end_time[i]=flowers[i][1];
    }

    sort(begin(start_time),end(start_time));
    sort(begin(end_time),end(end_time));

    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int already_bloomed=upper_bound(begin(start_time),end(start_time),people[i])
        -begin(start_time);
        int already_died=lower_bound(begin(end_time),end(end_time),people[i])
        -begin(end_time);

        ans[i]=already_bloomed-already_died;
    }
    return ans;
}
int main(){
    // Output: [1,2,2,2]
    vector<vector<int>>flowers={{1,6},{3,7},{9,12},{4,13}};
    vector<int>people={2,3,7,11};
    // Output: [2,2,1]
    vector<vector<int>>flowers2={{1,10},{3,3}};
    vector<int>people2={3,3,2};
    return 0;
}