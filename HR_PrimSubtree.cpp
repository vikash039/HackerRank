/*
 *       Filename:  HR_PrimSubtree.cpp
 *    Description:  https://www.hackerrank.com/challenges/primsmstsub
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

typedef pair<int, int> ipair;

void prims_mst(list<ipair> *adj_list, int src, int N){
    priority_queue<ipair, vector<ipair>, greater<ipair> > pq;
    vector<int> dist(N+1, INF);
    vector<bool> visited(N+1, false);
    int ans = 0;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        ans += wt;
        list<ipair>::iterator itr;
        for(itr = adj_list[u].begin(); itr != adj_list[u].end(); itr++){
            int v = (*itr).first;
            int w = (*itr).second;
            if(dist[v] > w){
                dist[v] = w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    list<ipair> *adj_list = new list<ipair> [n+1];
    while(m--){
        int s, d, w;
        cin >> s >> d >> w;
        adj_list[s].push_back(make_pair(d, w));
        adj_list[d].push_back(make_pair(s, w));
    }
    int s;
    cin >> s;
    prims_mst(adj_list, s, n);
    return 0;
}

