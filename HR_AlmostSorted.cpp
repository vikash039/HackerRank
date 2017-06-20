/*
* https://www.hackerrank.com/challenges/almost-sorted/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSorted(int arr[], int N)
{
    for(int i=1;i<N;i++){
        if(arr[i]<arr[i-1])
            return false;
    }
    return true;
}

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void do_solve(int arr[], int N)
{
    if(isSorted(arr, N)){
        cout << "yes\n";
        return;
    }
    int i = 0;
    while(i<N-1){
        if(arr[i]>arr[i+1])
            break;
        i++;
    }
    int j = N-1;
    while(j>0){
        if(arr[j]<arr[j-1])
            break;
        j--;
    }
    swap(arr, i, j);
    if(isSorted(arr, N)){
        cout << "yes\n";
        cout << "swap " << i+1 << " " << j+1 << "\n";
        return;
    }
    int k = i+1, l = j-1;
    while(k<l){
        swap(arr, k, l);
        k++,l--;
    }
    if(isSorted(arr, N)){
        cout << "yes\n";
        cout << "reverse " << i+1 << " " << j+1 << "\n";
        return;
    }
    cout << "no\n";
    return;
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int i=0;i<N;i++) cin >> arr[i];
    do_solve(arr, N);
    return 0;
}
