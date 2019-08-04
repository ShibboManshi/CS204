#include<bits/stdc++.h>
using namespace std;
string add(string str1, string str2)
{
	string str="";
	if(str1.length()>str2.length())
		swap(str1,str2);
	int n1=str1.length(),n2=str2.length();
	reverse(str1.begin(),str1.end());
	reverse(str2.begin(),str2.end());
	int carry=0;
	int i;
	int sum=0;
	for(i=0;i<n1;i++)
	{
		sum=((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10+'0');
		carry=sum/10;
	}
	for(i=n1;i<n2;i++)
	{
		sum=((str2[i]-'0')+carry);
		str.push_back(sum%10+'0');
		carry=sum/10;
	}
	if(carry)
	str.push_back(carry+'0');
	reverse(str.begin(),str.end());
	return(str);
}
int main(){
	string str1,str2;
	cin>>str1;
	cin>>str2;
	cout<<add(str1,str2);
	return 0;
}
