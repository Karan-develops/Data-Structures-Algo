// LC - 869 - Medium - Reordered Power of 2
// 3 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
// Approach 1 - Using Sorting
class Approach_1{
    string getSortedStr(int n){
        string s=to_string(n);
        sort(begin(s),end(s));
        
        return s;
    }
    public:
    bool reorderedPowerOf2(int n){
        string s=getSortedStr(n);

        // check all 2 powers and see if it matches with s
        // 2^29
        for(int p=0;p<=29;p++){
            if(s==getSortedStr(1<<p)){
                return true;
            }
        }
        return false;
    }
};
// Approach 2 - Using preprocessing and storing in a set
class Approach_2{
    unordered_set<string> st;
    void buildSet(){
        // 2^p from p = 0 to 29
        // convert to string
        // sort it
        // store it in st
        for(int p=0;p<=29;p++){
            string s=to_string(1<<p);
            sort(begin(s),end(s));
            st.insert(s);  
        }
    }
    public:
    bool reorderedPowerOf2(int n){
        if(st.empty()){
            buildSet(); //call only once (static)
        }

        string s=to_string(n);
        sort(begin(s),end(s));

        return st.count(s);
    }
};
// Approach 3 - count and store digits in a vector
class Approach_3{
    public:
    vector<int> getVectorCountFormat(int n){
        vector<int>vec(10,0);
        //256
        //256/10 = 25
        while(n){
            vec[n%10]++;
            n/=10;
        }
        return vec;
    }
    bool reorderedPowerOf2(int n){
        vector<int>input=getVectorCountFormat(n);

        for(int p=0;p<=29;p++){
            if(input==getVectorCountFormat(1<<p)){
                return true;
            }
        }
        return false;
    }
};
int main(){
    // Output: true
    int n=1;
    // Output: false
    int n2=10;
    return 0;
}