/*
 *       Filename:  HR_RoadLibrary.cpp
 *    Description:  https://www.hackerrank.com/challenges/torque-and-development/problem
 */

#include <bits/stdc++.h>

using namespace std;

void DFS(list<int> adj[], int src, vector<bool>& visited)
{
    list<int>::iterator it = adj[src].begin();
    while(it != adj[src].end()){
        if(!visited[*it]){
            visited[*it] = true;
            DFS(adj, *it, visited);
        }
        it++;
    }
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        long x;
        long y;
        cin >> n >> m >> x >> y;
        list<int> adj[n+1];
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            adj[city_1].push_back(city_2);
            adj[city_2].push_back(city_1);
        }
        if(y >= x){
            cout << n*x << "\n";
        }else{
            vector<bool> visited(n+1, false);
            int cmp = 0;
            for(int i=1;i<=n;i++){
                if(!visited[i]){
                    visited[i] = true;
                    DFS(adj, i, visited);
                    cmp++;
                }
            }
            cout << (n-cmp) * y + cmp * x << "\n";
        }
    }
    return 0;
}
