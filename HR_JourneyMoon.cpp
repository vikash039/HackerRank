/*
 *       Filename:  HR_JourneyMoon.cpp
 *    Description:  https://www.hackerrank.com/challenges/journey-to-the-moon/problem
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}
 
int find(vector<int> &parent, int a)
{
    if(parent[a] != -1)
        parent[a] = find(parent, parent[a]);
    return (parent[a] == -1 ? a : parent[a]);
}

void Union(vector<int> &parent, vector<int> &size, int x, int y)
{
    if(size[x] < size[y]){
        parent[x] = y;
        size[y] += size[x];
    }
    else{
        parent[y] = x;
        size[x] += size[y];
    }
}

int main()
{ 
    int N, I;
    cin >> N >> I;
    vector<int> parent(N, -1);
    vector<int> size(N, 1);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        int x = find(parent, a);
        int y = find(parent, b);
        if(x == y)
            continue;
        Union(parent, size, x, y);
    }
 
    long long result = 0;
    long long sum = 0;
    int feasible = 0;
    
    for(int i = 0; i < N; i++){
        if(parent[i] == -1){
            feasible++;
            if(feasible >= 2){
                result += (sum * size[i]);
            }
            sum += size[i];
        }
    }
    
    cout << result << endl;
    return 0;
}

