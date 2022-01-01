#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
unordered_map<string,ll>UniqueOTP;

string ToLowChar(string str, ll sz)
{
    for(ll i = 0; i<sz; i++) str[i] = tolower(str[i]);
    return str;
}

string GenerateOTP(ll sz)
{
    vector<char>v1;
    for(char c = '1'; c<='9'; c++) v1.push_back(c);
HERE:
    string OTP;
    ll cnt = 0;
    while(cnt != sz)
    {
        ll Random = rand() % v1.size();
        OTP += v1[Random];
        cnt++;
    }
    if(UniqueOTP[OTP] != 0) goto HERE;
    else UniqueOTP[OTP]++;
    return OTP;
}

void Cipher(string Plain, string OTP, char Type)
{
    if(Type == 'e') cout<<"PlainText Is: ";
    else cout<<"ChiperText Is: ";
    //string Text;
    for(ll i =0; i<Plain.size(); i++)
    {
        ll __O = OTP[i] - '0';
        ll __P = Plain[i] - '0';
        ll __R;
        if(__O < __P) __R = (__O + 10) - __P;
        else __R = __O - __P;
        cout<<__R;
    }
    puts("");
    //return Cipher;
}

int main()
{
    srand((unsigned) time(NULL));
    ll tc;
    cin>>tc;
    while(tc--)
    {
        printf("Please Enter Text : ");
        string Plain;
        cin>>Plain;
        //Plain = ToLowChar(Plain,Plain.size());
        printf("Please Enter (e) to Encrypt, (d) to Decrypt : ");
        char Type;
        cin>>Type;
        string OTP = GenerateOTP(Plain.size());
        cout<<"Unique OTP is: "<<OTP<<"\n";
        Cipher(Plain,OTP,Type);
        puts("");
        puts("");
    }
}
/*
I/P:
1
853759
e

O/P:
Depends On Randomly Generated Unique OTP
*/
