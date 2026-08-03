#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n = 10;
    
    vector<int> diff(n+1,0);
    
    auto update=[&](int left,int right, int val){
        diff[left]+=val;
        diff[right+1] -=val;
    };
    
    update(2,6,5);
    update(4,8,3);
    update(1,5,2);
    
    vector<int> final_arr(n,0);
    int current_running_total=0;
    
    for(int i=0; i<n;i++){
        current_running_total+=diff[i];
        final_arr[i]=current_running_total;
    }
    
    cout<<"Final Array Values:\n";
    for(int i=0;i<n; i++){
        cout<<"Index "<<i<<": "<<final_arr[i]<<"\n";
    }
    return 0;
}