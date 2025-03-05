/*#include<iostream>
using namespace std;
int main(){
    int rowCount,colCount;
    cout<<"Enter number of rows:";
    cin>>rowCount;
    cout<<"Enter number of columns:";
    cin>>colCount;
    cout<<"Here's the pattern"<<endl;
    for(int i=0;i<rowCount;i++){
        if(i==0 || i==rowCount-1){
            for(int j=0;j<colCount;j++){
                cout<<"* ";
            }
            cout<<endl;
        }
        else{
            cout<<"* ";
            for(int j=0;j<colCount-2;j++){
                cout<<"  ";
            }
            cout<<"* "<<endl;
        }
    }   
}*/
// Approach 2
#include<iostream>
using namespace std;
int main(){
    int rowCount,colCount;
    cout<<"Enter number of rows:";
    cin>>rowCount;
    cout<<"Enter number of columns:";
    cin>>colCount;
    cout<<"Here's the pattern"<<endl;
    for(int i=0;i<rowCount;i++){
        for(int j=0;j<colCount;j++){
            if(i==0 || j==0 || i==rowCount-1 || j==colCount-1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}