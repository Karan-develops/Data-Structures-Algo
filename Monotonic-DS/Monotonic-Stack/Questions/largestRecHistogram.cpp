// LC - 84 - HARD - Largest Rectangle in Histogram
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class MonotonicStack{
    int n;
    vector<int> prevSmaller(vector<int>&h){
        stack<int>st;
        vector<int>prev(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            prev[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return prev;
    }
    vector<int> nextSmaller(vector<int>&h){
        stack<int>st;
        vector<int>next(n);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            next[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return next;
    }
    public:
    int largestRectangleArea(vector<int>&heights){
        n=heights.size();

        vector<int>prev=prevSmaller(heights);
        vector<int>next=nextSmaller(heights);

        int maxArea=0;

        for(int i=0;i<n;i++){
            int h=heights[i];
            int w=next[i]-prev[i]-1;

            maxArea=max(maxArea,h*w);
        }
        return maxArea;
    }
};
int main(){
    // Output: 10
    vector<int>heights={2,1,5,6,2,3};
    // Output: 4
    vector<int>heights2={2,4};

    MonotonicStack sol;
    cout<<sol.largestRectangleArea(heights)<<endl;
    cout<<sol.largestRectangleArea(heights2);
    return 0;
}