#include<iostream>
using namespace std;
void transpose(int arr[][3],int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=i;j<cols;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}
void print(int arr[][3],int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[3][3]={{2,4,6},{1,3,5},{9,11,13}};
    int rows=3;
    int cols=3;
    transpose(arr,rows,cols);
    print(arr,rows,cols);
    return 0;
}