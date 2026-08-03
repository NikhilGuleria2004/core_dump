#include<iostream>
#include<vector>
using namespace std;

vector<int> prefix_sum(vector<int> &arr){
    vector<int>  ans;
    ans.push_back(arr[0]);
    for(int i=1; i<arr.size(); i++){
        ans.push_back(arr[i]+ans[i-1]);
    }
    return ans;
}

int main(){
    vector<int> arr = {2,4,1,7,3};
    vector<int> ans = prefix_sum(arr);
    for(int i=0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}