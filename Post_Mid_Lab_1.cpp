#include<bits/stdc++.h>
using namespace std;
int partition(float arr[], int l, int r, float k);
float FindMedian(float arr[],int n)
{
    sort(arr,arr+n);
    return arr[n/2];
}
float KthSmallest(float arr[], int l,int r, int k)
{
    int n=r-l+1;
    float median[(n+4)/5];
    int i;
    for(i=0;i<n/5;i++)
        median[i]=FindMedian(arr+l+i*5,5);
    if(i*5<n)
    {
        median[i]=FindMedian(arr+l+i*5,n%5);
        i++;
    }
    float medofMed=(i==1)?median[i-1]:KthSmallest(median,0,i-1,i/2);
    int pos=partition(arr,l,r,medofMed);
    if(pos-l==k-1)
        return arr[pos];
    if(pos-l>k-1)
        return KthSmallest(arr,l,pos-1,k);
    return KthSmallest(arr,pos+1,r,k-pos+l-1);
}
void swap(float *a,float *b)
{
    float temp=*a;
    *a=*b;
    *b=temp;
}
int partition(float arr[],int l, int r, float x)
{
    int i;
    for(i=l;i<r;i++)
        if(arr[i]==x)
        break;
    swap(&arr[i],&arr[r]);
    i=l;
    for(int j=l;j<=r-1;j++)
    {
        if(arr[j]<=x)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}    
int main()
{
    int Test_cases;
    cin>>Test_cases;
    while(Test_cases)
    {
        int k;
        cin>>k;
        int a[k][2];
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<2;j++)
                cin>>a[i][j];
        }
        float d[k];
        for(int i=0;i<k;i++)
            d[i]=sqrt(a[i][0]*a[i][0]+a[i][1]*a[i][1]);
        if(k%2==0)
        {
            float Radius1=KthSmallest(d,0,k-1,k/2);
            cout<<Radius1<<"\n";
        }
        if(k%2!=0)
        {
            int t=k/2+1;
            float Radius2=KthSmallest(d,0,k-1,t);
            cout<<Radius2<<"\n";
        }
        Test_cases--;
    }
    return 0;
}


