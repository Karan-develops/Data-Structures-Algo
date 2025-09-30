// Unique Pointers
#include<iostream>
#include<memory>
using namespace std;
class Book{
    public:
    string title;
    Book(string t): title(move(t)){
        cout<<"Book created of Title: "<<title<<endl;
    }
    ~Book(){
        cout<<"Book destroyed of Title: "<<title<<endl;
    }
};
int main(){
    unique_ptr<Book>b1=make_unique<Book>("C++ Guide");

    // unique_ptr<Book>b2=b1; error (cannot copy)

    unique_ptr<Book>b2=move(b1); // transfer ownership
    
    if(!b1) cout<<"b1 is empty now lol"<<endl;

    // cout<<b1->title<<endl; program crashes
    cout<<b2->title<<endl;
    return 0;
}