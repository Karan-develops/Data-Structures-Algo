// LC - 85 - HARD - Maximal Rectangle
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
    int numSize;
    vector<int> getNSL(vector<int>&nums){
        vector<int>ans(numSize);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<numSize;i++){
            while(st.top()!=-1 && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>&nums){
        vector<int>ans(numSize);
        stack<int>st;
        for(int i=numSize-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=numSize;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestArea(vector<int>&heights){
        numSize=heights.size();
        vector<int>NSL=getNSL(heights);
        vector<int>NSR=getNSR(heights);
        int maxArea=0;
        
        for(int i=0;i<numSize;i++){
            int h=heights[i];
            int w=NSR[i]-NSL[i]-1;
            maxArea=max(maxArea,h*w);
        }
        return maxArea;
    }
    public:
    int maximalRectangle(vector<vector<char>>&matrix){
        int m=matrix.size(),n=matrix[0].size();
        vector<int>heights(n,0);
        
        // Since the matrix is in char convert it to int
        for(int i=0;i<m;i++){
            heights[i]=(matrix[0][i]=='1')?1:0;
        }
        
        // Get answer of one row
        int maxArea=largestArea(heights);
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') heights[j]=0;
                else heights[j]+=1;
            }
            maxArea=max(maxArea,largestArea(heights));
        }
        return maxArea;
    }
};
int main(){
    // Output: 6
    vector<vector<char>>matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    // Output: 0
    vector<vector<char>>matrix2={{'0'}};
    // Output: 1
    vector<vector<char>>matrix3={{'1'}};
    Solution sol;
    cout<<sol.maximalRectangle(matrix);
    return 0;
}