#include<iostream>
#include<vector>
using namespace std;

vector<int> bubble_sort(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-1; j++){
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    
    return arr;
}

int main(){
    vector<int> arr = {2,4,1,3,5};
    vector<int> sorted = bubble_sort(arr);
    for(int i=0; i<sorted.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
