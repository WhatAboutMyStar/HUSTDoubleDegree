/*
input:
6 9
0 1 16
0 2 13
2 1 4
1 3 12
3 2 9
2 4 14
4 3 7
3 5 20
4 5 4

6是一共有6个顶点
9是一共有9条边
剩余9行，前两个是一条有向边，后面两个表示流量和容量 
其中源点用0来表示，汇点用5来表示 
用例是算法导论425页的最大流的例子
由于寻找增广路径的时候我使用的是深度优先搜索，执行过程和书上略有区别，但是结果一样。 
*/
#include<iostream>
#include<vector>
using namespace std;
int n,m; //顶点数和边数 
const int INF = 0x7fffffff;
const int MAXV = 100;
//定义图的结构 
struct Graph{
	int flow;
	int capacity;
}G[MAXV][MAXV];
bool vis[MAXV] = {false};
//vector<int> route[MAXV];
vector<int> route;
vector<int> route2;
int r = 0; //路径的数量 
int Gc[MAXV][MAXV];//残存网络
//使用深度优先遍历找出所有到终点的路径 
int flag = false;
void find_route(int v,int end)
{
	route.push_back(v);
	vis[v] = true;
	//找到了到汇点的路径将其保存起来 
	if(v == end)
	{
		route2 = route;
		flag = true;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i] == false and Gc[v][i] > 0)
		{
			find_route(i,end);
			if(flag)
				return ;
			else
			{
				route.pop_back();
				vis[i] = false;
			}
			
		}
	}
}

bool hasPath(int start, int end)
{
	route.clear();
	route2.clear();
	fill(vis, vis + MAXV, false);
	flag = false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(G[i][j].capacity > 0)
			{
				Gc[j][i] = G[i][j].flow;
				Gc[i][j] = G[i][j].capacity - G[i][j].flow;
			}
		}
	}
	find_route(start,end);

	if(route[route2.size() - 1] != end)
	{
		return false;		
	}
	else
	{
		return true;
	}
		
}

int min_flow()
{
	int min_f = INF;
	for(int i=0;i<route2.size() - 1;i++)
	{
		if(Gc[route2[i]][route2[i+1]] < min_f)
		{
			min_f = Gc[route2[i]][route2[i+1]];
		}
	}
	return min_f;
}

void Ford_Fulkerson()
{
	int start = 0;
	int end = n - 1;
	while(hasPath(start,end)) //判断是否还有增广路径 
	{
		//打印增广路径 
		for(int i=0;i<route2.size();i++)
		{
			if(i!=route2.size()-1)
				cout<<route2[i]<<"->";
			else
				cout<<route2[i]<<endl;
		}
		
		int mf = min_flow();
		for(int i=0;i<route2.size() - 1;i++) //遍历这条路径上的所有边 
		{
			if(G[route2[i]][route2[i + 1]].capacity != 0)
			{
				G[route2[i]][route2[i + 1]].flow += mf;
			}
			else
			{
				G[route2[i + 1]][route2[i]].flow -= mf;
			}
		}
	}
}

int main()
{
	for(int i=0;i<MAXV;i++)
	{
		for(int j=0;j<MAXV;j++)
		{
			G[i][j].capacity = 0;
			G[i][j].flow = 0;
		}
	}
	freopen("./ford-f.in","r",stdin); //输入重定向
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,capacity;
		cin>>u>>v>>capacity;
		G[u][v].capacity = capacity;
	}
	Ford_Fulkerson();
	//显示流网络 
	
	cout<<"最终的流网络邻接矩阵：\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<G[i][j].flow<<" ";
		}
		cout<<endl;
	}
	cout<<"最大流：";
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		ans += G[0][i].flow;
	}
	cout<<ans<<endl;
	return 0;
}
