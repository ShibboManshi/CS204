#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int>* adjlist, int n)
{
    queue<int> q;
    q.push(0);
    int visited[n] = {0};
    visited[0] = 1;
    for(int j=0;j<n;j++)
    {
        
        if(!visited[j])
        {
            while(!q.empty())
            {
                int cv = q.front();
                q.pop();
                cout<<cv<<" ";
                for(int i=0;i<adjlist[cv].size();i++)
                {
                    int ng = adjlist[cv][i];
                    if(!visited[ng])
                    {
                        visited[ng] = 1;
                        q.push(ng);
                    }
                }
            }
            
        }
        
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
    	bfs(adjlist,v);
    	T--;
	}
    return 0;
}

