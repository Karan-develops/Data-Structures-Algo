// Shared Pointers
#include<iostream>
#include<memory>
using namespace std;
class Book{
    public:
    string title;
    Book(string t): title(move(t)){
        cout<<"Book Created of Title: "<<title<<endl;
    }
    ~Book(){
        cout<<"Book Destroyed of Title: "<<title<<endl;
    }
};
int main(){
    shared_ptr<Book>b1=make_shared<Book>("C++ Guide");

    {
        shared_ptr<Book>b2=b1; // Shared Ownership
        // b2->title="DSA Guide";
        cout<<"Inside B2 Block: "<<b2->title<<endl;
    } // b2 goes out of scope, but b1 still owns the object

    cout<<"Inside B1 Block: "<<b1->title<<endl;
    return 0;
} // b1 goes out of scope, Book is automatically deleted
/*
Output:
Book Created of Title: C++ Guide
Inside B2 Block: C++ Guide
Inside B1 Block: C++ Guide
Book Destroyed of Title: C++ Guide
*/