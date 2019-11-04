#include <bits/stdc++.h>
using namespace std;
void dfs2(vector<int>* adjlist, int n, int* visited, int start)
{
    visited[start] = 1;
    cout<<start<<" ";
    for(int i=0;i<adjlist[start].size();i++)
    {
        int cv = adjlist[start][i];
        if(!visited[cv])
        {
            dfs2(adjlist,n,visited,cv);
        }
    }
}

void dfs(vector<int>* adjlist, int n)
{
    int visited[n] = {0};
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            {dfs2(adjlist,n,visited,i);}
    }
}
 
int main()
{
	int T;
	cin>>T;
	while(T)
	{
    	int v,e;
    	cin>>v>>e;
    	vector<int> adjlist[v];
    	for(int i=0;i<e;i++)
    	{
        	int x,y;
        	cin>>x>>y;
        	adjlist[x].push_back(y);
        	adjlist[y].push_back(x);
    	}
    	dfs(adjlist,v);
    	T--;
	}
    return 0;
}
