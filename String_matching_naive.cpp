#include <bits/stdc++.h>

using namespace std;

int main()
{
	string text = "This is a test text";
	string pattern = "text";
	int n = text.length();
	int m = pattern.length();
	for(int i=0;i<n-m+1;i++)
	{
    	int j;
    	for(j=0;j<m;j++)
    	{
        	if(text[i+j] != pattern[j])
        	break;
    	}
    	if(j == m)
    	cout << i << " ";
	}
	return 0;
}
