// LC - 1678 - Easy - Goal Parser Interpretation
#include<iostream>
using namespace std;
string interpret(string command) {
    string ans="";
    for(int i=0;i<command.size();i++){
        if(command[i]=='G') ans+='G';
        else if(command[i]=='(' && command[i+1]==')'){
            ans+='o';
            i++;
        } else if(command[i]=='(' && command[i+1]=='a'){
            ans+="al";
            i+=3;
        }
    }
    return ans;
}
int main(){
    // Output: "Goal"
    string command="G()(al)";
    // Output: "Gooooal"
    string command2="G()()()()(al)";
    // Output: "alGalooG"
    string command3="(al)G(al)()()G";
    cout<<interpret(command)<<endl;
    cout<<interpret(command2)<<endl;
    cout<<interpret(command3);
    return 0;
}