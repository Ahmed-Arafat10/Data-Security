#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string ToLowChar(string str, ll sz)
{
    for(ll i = 0; i<sz; i++) str[i] = tolower(str[i]);
    return str;
}
int main()
{
    string Plain,Key;
    getline(cin,Plain);
    cin>>Key;
    Plain = ToLowChar(Plain,(ll)Plain.size());
    Key = ToLowChar(Key,(ll)Key.size());
    string Temp = Key;
    while(Key.size() < Plain.size())
    {
        Key += Temp;
    }
    //Debug
    //cout<<Key<<"\n";
    cout<<"CipherText: ";
    for(ll i = 0; i<Plain.size(); i++)
    {
        ll __P = Plain[i] - 'a';
        ll __C = Key[i] - 'a' ;
        ll __X = __P + __C;
        char __R = 'a'+ (__X % 26);
        cout<<__R;
    }
}
/*
I/P:
wearediscoveredsaveyourself
----
O/P:
deceptive
*/
