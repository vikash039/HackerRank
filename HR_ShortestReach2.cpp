/*
 *       Filename:  HR_ShortestReach2.cpp
 *    Description:  https://www.hackerrank.com/challenges/dijkstrashortreach/problem
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 9999999

void dijkstra(list<pair<int, int> >* adj_list, int src, int N)
{
    set<pair<int, int> > setd;
    vector<int> dist(N+1, INF);
    setd.insert(make_pair(0, src));
    dist[src] = 0;
    while(!setd.empty()){
        pair<int, int> tmp = *(setd.begin());
        setd.erase(setd.begin());
        int u = tmp.second;
        list<pair<int, int> >::iterator itr;
        for(itr = adj_list[u].begin(); itr != adj_list[u].end(); itr++){
            int v = (*itr).first;
            int w = (*itr).second;
            if(dist[v] > dist[u] + w){
                if(dist[v] != INF)
                    setd.erase(setd.find(make_pair(dist[v], v)));
                dist[v] = dist[u] + w;
                setd.insert(make_pair(dist[v], v));
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(i != src)
            cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
        list<pair<int, int> > *adj_list = new list<pair<int, int> >[n+1];
        for(int a1 = 0; a1 < m; a1++){
            int x;
            int y;
            int r;
            cin >> x >> y >> r;
            adj_list[x].push_back(make_pair(y, r));
            adj_list[y].push_back(make_pair(x, r));
        }
        int s;
        cin >> s;
        dijkstra(adj_list, s, n);
    }
    return 0;
}

