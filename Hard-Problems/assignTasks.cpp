//LC - 2071 - HARD - Maximum Number of Tasks You Can Assign
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution{
    bool check(vector<int>&tasks,vector<int>&workers,int pills,int strength,int mid){
        int pillsUsed=0;
        multiset<int>st(begin(workers),begin(workers)+mid);

        for(int i=mid-1;i>=0;i--){
            int rqrd=tasks[i];
            auto it=prev(st.end());

            if(*it>=rqrd){
                st.erase(it);
            } else if(pillsUsed>=pills){
                return false;
            } else{
                auto weakestWorkerIt=st.lower_bound(rqrd-strength);
                if(weakestWorkerIt==st.end()){
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }
        return true;
    }
    public:
    int maxTaskAssign(vector<int>&tasks,vector<int>&workers,int pills,int strength){
        int m=tasks.size(),n=workers.size();

        sort(begin(tasks),end(tasks));
        sort(begin(workers),end(workers));

        int ans=0;
        int l=0,r=min(m,n);

        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(tasks,workers,pills,strength,mid)){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 3
    vector<int>tasks={3,2,1},workers={0,3,3};
    int pills=1,strength=1;
    // Output: 1
    vector<int>tasks2={5,4},workers2={0,0,0};
    int pills2=1,strength2=5;
    // Output: 2
    vector<int>tasks3={10,15,30},workers3={0,10,10,10,10};
    int pills3=3,strength3=10;
    Solution sol;
    cout<<sol.maxTaskAssign(tasks,workers,pills,strength)<<endl;
    cout<<sol.maxTaskAssign(tasks2,workers2,pills2,strength2)<<endl;
    cout<<sol.maxTaskAssign(tasks3,workers3,pills3,strength3);
    return 0;
}