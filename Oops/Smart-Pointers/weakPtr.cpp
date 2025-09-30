// Weak Pointers (non-owning reference)
// Used together with shared_ptr.
#include<iostream>
#include<memory>
using namespace std;
class Node{
    public:
    int val;
    shared_ptr<Node>next;
    weak_ptr<Node>prev; // weak_ptr avoids circular reference

    Node(int v): val(v){
        cout<<"Node created of val: "<<val<<endl;
    }
    ~Node(){
        cout<<"Node destroyed"<<endl;
    }
};
// Better Example
class BadPerson{
    public:
    string name;
    shared_ptr<BadPerson>bestFriend; // both strong

    BadPerson(string n): name(move(n)){
        cout<<name<<" created"<<endl;
    }
    ~BadPerson(){
        cout<<name<<" deleted"<<endl;
    }
};
class GoodPerson{
    public:
    string name;
    weak_ptr<GoodPerson>bestFriends; // weak (no ownership)

    GoodPerson(string n): name(move(n)){
        cout<<name<<" created"<<endl;
    }
    ~GoodPerson(){
        cout<<name<<" destroyed"<<endl;
    }
};
int main(){
    // Example 1:
    shared_ptr<Node>n1=make_shared<Node>(1);
    shared_ptr<Node>n2=make_shared<Node>(2);

    n1->next=n2;
    n2->prev=n1; // weak_ptr prevents memory leak

    cout<<"n1->next->value : "<<n1->next->val<<endl;

    /* ---------------------------------------------------------------- */
    // Example 2:
    /* This is bad practice
    auto alice=make_shared<BadPerson>("Alice");
    auto bob=make_shared<BadPerson>("Bob");
    
    alice->bestFriend=bob;
    bob->bestFriend=alice; // circular shared_ptr

    Output: 
    Alice created
    Bob created
    End of main (no "destroyed". They are stuck forever in memory → leak.)
    */

    // Better & Correct Way
    auto alice=make_shared<GoodPerson>("Alice");
    auto bob=make_shared<GoodPerson>("Bob");

    alice->bestFriends=bob;
    bob->bestFriends=alice; // Safe now

    return 0;
}
/*
Output:
Alice created
Bob created
End of main
Bob destroyed
Alice destroyed
*/
/*
⚡️Analogy:

→ Think of shared_ptr as owning keys to a house:
→ As long as someone has a key, the house exists.
→ If everyone throws away keys → house demolished.

Problem: If two people exchange keys, no one throws them → house stays forever (leak).

→ A weak_ptr is like saying:
→ “I know the address of the house, but I don’t hold a key.”
→ If the house is demolished, you can’t enter anymore.

That’s why we need weak_ptr.
*/
/*
✅ When to use
→ Parent ↔ Child relationships (e.g., Tree, Graph, Linked List)
→ → Parent owns child with shared_ptr
→ → Child references parent with weak_ptr
→ Observer pattern (listeners that should not keep subjects alive forever)
→ Caches (you want to reference objects if alive, but not force them to stay alive)
*/