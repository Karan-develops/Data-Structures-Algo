// LC - 587 - HARD - Erect the Fence
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
class Maths{
    int findEquationValue(pair<int,int>&P1,pair<int,int>&P2,pair<int,int>P3){
        int x1=P1.first;
        int x2=P2.first;
        int x3=P3.first;
        
        int y1=P1.second;
        int y2=P2.second;
        int y3=P3.second;

        return (y3-y2)*(x2-x1)-(y2-y1)*(x3-x2);
    }
    public:
    vector<vector<int>> outerTrees(vector<vector<int>>&trees){
        sort(begin(trees),end(trees));
        
        deque<pair<int,int>>upper,lower;
        vector<vector<int>>ans;
        
        for(auto &point:trees){
            int l=lower.size();
            int u=upper.size();
            
            while(l>=2 && findEquationValue(lower[l-2],lower[l-1],{point[0],point[1]})<0){
                l--;
                lower.pop_back();
            }
            
            while(u>=2 && findEquationValue(upper[u-2],upper[u-1],{point[0],point[1]})>0){
                u--;
                upper.pop_back();
            }
            
            upper.push_back({point[0],point[1]});
            lower.push_back({point[0],point[1]});
        }
        
        set<pair<int,int>>st;
        for(auto &point:upper){
            st.insert(point);
        }
        
        for(auto &point:lower){
            st.insert(point);
        }
        
        for(auto &point:st){
            ans.push_back({point.first, point.second});
        }
        
        return ans;
    }
};
int main(){
    // Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
    vector<vector<int>>trees={{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    // Output: [[4,2],[2,2],[1,2]]
    vector<vector<int>>trees2={{1,2},{2,2},{4,2}};
    return 0;
}