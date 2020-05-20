#include<bits/stdc++.h>
using namespace std;
int link[100],size[100];
int find(int x)
{
    while(x!=link[x])
    {
        x=link[x];
    }
    return x;
}
bool same(int a, int b)
{
    return (find(a) == find(b));
}
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if(size[a]<size[b])
    swap(a,b);
    size[a]+=size[b];
    link[b]=a;
    
}
int main()
{
    int q,e; cin>>q>>e;
    vector<tuple< int, int, int >> v;
    vector<tuple< int, int, int >> f;
    for(int i=0;i<e;i++)
    {
        int r,u,w; cin>>r>>u>>w;
        v.push_back( make_tuple ( w , r , u ));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<q;i++)
    {
        link[i]=i;
        size[i]=1;
    }
    for(int i=0;i<e;i++)
    {
        int a=get<1>(v[i]), b= get<2>(v[i]);
        if(!same(a,b))
        {
            unite(a,b);
            f.push_back( make_tuple ( w , a , b ));
        }
    }
    for(int i=0;i<f.size();i++)
    {
    	cout<<(get<1>(f[i]))<<" "<<(get<2>(f[i]))<<" "(get<0>(f[i]))<<"\n";
	}
    return 0;
}
