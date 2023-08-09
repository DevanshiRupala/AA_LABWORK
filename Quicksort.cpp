#include <bits/stdc++.h>

int partition(int a[],int p,int r)
{
	int x = a[r];
	int i = p-1;
	int j;
    
	for(j=p;j<r;j++)
	{
    	if(a[j]<=x)
    	{
        	i++;
        	swap(a[i],a[j]);
    	}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

int randomized_partition(int a[],int p,int r)
{
	srand(time(0));
	int i = p+rand()%(r-p+1);
	swap(a[i],a[r]);
	return partition(a,p,r);
}

void randomized_quicksort(int a[],int p,int r)
{
	if(p<r)
	{
    	int q = randomized_partition(a,p,r);
    	randomized_quicksort(a,p,q-1);
    	randomized_quicksort(a,q+1,r);
	}
}

int main()
{
	int a[101];
	for(int i=100;i>=0;i--)
	{
    	a[i-1]=i;
	}
	randomized_quicksort(a,0,100);
	for(int i=0;i<101;i++)
	{
    	cout << a[i] << " ";
	}

	return 0;
}
