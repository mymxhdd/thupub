#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>


using namespace std;


void insert(int* child, int len, int new_child){


    bool flag = false;
    for(int i=len-1; i>=0; i--){
        if(child[i] > new_child){
            child[i+1] = child[i];
        }
        else{
            child[i+1] = new_child;
            flag = true;
            break;
        }
    }
    if(!flag)
        child[0] = new_child;
    for(int i=0; i<=len; i++){
        cout << child[i] << " ";
    }
    cout << endl;

}


void solve(int n, int m, int k){
    int count = 0;
    int high = 0;

    int* child = new int[m+1];

    for(int i=0; i<n; i++){
        cin >> high;
        if(i >= m){
            count = child[m-1] - child[0];
            if(count <= k){
                cout << i << endl;
                break;
            }
            child[i] = high;
            insert(child, m, child[i]);
        }
        else{
            child[i] = high;
            insert(child, i, child[i]);
        }
    }
}


int main(){

    int n, m, k;
    cin >> n >> m >> k;
    solve(n , m, k);



    return 0;
}
