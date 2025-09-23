// Emplace & Emplace back
/*
   | Function      |Containers                     |
   | --------------|-------------------------------|
   | `emplace_back`|`vector`,`deque`,`list`        |
   | `emplace`     |`map`,`set`,`unordered_map` etc|
*/
#include<iostream>
#include<vector>
using namespace std;
struct Person{
    string username;
    int userId;

    Person(string name,int id): username(name),userId(id){}
};
int main(){
    vector<Person>people;

    // Simple push_back makes a copy (requires creating a temporary Person)
    people.push_back(Person("A",10));

    // emplace_back directly puts inside container (constructs in-place, no temporary)
    people.emplace_back("B",15);

    cout<<people[0].username<<endl;

    /* Emplace is for more standard containers like 
       emplace(pos, args...) → inserts at the position pos in the container 
       (anywhere, not just the end).
    */
    vector<int>v={1,2,4};

    // Insert 3 at position 2 (before 4)
    v.emplace(begin(v)+2,3);

    for(int &i:v) cout<<i<<" "; // Output: 1 2 3 4
    cout<<endl;
    
}