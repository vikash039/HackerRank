/*
 *       Filename:  HR_BikeRacers.c
 *    Description:  https://www.hackerrank.com/challenges/bike-racers/problem
 */

#include <stdio.h>

#define MAX 253
#define INF 9999999

typedef struct {
	int x;
	int y;
}point;

int dfs(int biker, int bks[], int used[], int graph[][MAX], int M)
{
	int i;
	for(i=0;i<M;i++){
		if(graph[biker][i] && !used[i]){
			used[i] = 1;
			if(bks[i] == -1 || dfs(bks[i], bks, used, graph, M)){
				bks[i] = biker;
				return 1;
			}
		}
	}
	return 0;
}

int feasible(int N, int M, int K, long mid, point bikers[], point bikes[], long dist[][MAX])
{
	int i, j;
	int graph[MAX][MAX];

	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(dist[i][j] <= mid){
				graph[i][j] = 1;
			}
			else
				graph[i][j] = 0;
		}
	}

	int bks[M];
	for(i=0;i<M;i++)
		bks[i] = -1;
	int count = 0;
	for(i=0;i<N;i++){
		int used[M];
		for(j=0;j<M;j++)
			used[j] = 0;

		if(dfs(i, bks, used, graph, M))
			count++;
	}

	return (count >= K);
}

int main()
{
	setbuf(stdout, NULL);
	int T;
	//scanf("%d", &T);
    T=1;
	while(T--){
		int N, M, K, i, j;
		scanf("%d %d %d", &N, &M, &K);
		point bikers[N];
		for(i=0;i<N;i++){
			scanf("%d %d", &bikers[i].x, &bikers[i].y);
		}
		point bikes[M];
		for(i=0;i<M;i++){
			scanf("%d %d", &bikes[i].x, &bikes[i].y);
		}
		long dist[MAX][MAX];
		long maxdist = 0;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				long distx = bikers[i].x - bikes[j].x;
				if(distx < 0) distx = distx * (-1);
				distx = distx * distx;
				long disty = bikers[i].y - bikes[j].y;
				if(disty < 0) disty = disty * (-1);
				disty = disty * disty;
				dist[i][j] = distx + disty;
				maxdist = (maxdist < dist[i][j] ? dist[i][j] : maxdist);
			}
		}

		long low = 0;
		long high = maxdist;
		long ans = 0;
		while(low < high){
			long mid = low + (high - low)/2;
			if(feasible(N, M, K, mid, bikers, bikes, dist)){
				high = mid;
			}
			else
				low = mid+1;
		}
		printf("%ld\n", low);
	}
	return 0;
}

