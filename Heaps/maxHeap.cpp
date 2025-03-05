#include<iostream>
#include<vector>
using namespace std;
class MaxHeap{
    private:
    vector<int>heap;
    // Heapify Down: Used after deleting the root
    void heapifyDown(int i){
        int largest=i;
        int leftChild=2*i+1;
        int rightChild=2*i+2;
        // Check if left child exists & is greater than current node
        if(leftChild<heap.size() && heap[leftChild]>heap[largest]){
            largest=leftChild;
        }
        // Check if left child exists & is greater than current node
        if(rightChild<heap.size() && heap[rightChild]>heap[largest]){
            largest=rightChild;
        }
        // If largest is not the current node, swap and recursively heapify
        if(largest!=i){
            swap(heap[largest],heap[i]);
            heapifyDown(largest);
        }
    }
    // Heapify Up: Used after insertion
    void heapifyUp(int index){
        int parent=(index-1)/2;
        // If the current node is greater than its parent, swap and recurse
        if(index>0 && heap[index]>heap[parent]){
            swap(heap[index],heap[parent]);
            heapifyUp(parent);
        }
    }
    public:
    void insert(int data){
        heap.push_back(data);
        heapifyUp(heap.size()-1);
    }
    int extractMax(){
        if(heap.empty()){
            // cout<<"Heap is Empty."<<endl;
            // return -1;
            throw out_of_range("Heap is Empty");
        }
        int maxVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }
    void display(){
        for(int i:heap){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MaxHeap heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(25);
    cout << "Heap after insertions: ";
    heap.display();

    cout << "Extracted Max: " << heap.extractMax() << endl;

    cout << "Heap after extraction: ";
    heap.display();
    return 0;
}