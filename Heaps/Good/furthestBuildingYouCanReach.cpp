// LC - 1642 - Medium - Furthest Building You Can Reach
// NOT ACCEPTED Using Rec + Memo (DP) --> MLE
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Heap{
    public:
    int furthestBuilding(vector<int>&heights,int bricks,int ladders){
        int n=heights.size();
    
        priority_queue<int>pq;
        
        int i=0;
        for(;i<n-1;i++){
            if(heights[i]>=heights[i+1]){
                continue;
            }
            
            int curr_diff=heights[i+1]-heights[i];

            if(curr_diff<=bricks){
                bricks-=curr_diff;
                // Using curr_diff bricks here (Push in Heap to keep track of it)
                pq.push(curr_diff);
            }
            else if(ladders>0){
                if(!pq.empty()){
                    int max_bricks_past=pq.top();

                    if(max_bricks_past>curr_diff){
                        // It means i unneccasrily used huge bricks in past. Let's get it back
                        bricks+=max_bricks_past;
                        pq.pop();

                        pq.push(curr_diff);

                        bricks-=curr_diff;
                    }
                }
                ladders--; // either used in past or present
            }
            else break;
        }
        return i;
    }
};
int main(){
    // Output: 4
    vector<int>heights={4,2,7,6,9,14,12};
    int bricks=5,ladders=1;
    // Output: 7
    vector<int>heights2={4,12,2,7,3,18,20,3,19};
    int bricks2=10,ladders2=2;
    // Output: 3
    vector<int>heights3={14,3,19,3};
    int bricks3=17,ladders3=0;

    Heap sol;
    cout<<sol.furthestBuilding(heights,bricks,ladders)<<endl;
    cout<<sol.furthestBuilding(heights2,bricks2,ladders2)<<endl;
    cout<<sol.furthestBuilding(heights3,bricks3,ladders3);
    return 0;
}