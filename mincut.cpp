#include<bits/stdc++.h>

using namespace std;

int G1[4][4];

void mincut(int G[4][4],int u,int v,int n)
{
	for(int i=0;i<n-1;i++)
	{
    	for(int j=i+1;j<n;j++)
    	{
        	int cnt = 0;
        	if(i == u && j == v)
        	{
            	G1[i][j]=G1[j][i]=0;
        	}
        	else if(i == u || i == v)
        	{
            	if(G[u][j] > 0)
            	cnt+=G[u][j];
            	if(G[v][j] > 0)
            	cnt+=G[v][j];
            	G1[u][j]=G1[v][j]=cnt;
        	}
        	else if(j == u || j == v)
        	{
            	if(G[u][i] > 0)
            	cnt+=G[u][i];
            	if(G[v][i] > 0)
            	cnt+=G[v][i];
            	G1[i][u]=G1[i][v]=cnt;
        	}
        	else{
            	G1[i][u]=G1[i][v]=cnt;
        	}
    	}
	}
    
	for(int i=0;i<n;i++)
	{
    	for(int j=0;j<n;j++)
    	{
        	if(i >= j)
        	{
            	G1[i][j]=G1[j][i];
        	}
    	}
	}
    
	int G2[3][3];
	for(int i=0;i<n;i++)
	{
    	for(int j=0;j<n;j++)
    	{
        	if(i == v || j == v)
          	G2[i][j] = G1[i+1][j+1];
         	else
          	G2[i][j] = G1[i][j];
    	}
	}
    
	for(int i=0;i<n-1;i++)
	{
    	for(int j=0;j<n-1;j++)
    	{
        	cout << G2[i][j] << " ";
    	}
    	cout << endl;
	}
}

int main()
{
	int G[4][4] = {{0,1,1,1},
         	{1,0,1,0},
         	{1,1,0,1},
         	{1,0,1,0}};
	mincut(G,0,2,4);
	return 0;
}
