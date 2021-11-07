#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<char,ll> mp;
map<char,ll> mp_IDX;
void SubstituteCipher(string Text,string KeyWord,bool Type)
{
    string CT;
    for(ll i = 0; i<KeyWord.size(); i++)
    {
        Text[i] = tolower(Text[i]);
        mp[ KeyWord[i] ]++;
        if( mp[KeyWord[i]] == 1)
        {
            CT += KeyWord[i];
            mp_IDX[ KeyWord[i] ] = CT.size()-1;
        }
    }

    for(char c = 'a'; c<='z'; c++)
    {
        if(mp[c] == 0)
        {
            CT += c;
            mp_IDX[ c ] = CT.size()-1;
        }
        if(CT.size() == 26) break;
    }

    for(ll i = 0; i<Text.size(); i++)
    {
        ll Cur;
        if(!Type)
        {
            Cur = Text[i] - 'a';
            cout<<CT[Cur];
        }
        else
        {
            char c = mp_IDX[Text[i]] + 'a';
            cout<<c;
        }

    }
}

int main()
{
    // Text to Encrypt/Decrypt
    string Text,KeyWord;
    //Key is a number
    //if its a letter convert it into number {easy}
    ll Key;
    //0 For Encryption
    //1 For Decryption
    bool Type;
    cin>>Text>>KeyWord>>Type;
    SubstituteCipher(Text,KeyWord,Type);
}
/*
escape
security
0
----------
rncskr

+++++++++++++++++++++

hjv
security
1
---------
now

++++++++++++++++++++++

okdkqaep
identifiers
1
-----------
robotics
*/
