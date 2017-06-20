/*
*	https://www.hackerrank.com/challenges/larrys-array/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int merge(int arr[], int tmp[], int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = left;
    int inv = 0;
    while(i<mid && j<=right){
        if(arr[i]<=arr[j]){
            tmp[k++] = arr[i++];
        }
        else{
            tmp[k++] = arr[j++];
            inv += (mid-i);
        }
    }
    while(i<mid){
        tmp[k++] = arr[i++];
    }
    while(j<=right){
        tmp[k++] = arr[j++];
    }
    for(i=left;i<=right;i++)
        arr[i] = tmp[i];
    return inv;
}

int countInv(int arr[], int tmp[], int left, int right)
{
    int mid, inv = 0;
    if(right > left){
        mid = left + (right-left)/2;
        inv = countInv(arr, tmp, left, mid);
        inv += countInv(arr, tmp, mid+1, right);
        inv += merge(arr, tmp, left, mid+1, right);
    }
    return inv;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        int N, inv = 0;
        cin >> N;
        int arr[N], tmp[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            tmp[i] = 0;
        }
        inv = countInv(arr, tmp, 0, N-1);
        if(inv & 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
