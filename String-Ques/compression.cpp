// LC - 443 - Medium - String Compression
#include<iostream>
#include<vector>
using namespace std;
int compress(vector<char>&chars){
    int n=chars.size();
    int idx=0;
    for(int i=0;i<n;i++){
        int count=0;
        while(i+1<n && chars[i]==chars[i+1]){
            count++;
            i++;
        }

        chars[idx++]=chars[i];
        if(count==0) continue;

        string temp=to_string(count+1);
        for(int x=0;x<temp.length();x++){
            chars[idx++]=temp[x];
        }
    }
    return idx;
}
int main(){
    // Output: Return 6, and the first 6 characters of the input array should be: ['a','2','b','2','c','3']
    vector<char>chars={'a','a','b','b','c','c','c'};
    // Output: Return 1, and the first character of the input array should be: ['a']
    vector<char>chars2={'a'};
    // Output: Return 4, and the first 4 characters of the input array should be: ['a','b','1','2'].
    vector<char>chars3={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout<<compress(chars)<<endl;
    cout<<compress(chars2)<<endl;
    cout<<compress(chars3);
    return 0;
}