#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<pair<int,int>> &a, int x,int l,int r)
{
    if(r>=l)
    {
        int mid=l+(r-l)/2;
        if(a[mid].first==x)
            return mid;
        if(a[mid].first>x)
            return BinarySearch(a ,x,l,mid-1);
        return BinarySearch(a ,x, mid+1, r);
    }
        return -1;
}
int main()
{
    int n,q,maxid=-1,maxrs=-100;
    cin>>n>>q;
    vector<pair<int,int>> A;
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int id,rs;
            cin>>id>>rs;
            pair<int,int>B;
            B.first=id;
            B.second=rs;
            A.push_back(B);
        }
        else if(x==2)
        {
            pair<int,int>B;
            B.first=-1;
            B.second=0;
            A.push_back(B);
        }
        else
        {
            pair<int,int>B;
            B.first=-2;
            B.second=0;
            A.push_back(B);
        }
    }
    vector<int> C;
    for(int i=0;i<q;i++)
    {
        if(A[i].first>0)
            C.push_back(A[i].first);
    }
    vector<pair<int,int>> D;
    sort(C.begin(),C.end());
    int prev=0;
    for(int i=0;i<C.size();i++)
    {
        if(C[i]!=prev)
        {
            pair<int,int> P;
            P.first=C[i];
            P.second=0;
            D.push_back(P);
        }
        prev=C[i];
    }
    for(int i=0;i<q;i++)
    {
        if(A[i].first>0)
        {
            int x=A[i].first;
            int m=BinarySearch(D , x, 0, D.size()-1);
            D[m].second=D[m].second + A[i].second;
            if(D[m].second>maxrs)
            {
                maxrs=D[m].second;
                maxid=D[m].first;
            }
        }
        else if(A[i].first==-1)
        {
            if(maxid==-1)
                cout<<"No data available\n";
            else
                cout<<maxid<<"\n";
        }
        else
            cout<<"Invalid Output\n";
    }
}

