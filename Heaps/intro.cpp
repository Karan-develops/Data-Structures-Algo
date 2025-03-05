// Heaps -> CBT complete binary tree
// MinHeap,MaxHeap
#include<iostream>
#include<vector>
using namespace std;
// Starting for last non-leaf node
void heapifyDown(vector<int>&arr,int n,int i){
    int largest=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;
    // Check if left child exists and is greater
    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest=leftChild;
    }
    // Check if right child exists and is greater
    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest=rightChild;
    }
    // If largest is not the current node, swap and recursively heapify
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapifyDown(arr,n,largest);
    }
}
void buildHeap(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapifyDown(arr,n,i);
    }
}
void displayHeap(const vector<int>&arr){
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>arr={10,20,15,30,40,50,25};
    cout<<"Original Array: ";
    displayHeap(arr);
    buildHeap(arr);
    cout<<"Heapified Array: ";
    displayHeap(arr);
    return 0;
}