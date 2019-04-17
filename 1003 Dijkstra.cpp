#include<iostream>
using namespace std;
int n,m,c1,c2;
const int maxv = 501;
const int inf = 10000000;
int g[maxv][maxv];
int d[maxv];
bool visit[maxv] = {false};
int w[maxv];
int tempw[maxv];
int num[maxv];

void dijkstra(int s){
	fill(d,d+maxv,inf);
	d[s] = 0;
	fill(w,w+maxv,0);
	fill(num,num+maxv,0);
	w[s] = tempw[s];
	num[s] = 1;
	for(int i=0;i<n;i++){
		int u = -1,MIN = inf;
		for(int j=0;j<n;j++){
			if(d[j]<MIN&&visit[j]==false){
				u = j;
				MIN = d[j];
			}
		}
		if(u==-1) return;
		visit[u] = true;
		for(int v=0;v<n;v++){
			if(visit[v]==false&&g[u][v]!=inf){
				if(d[u]+g[u][v]<d[v]){
					d[v] = d[u] + g[u][v];
					w[v] = w[u] + tempw[v];
					num[v] = num[u];
				}
				else if(d[u]+g[u][v]==d[v]){
					num[v] = num[u] + num[v];
					if(w[v] < w[u] + tempw[v]){
						w[v] = w[u] + tempw[v];
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&tempw[i]);
	}
	int r1,r2;
	fill(g[0],g[0]+maxv*maxv,inf);
	for(int i=0;i<m;i++){
		scanf("%d%d",&r1,&r2);
		scanf("%d",&g[r1][r2]);
		g[r2][r1] = g[r1][r2];
	}
	dijkstra(c1);
	printf("%d %d",num[c2],w[c2]);
}
