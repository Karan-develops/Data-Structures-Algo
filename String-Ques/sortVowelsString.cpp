// LC - 2785 - Medium - Sort Vowels in a String
// 2 Approaches
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
// Approach 1 - Sorting
class String{
    bool isVowel(char ch){
        ch=tolower(ch);

        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    public:
    string sortVowels(string s){
        string temp;

        for(char &ch:s){
            if(isVowel(ch)){
                temp.push_back(ch);
            }
        }

        sort(begin(temp),end(temp));
        int n=temp.length();
        int i=0;

        for(char &ch:s){
            if(isVowel(ch)){
                ch=temp[i++];
            }
        }

        return s;
    }
};
class CountingSort{
    bool isVowel(char ch){
        ch=tolower(ch);

        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    public:
    string sortVowels(string s){
        unordered_map<char,int>mp;
        
        for(char &ch:s){
            if(isVowel(ch)){
                mp[ch]++;
            }
        }
        
        string temp="AEIOUaeiou";
        
        int j=0;
        
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                while(mp[temp[j]]==0){
                    j++;
                }
                
                s[i]=temp[j];
                mp[temp[j]]--;
            }
        }
        return s;
        
    }
};
int main(){
    // Output: "lEOtcede"
    string s="lEetcOde";
    // Output: "lYmpH"
    string s2="lYmpH";

    String sol;
    cout<<sol.sortVowels(s)<<endl;
    cout<<sol.sortVowels(s2);
    return 0;
}