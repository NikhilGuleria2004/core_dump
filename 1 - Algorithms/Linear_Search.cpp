#include<iostream>
#include<vector>
using namespace std;

int linear_search(vector<int> & arr, int target){
    for(int i =0;i<arr.size(); i++){
        if(arr[i] == target) return i;
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
    cout<<linear_search(arr, 9);
}