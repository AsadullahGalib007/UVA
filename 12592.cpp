#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    map<string, string>m;
    int t;
    cin>>t;
    char ch = getchar();
    while(t--)
    {
        
        getline(cin, s1);
        getline(cin, s2);
        m.insert(make_pair(s1,s2));
        //cout<<s1<<"\t"<<s2<<endl;
    }

    int n;
    cin>>n;
    ch = getchar();
    while(n--)
    {
        string str;
        getline(cin, str);
        cout<<m[str]<<endl;
    }
    return 0;
}