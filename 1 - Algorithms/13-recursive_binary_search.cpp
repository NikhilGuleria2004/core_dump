#include<iostream>
#include<vector>
using namespace std;

int binary_search_recursive(const vector<int>& arr, int left, int right, int target){
    if(left>right) return -1;
    
    int mid=left+(right-left)/2;
    
    if(arr[mid]==target) return mid;
    
    if(target<arr[mid])
    return binary_search_recursive(arr, left, mid-1, target);
    
    
    return binary_search_recursive(arr, mid+1, right, target);
}

int main(){
    vector<int> arr = {2,5,8,12,16,23,38,45,56};
    int target = 23;
    
    int index = binary_search_recursive(arr, 0, arr.size()-1, target);
    if(index!=-1)
        cout<<"Found at Index: "<<index<<endl;
    else
        cout<<"Not Found"<<endl;
        
    return 0;
}
