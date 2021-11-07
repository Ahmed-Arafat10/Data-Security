#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string Alph = "abcdefghijklmnopqrstuvwxyz";

void CaesarCipher(string Text,ll Key,bool Type)
{
    for(ll i = 0; i<Text.size(); i++)
    {
        Text[i] = tolower(Text[i]);
        ll Cur;
        if(!Type) Cur = ( (Text[i] - 'a') + Key) % 26;
        else
        {
            Cur = (Text[i] - 'a') - Key;
            if(Cur < 0) Cur += 26;
        }
        cout<<Alph[Cur];
    }
}
int main()
{
    // Text to Encrypt/Decrypt
    string Text;
    //Key is a number
    //if its a letter convert it into number {easy}
    ll Key;
    //0 For Encryption
    //1 For Decryption
    bool Type;
    cin>>Text>>Key>>Type;
    CaesarCipher(Text,Key,Type);
}
/*
I/P:
hcdmshehdqr
25
1

O/P:
identifiers
*/
