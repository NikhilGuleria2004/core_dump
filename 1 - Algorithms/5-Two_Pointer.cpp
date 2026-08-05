#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int target = 9;
    
    int left = 0;
    int right = 6;
    
    while(left<right){
        int sum = arr[left]+arr[right];
        
        if(sum == target){ 
            cout<<left<<" "<<right<<endl;
            break;
        }
        if(sum<target) left++;
        if(sum>target) right--;
    }
    
    int revArr[] = {1,2,3,4,5,6,7,8,9,10};
    int start = 0;
    int end = 9;
    
    while(start<end){
        swap(revArr[start], revArr[end]);
        start++;
        end--;
    }
    
    for(int i=0;i<9;i++){
        cout<<revArr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
    
    
}