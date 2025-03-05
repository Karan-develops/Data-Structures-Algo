#include<iostream>
#include<vector>
using namespace std;
class MinHeap{
    private:
    vector<int>heap;
    void heapifyDown(int i){
        int smallest=i;
        int leftChild=2*i+1;
        int rightChild=2*i+2;
        if(leftChild<heap.size() && heap[smallest]>heap[leftChild]){
            smallest=leftChild;
        }
        if(rightChild<heap.size() && heap[smallest]>heap[rightChild]){
            smallest=rightChild;
        }
        if(smallest!=i){
            swap(heap[i],heap[smallest]);
            heapifyDown(smallest);
        }
    }
    void heapifyUp(int i){
        int parent=(i-1)/2;
        if(i>0 && heap[parent]>heap[i]){
            swap(heap[parent],heap[i]);
            heapifyUp(parent);
        }
    }
    public:
    void insert(int data){
        heap.push_back(data);
        heapifyUp(heap.size()-1);
    }
    int extractMin(){
        if(heap.empty()){
            throw out_of_range("Heap is Empty.");
        }
        int minVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }
    void display(){
        for(int i:heap){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MinHeap heap;
    heap.insert(5);
    heap.insert(10);
    heap.insert(50);
    heap.insert(8);
    heap.insert(3);
    heap.insert(54);
    cout << "Heap after insertions: ";
    heap.display();

    cout << "Extracted Min: " << heap.extractMin() << endl;

    cout << "Heap after extraction: ";
    heap.display();
    return 0;
}