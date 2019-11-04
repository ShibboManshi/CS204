#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
void prim(vector<pair<int,int> > adjlist[], int n)
{
    int weight[n];
    int parent[n];
    int visited[n] = {0};
    for(int i=0;i<n;i++)
    {
        weight[i] = INT_MAX;
        parent[i] = -1;
    }
    parent[0] = 0;
    weight[0] = 0;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; // (weight,source)
    pq.push(make_pair(0,0));
    int count = 0;
    while(!pq.empty())
    {
        int cv = pq.top().second;
        pq.pop();
        count++;
        visited[cv] = 1;
        for(int i=0;i<adjlist[cv].size();i++)
        {
            int ng = adjlist[cv][i].first;
            int ngw = adjlist[cv][i].second;
            if( !visited[ng] && weight[ng] > ngw + weight[cv]) 
            {
                weight[ng] = ngw + weight[cv];
                pq.push(make_pair(weight[ng],ng));
                parent[ng] = cv;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<weight[i]<<endl;
    }  
}
int main()
{   
    int v,e;
    cin>>v>>e;
    vector<pair<int,int> > adjlist[v];
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>w>>x>>y;
        adjlist[x].push_back(make_pair(y,w));
        adjlist[y].push_back(make_pair(x,w));
    }
    prim(adjlist,v);
    return 0;
}
