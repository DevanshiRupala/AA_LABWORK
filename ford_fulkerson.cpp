#include<bits/stdc++.h>
using namespace std;

bool bfs(int rg[6][6],int s,int t,int p[])
{
	vector<int>visited(6,0);
	queue<int>q;
	q.push(s);
	visited[s]=1;
	p[s]=-1;
	while(!q.empty())
	{
    	int u = q.front();
    	q.pop();
    	for(int v=0;v<6;v++)
    	{
        	if(visited[v] == 0 && rg[u][v] > 0)
        	{
            	if(v == t)
            	{
                	p[v] = u;
                	return true;
            	}
            	q.push(v);
            	visited[v]=1;
            	p[v]= u;
        	}
    	}
	}
	return false;
}

int ford_fulkerson(int g[6][6],int s,int t)
{
	int rg[6][6];
	for(int u=0;u<6;u++)
	{
    	for(int v=0;v<6;v++)
    	{
        	rg[u][v]=g[u][v];
    	}
	}
    
	int p[6];
	int mf = 0;
	while(bfs(rg,s,t,p))
	{
    	int pf = INT_MAX;
    	for(int v=t;v!=s;v=p[v])
    	{
        	int u = p[v];
        	pf = min(pf,rg[u][v]);
    	}
    	for(int v=t;v!=s;v=p[v])
    	{
        	int u = p[v];
        	rg[u][v]-=pf;
        	rg[v][u]+=pf;
    	}
    	mf+=pf;
	}
	return mf;
}

int main()
{
	int g[6][6] = {{0,16,13,0,0,0},
               	{0,0,10,12,0,0},
               	{0,4,0,0,14,0},
               	{0,0,9,0,0,20},
               	{0,0,0,7,0,4},
               	{0,0,0,0,0,0}};
              	 
	int n = ford_fulkerson(g,0,5);
	cout << n;
	return 0;
}
