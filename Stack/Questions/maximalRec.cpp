#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> prevSmaller(vector<int>&h){
    int s=h.size();
    vector<int>prev(s);
    stack<int>st;
    st.push(-1);
    for(int i=0;i<s;i++){
        // h[st.top()] bcoz vector is storing indices not the values.
        while(st.top()!=-1 && h[i]<=h[st.top()]){
            st.pop();
        }
        prev[i]=st.top();
        st.push(i);
    }
    return prev;
}
vector<int> nextSmaller(vector<int>&h){
    int s=h.size();
    vector<int>next(s);
    stack<int>st;
    st.push(-1);
    for(int i=s-1;i>=0;i--){
        while(st.top()!=-1 && h[i]<=h[st.top()]){
            st.pop();
        }
        if(st.top()==-1){ // Bcoz we need actual greater values while calculating width.
            next[i]=s;
        } else{
            next[i]=st.top();
        }
        st.push(i);
    }
    return next;
}
int largestAreaInHistogram(vector<int>&heights){
    int s=heights.size();
    vector<int>prev=prevSmaller(heights);
    vector<int>next=nextSmaller(heights);
    int maxArea=0;
    for(int i=0;i<s;i++){
        int h=heights[i];
        int w=next[i]-prev[i]-1;
        maxArea=max(maxArea,h*w);
    }
    return maxArea;
}
int maximalArea(vector<vector<char>>&rectangleMatrix){
    // The input vector is in char, so need to make int type
    int rows=rectangleMatrix.size();
    int cols=rectangleMatrix[0].size();
    vector<vector<int>>histogramEntries;
    for(int i=0;i<rows;i++){
        vector<int>temp;
        for(int j=0;j<cols;j++){
            temp.push_back(rectangleMatrix[i][j]-'0');
        }
        histogramEntries.push_back(temp);
    }
    // Calculate area of first row.
    int maxArea=largestAreaInHistogram(histogramEntries[0]);
    // Calculate other rows
    for(int i=1;i<rows;i++){
        for(int j=0;j<cols;j++){
            // updating current row values with previous values adding basically ex, at bottom
            if(histogramEntries[i][j]){
                histogramEntries[i][j]+=histogramEntries[i-1][j];
            } else{
                histogramEntries[i][j]=0;
            }
        }
        maxArea=max(maxArea,largestAreaInHistogram(histogramEntries[i]));
    }
    return maxArea;
}
int main(){
    vector<vector<char>> rectangleMatrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalArea(rectangleMatrix);
    return 0;
}
/* 
1 0 1 0 0        1 0 1 0 0
1 0 1 1 1   ==>  2 0 2 1 1
1 1 1 1 1        3 1 3 2 2
1 0 0 1 0        4 0 0 3 0
*/
// If bottoms rows has then there will no histogram bcoz histogram hawa me thodi udega