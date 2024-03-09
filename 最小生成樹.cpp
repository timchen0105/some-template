#include<bits/stdc++.h>
using namespace std;

const int MAXV = 100, MAXE = 1000;

int v, e;
int weight = 0;
int v_num;

struct Edge{
	int a;
	int b;
	int w;
}E[MAXE];

int p[MAXV];
int sz[MAXV];
void init(){
	for(int i = 1; i <= v; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	int px = find(x);
	int py = find(y);
	if(sz[px] > sz[py]){
		p[py] = px;
		sz[px] += sz[py];
	}else{
		p[px] = py;
		sz[py] += sz[px];
	}
}

bool cmp(Edge x, Edge y){
	return x.w < y.w;
}

void Kruskal(){
	init();
	sort(E+1, E+1+e, cmp);

	int i = 1, j = 1;
	for(i, j; i <= v-1 && j <= e; i++){
		while(find(E[j].a) == find(E[j].b)){
            j++;
            continue;
		}

		merge(E[j].a, E[j].b);
		weight += E[j].w;

		j++;
	}

	v_num = i;
}

int main(){
	cin >> v >> e;
	for(int i = 1; i <= e; i++){
		cin >> E[i].a >> E[i].b >> E[i].w;
	}

	Kruskal();

	if(v_num == v){
		cout << weight << endl;
	}else{
		cout << -1 << endl;
	}
}
