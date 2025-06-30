// LC - 85 - HARD - Maximal Rectangle
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class MonotonicStack{
    int N;
    vector<int> prevSmaller(vector<int>&h){
        vector<int>prev(N);
        stack<int>st;

        for(int i=0;i<N;i++){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            prev[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return prev;
    }
    vector<int> nextSmaller(vector<int>&h){
        vector<int>next(N);
        stack<int>st;

        for(int i=N-1;i>=0;i--){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            next[i]=st.empty()?N:st.top();
            st.push(i);
        }
        return next;
    }
    int largestArea(vector<int>&heights){
        N=heights.size();
        vector<int>prev=prevSmaller(heights);
        vector<int>next=nextSmaller(heights);

        int maxArea=0;
        
        for(int i=0;i<N;i++){
            int h=heights[i];
            int w=next[i]-prev[i]-1;

            maxArea=max(maxArea,h*w);
        }
        return maxArea;
    }
    public:
    int maximalRectangle(vector<vector<char>>&matrix){
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>v;

        for(int i=0;i<m;i++){
            vector<int>t;
            for(int j=0;j<n;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }

        int maxArea=largestArea(v[0]);

        for(int i=1;i<m;++i){
            for(int j=0;j<n;j++){
                // Let's update current row with previous values
                if(v[i][j]) v[i][j]+=v[i-1][j];
                else v[i][j]=0;
            }
            maxArea=max(maxArea,largestArea(v[i]));
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

    MonotonicStack sol;
    cout<<sol.maximalRectangle(matrix)<<endl;
    cout<<sol.maximalRectangle(matrix2)<<endl;
    cout<<sol.maximalRectangle(matrix3);
    return 0;
}