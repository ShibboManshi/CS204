#include<bits/stdc++.h> 
using namespace std; 
bool IsBalanced(string a) 
{ 
    stack<char> s; 
    char x; 
    int count=0;
    for (int i=0; i<a.length(); i++) 
    { 
        if (a[i]=='('||a[i]=='['||a[i]=='{' || a[i]=='<') 
        { 
            s.push(a[i]); 
            continue; 
        } 
        if(a[i]=='|')
        {
            count++;
            if(count%2==1)
            {
                s.push(a[i]);
            }
        }

        if (s.empty()) 
           return false; 

        switch (a[i]) 
        { 
        case ')': 

            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[' || x=='<' || x=='|') 
                return false; 
            break; 

        case '}': 
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[' || x=='<' || x=='|') 
                return false; 
            break; 

        case ']': 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{' || x== '<' || x=='|') 
                return false; 
            break; 


        case '>': 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{' || x== '[' || x=='|') 
                return false; 
            break; 


        case '|':
             if(count%2==0)
             {
                x= s.top();
                s.pop();
                if(x=='(' || x=='[' || x=='{' || x=='<')
                {
                    return false;
                }
             }
             break;
        } 
    } 
    return (s.empty()); 
} 

int main() 
{ 
    int n;
    cin>> n;
    for(int i=0; i<n; i++)
    {
        string a;
        cin>> a;
        if(IsBalanced(a))
        {
            cout<< "YES\n";
        }
        else 
        {
            cout<< "NO\n";
        }
    }
} 
