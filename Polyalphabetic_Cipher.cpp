#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string ToLowChar(string str, ll sz)
{
    for(ll i = 0; i<sz; i++) str[i] = tolower(str[i]);
    return str;
}
void Encryption(ll __P,ll __C)
{
    ll __X = __P + __C;
    char __R = 'a'+ (__X % 26);
    cout<<__R;
}
string Decryption(ll __P,ll __C)
{
    ll __X = __P - __C;
    if(__X < 0) __X += 26;
    char __R = 'a'+ (__X % 26);
    cout<<__R;
}
int main()
{
    char Type;
    string Plain,Key;
    printf("Please Enter Plain/Chiper Text:\n");
    getline(cin,Plain);
    printf("Please Enter Key:\n");
    cin>>Key;
    printf("Please Enter (e) o Encrypt or (d) to Decrypt:\n");
    cin>>Type;
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
        if(Type =='e') Encryption(__P,__C);
        else Decryption(__P,__C);
    }
}
/*
I/P:
wearediscoveredsaveyourself
deceptive
e
----
O/P:
zicvtwqngrzgvtwavzhcqyglmgj


TIHJRG
ART
d
*/
