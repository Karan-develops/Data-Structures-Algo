// LC - 1472 - Medium - Design Browser History
#include<iostream>
#include<stack>
using namespace std;
class BrowserHistory{
    stack<string>past;
    stack<string>future;
    string curr;
    public:
    BrowserHistory(string homepage){
        curr=homepage;
    }
    void visit(string url){
        past.push(curr);
        curr=url;
        future=stack<string>();
    }
    string back(int steps){
        while(!past.empty() && steps--){
            future.push(curr);
            curr=past.top();
            past.pop();
        }
        return curr;
    }
    string forward(int steps){
        while(!future.empty() && steps--){
            past.push(curr);
            curr=future.top();
            future.pop();
        }
        return curr;
    }
};