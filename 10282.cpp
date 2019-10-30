#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string>dict;
    string t, first, second;
    
    while(getline(cin, t) && t != "")
    {
        stringstream ss(t);
        ss>>first>>second;
        dict[first] = second;
        dict[second] = first;
    }

    while(cin>>t)
    {
        if(dict[t] == "")
            cout<<"eh"<<endl;

        else
        {
            cout<<dict[t]<<endl;
        }
        
    }

    return 0;
}