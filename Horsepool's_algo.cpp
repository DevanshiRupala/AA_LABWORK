#include <bits/stdc++.h>

using namespace std;

int main()
{
	string text = "this_is_a_test_text";
	string pattern = "text";
	int n = text.length();
	int m = pattern.length();
	int shift[26];
	for(int i=0;i<26;i++)
	{
    	shift[i]=m;
	}
	for(int i=0;i<m-2;i++)
	{
    	shift[pattern[i]-'a']=m-1-i;
	}
	int j = 0;
	while(j + m <= n)
	{
    	if(pattern[m-1] == text[j+m-1])
    	{
        	int i = m-2;
        	while(i >= 0 && pattern[i] == text[j+i])
           	i--;
        	if(i == -1)
        	cout << j << " ";
    	}
    	if(text[j+m-1] == '_')
    	j = j+m;
    	else
    	j = j + shift[text[j+m-1]-'a'];
	}
	return 0;
}
