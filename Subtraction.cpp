#include<bits/stdc++.h>
using namespace std;
string Sub(string str1, string str2)
{
	string str="";
	int count=1;
	char a='-';
	if(str1.length()<str2.length())
	{
		count=0;
		swap(str1,str2);
	}
	int i,sub=0,carry=0;
	int n1=str1.length(),n2=str2.length();
	reverse(str1.begin(),str1.end());
	reverse(str2.begin(),str2.end());
	for(i=0;i<n2;i++)
	{
		sub=((str1[i]-'0')-(str2[i]-'0')-carry);
		if(sub<0)
		{
			sub=sub+10;
			carry=1;
		}
		else
			carry=0;
		str.push_back(sub+'0');
	}
	for(i=n2;i<n1;i++)
	{
		sub=((str1[i]-'0')-carry);
		if(sub<0)
		{
			sub=sub+10;
			carry=1;
		}
		else
			carry=0;
		str.push_back(sub+'0');
	}
	if(count==0)
	str.push_back(a);
	reverse(str.begin(),str.end());
	return(str);
}
int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;
	cout<<Sub(str1,str2);
	return 0;
}
