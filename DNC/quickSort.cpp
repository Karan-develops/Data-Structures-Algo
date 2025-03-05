#include<iostream>
using namespace std;
int pivotElement(int* arr,int s,int e){
    // step1:Choose pivot element
    int pivotIndex=s;
    int pivotElement=arr[s];
    int count=0;
    // step2:find correct index of pivot element and place it there
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivotElement) count++;
    }
    int correctIndex=s+count;
    swap(arr[pivotIndex],arr[correctIndex]);
    pivotIndex=correctIndex;
    // step3:left me chote elements and right me bade elements daalne h
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivotElement) i++;
        while(arr[j]>pivotElement) j--;
        if(i<pivotIndex && j>pivotIndex){
        swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
}
void qS(int* arr,int s,int e){
    if(s>=e) return;
    // partitioning logic, returns pivotIndex
    int pivotElementIndex=pivotElement(arr,s,e);
    // left part
    qS(arr,s,pivotElementIndex-1);
    // right part
    qS(arr,pivotElementIndex+1,e);
}
int main(){
    int arr[]={8,1,3,4,20,50,30,1,3,1,1,2,1,2,0,230,1};
    int n=sizeof(arr)/sizeof(int);
    qS(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Easier approach
/*#include<iostream>
using namespace std;

int partition(int* arr, int s, int e) {
    // step1: Choose pivot element (we choose the first element as pivot)
    int pivotElement = arr[s];
    int i = s + 1;  // Start from the element next to the pivot
    int j = e;      // Start from the end of the array
    
    while (i <= j) {
        // Find the first element greater than the pivot
        while (i <= e && arr[i] <= pivotElement) {
            i++;
        }
        // Find the first element smaller than or equal to the pivot
        while (j >= s && arr[j] > pivotElement) {
            j--;
        }
        // Swap elements if `i` is still less than `j`
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Finally, swap the pivot element with arr[j] to place it at the correct index
    swap(arr[s], arr[j]);
    return j;  // Return the correct position of the pivot element
}

void quickSort(int* arr, int s, int e) {
    if (s >= e) return;
    
    // Partitioning logic, returns the correct position of the pivot
    int pivotIndex = partition(arr, s, e);
    
    // Sort the left part
    quickSort(arr, s, pivotIndex - 1);
    
    // Sort the right part
    quickSort(arr, pivotIndex + 1, e);
}

int main() {
    int arr[] = {8, 1, 3, 4, 20, 50, 30, 1, 3, 1, 1, 2, 1, 2, 0, 230, 1};
    int n = sizeof(arr) / sizeof(int);
    
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
*/