include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	int i,count=0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			count++;
		}
		break;
	}
	if(count==0)
	{
		cout<<"Prime";
	}
	else
	{
		cout<<"Not Prime";
	}
	return 0;
}
