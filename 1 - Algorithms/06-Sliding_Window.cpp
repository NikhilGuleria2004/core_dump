#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSum(vector<int>&arr, int k){
    int windowsSum = 0;
    int maxSum = 0;
    
    for(int i=0;i<k;i++){
        windowsSum+=arr[i];
    }
    
    maxSum = windowsSum;
    for(int i=k; i<arr.size(); i++){
        windowsSum+=arr[i];
        windowsSum-=arr[i-k];
        
        maxSum = max(maxSum, windowsSum);
    }
    
    return maxSum;
}

int main(){
    vector<int>arr = {2,1,5, 1,3,2};
    cout<<maxSum(arr,3);
}
