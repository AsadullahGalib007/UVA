#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--)
    {
        map<string, string>m1, m2;
        map<string, string>::iterator itr, it;
        string str1, str2, line, key, value;
        getline(cin, str1);
        getline(cin, str2);

        line = str1.substr(1, str1.length()-2); ///removing braces
        istringstream iss1(line);
        while(getline(iss1, key,':')){
            getline(iss1, value, ',');
            m1[key] = value;
        }

        line = str2.substr(1, str2.length()-2); ///removing braces
        istringstream iss2(line);
        while(getline(iss2, key,':')){
            getline(iss2, value, ',');
            m2[key] = value;
        }
        set<string>inc;
        set<string>exc;
        set<string>change;
        set<string>::iterator its;

        for(itr=m2.begin(); itr!=m2.end(); itr++)
        {
            it = m1.find(itr->first);
            if(it == m1.end())
                inc.insert(itr->first);

            else
            {
                if(itr->second != it->second)
                    change.insert(itr->first);
            }
        }

        for(itr=m1.begin(); itr!=m1.end(); itr++)
        {
            it = m2.find(itr->first);
            if(it == m2.end())
                exc.insert(itr->first);
        }

        if(inc.size() == 0 && exc.size() == 0 && change.size() == 0)
            cout<<"No changes"<<endl;

        else
        {
            if(inc.size()>=1)
            {
                its = inc.begin();
                cout<<'+'<<*its;
                its++;
                for(; its!=inc.end(); its++)
                    cout<<','<<*its;
                cout<<endl;
            }
            

            if(exc.size()>=1)
            {
                its = exc.begin();
                cout<<'-'<<*its;
                its++;
                for(; its!=exc.end(); its++)
                    cout<<','<<*its;
                cout<<endl;
            }
            
            if(change.size()>=1)
            {
                its = change.begin();
                cout<<'*'<<*its;
                its++;
                for(; its!=change.end(); its++)
                    cout<<','<<*its;
                cout<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
