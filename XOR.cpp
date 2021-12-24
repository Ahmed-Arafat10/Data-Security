#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    string Key,Text,Result;
    char Type;
    cout<<"Please Enter Key in Binary : ";
    cin>>Key;
    cout<<"Please Enter Text In Binary You want To Encrypt/Decrypt : ";
    cin>>Text;
    cout<<"Please Enter (e) to Encrypt , (d) to Decrypt : ";
    cin>>Type;
    for(ll i =0; i<Key.size(); i++)
    {
        if(Key[i] == Text[i] && Key[i] == '1') Result += "0";
        else if(Key[i] == '1' || Text[i] == '1') Result +="1";
        else Result += "0";
    }
    if(Type == 'e') cout<<"Cipher Is : "<<Result;
    else cout<<"Plain Is : "<<Result;
}
/*
I/P:
01010011000111
00110011001100
e

O/P:
01100000001011
--
I/P:
01010011000111
01100000001011
d

O/P:
00110011001100
*/
