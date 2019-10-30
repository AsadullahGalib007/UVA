#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    map<int, int>m;
    int t;
    while((scanf("%d",&t)) != EOF)
    {
        if(m[t] == 0){
            m[t]++;
            v.push_back(t);
        }
        	
        else
            m[t]++;
    }
    
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" "<<m[v[i]]<<endl;
    }
    return 0;
}