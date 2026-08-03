#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> &arr, int target){
    int start = 0;
    int end = arr.size()-1;
    
    while(start<=end){
        int mid = (start+end)/2;
        if(target>arr[mid]) start = mid+1;
        if(target<arr[mid]) end = mid-1;
        if(target==arr[mid]) return mid;
    }
    return -1;
} 

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
    cout<<binary_search(arr, 9);
}