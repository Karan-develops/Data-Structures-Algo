// LC - 2296 - HARD - Design a Text Editor
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
class Design{
public:
    deque<char>left;
    deque<char>right;
    // My Function
    string getCursorString(){
        string s;
        int count=10;

        while(!left.empty() && count--){
            s+=left.back();
            left.pop_back();
        }

        reverse(begin(s),end(s));
        
        for(int i=0;i<s.length();i++){
            left.push_back(s[i]);
        }

        return s;
    }
    public:
    Design(){
        left=deque<char>();
        right=deque<char>();
    }
    void addText(string text){
        left.insert(end(left),begin(text),end(text));
    }
    int deleteText(int k){
        int count=0;

        while(!left.empty() && k--){
            left.pop_back();
            count++;
        }
        return count;
    }
    string cursorLeft(int k){
        while(!left.empty() && k--){
            right.push_front(left.back());
            left.pop_back();
        }

        return getCursorString();
    }
    string cursorRight(int k){
        while(!right.empty() && k--){
            left.push_back(right.front());
            right.pop_front();
        }

        return getCursorString();
    }
};