#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    
    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quick_sort(vector<int>&arr, int low, int high){
    if(low>=high) return;
    int pivotIndex = partition(arr, low, high);
    
    quick_sort(arr, low, pivotIndex-1);
    quick_sort(arr, pivotIndex+1, high);
}

int main(){
    vector<int> arr = {2,4,1,3,5};
    quick_sort(arr, 0, arr.size()-1);
    
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}
