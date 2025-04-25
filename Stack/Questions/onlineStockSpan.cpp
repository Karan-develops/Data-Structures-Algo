// LC - 901 - Medium - Online Stock Span
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
    stack<pair<int,int>>st;
    public:
    int next(int price){
        int span=1;
        while(!st.empty() || st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};
// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]