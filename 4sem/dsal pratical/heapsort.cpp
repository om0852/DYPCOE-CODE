#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n  && arr[l]>arr[largest])
    {
        largest=l;
    }
    if(r<n  && arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr, n, largest);
        
    }
    
    
}


void heap_sort(vector<int>& arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
                heapify(arr, n, i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void printHeap(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };
    // Function call
    heap_sort(arr);
    printHeap(arr);
    return 0;
}