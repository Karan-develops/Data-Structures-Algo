// Full Pyramid
/*#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter row:";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}*/
// Approach 2
#include <iostream>
using namespace std;
int main()
{
    short n;
    cout << "Enter row:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k=0;
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (j < n - i - 1)
                cout << " ";
            else if (k < 2 * i + 1)
            {
                cout << "*";
                k++;
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}