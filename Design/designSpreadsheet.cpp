// LC - 3484 - Medium - Design Spreadsheet
#include<iostream>
#include<vector>
using namespace std;
class Design{
    int solve(string &s){
        if(isdigit(s[0])) return stoi(s);

        int row=stoi(s.substr(1))-1;
        int col=s[0]-'A';

        return sheet[row][col];
    } 
public:
    vector<vector<int>>sheet;
    Design(int rows){
        sheet.assign(rows,vector<int>(26,0));
    }
    
    void setCell(string cell,int value){
        int row=stoi(cell.substr(1))-1;
        int col=cell[0]-'A';

        sheet[row][col]=value;
    }
    void resetCell(string cell){
        int row=stoi(cell.substr(1))-1;
        int col=cell[0]-'A';

        sheet[row][col]=0;
    }
    int getValue(string formula){
        string s=formula.substr(1);
        int plusIdx=s.find('+');

        string left=s.substr(0,plusIdx);
        string right=s.substr(plusIdx+1);

        return solve(left)+solve(right);
    }
};