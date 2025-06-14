// LC - 2566 - Easy - Maximum Difference by Remapping a Digit
// 2 Approaches - Simple - STL
#include<iostream>
#include<algorithm>
using namespace std;
class Greedy{
    public:
    int minMaxDifference(int num){
        string minNum=to_string(num);
        string maxNum=to_string(num);
        int n=minNum.length();

        char ch;
        for(int i=0;i<n;i++){
            if(maxNum[i]!='9'){
                ch=maxNum[i];
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(maxNum[i]==ch){
                maxNum[i]='9';
            }
        }

        ch=minNum[0];
        for(int i=0;i<n;i++){
            if(minNum[i]==ch){
                minNum[i]='0';
            }
        }

        return stoi(maxNum)-stoi(minNum);
    }
    int STL(int num){
        string s1=to_string(num);
        string s2=to_string(num);

        int idx=s1.find_first_not_of('9');
        if(idx!=string::npos){
            char ch=s1[idx];
            replace(begin(s1),end(s1),ch,'9');
        }

        char ch=s2[0];
        replace(begin(s2),end(s2),ch,'0');

        return stoi(s1)-stoi(s2);
    }
};
int main(){
    // Output: 99009
    int num=11891;
    // Output: 99
    int num2=90;

    Greedy sol;
    cout<<sol.minMaxDifference(num)<<endl;
    cout<<sol.STL(num2);
    return 0;
}