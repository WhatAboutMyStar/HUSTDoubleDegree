#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int MAXV = 100;
const int INF = 100000000;
set<int> V;
int n;
int G[MAXV][MAXV];
int path[MAXV][MAXV];

void floyd()
{
	for(int i=0;i<MAXV;i++)
	{
		for(int j=0;j<MAXV;j++)
		{
			path[i][j] = -1;
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i =0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(G[i][k]!=INF and G[k][j]!=INF and G[i][k]+G[k][j] < G[i][j])
				{
					G[i][j] = G[k][j] + G[i][k];
					path[i][j] = k;
				}
			}
		}
	}
}
void print_path(int u,int v)
{
	if(path[u][v]==-1)
	{
		return;
	}
	print_path(u,path[u][v]);
	cout<<path[u][v]<<"-";
	print_path(path[u][v],v);
}
int main()
{
	freopen("./fw.in","r",stdin);//输入重定向，相当于你在控制台里面输入了in文件里面的所有内容
	cin>>n;
	fill(G[0],G[0] + MAXV * MAXV,INF);
	for(int i=0;i<n;i++)
	{
		int u,v,distance;
		cin>>u>>v>>distance;
		V.insert(u);
		V.insert(v);
		G[u][v] = distance;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i == j)
			{
				G[i][j] = 0;
			}
		}
	}
	floyd();
	for(set<int>::iterator it=V.begin();it!=V.end();it++)
	{
		for(set<int>::iterator it2=V.begin();it2 != V.end();it2++)
		{
			if(G[*it][*it2] == INF)
				continue;
			cout<<*it<<"-";
			print_path(*it,*it2);
			cout<<*it2<<" "<<G[*it][*it2]<<endl;
		}
	}
	return 0;
}
