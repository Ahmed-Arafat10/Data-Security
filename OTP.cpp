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
    for(char c = 'a'; c<='z'; c++)
    {
        v1.push_back(c);
    }
HERE:
    string OTP;
    ll cnt = 0;
    while(cnt != sz)
    {
        ll Random = rand() % v1.size();
        OTP += v1[Random];
        //swap(v1[Random],v1[v1.end()-1]);
        //v1.erase(v1.end()-1);
        cnt++;
    }
    if(UniqueOTP[OTP] != 0) goto HERE;
    else UniqueOTP[OTP]++;
    return OTP;
}
string CipherEncrypt(string Plain, string OTP)
{
    string Cipher;
    for(ll i =0; i<Plain.size(); i++)
    {
        if(Plain[i] == ' ')
        {
            cout<<" ";
            continue;
        }
        ll __O = OTP[i] -'a';
        ll __P = Plain[i] - 'a';
        if(__O < __P) __O += 10;
        char __R = ( (__O - __P) % 26 )+ 'a'  ;
        Cipher+= __R;
        cout<<__R;
    }
    puts("");
    return Cipher;
}

void CipherDecrypt(string Cipher, string OTP)
{
    for(ll i = 0; i<Cipher.size(); i++)
    {
        if(Cipher[i] == ' ')
        {
            cout<<" ";
            continue;
        }
        ll __O = OTP[i] -'a';
        ll __P = Cipher[i] - 'a';
        if(__O < __P) __O += 10;
         char __R = ( (__O - __P) % 26 ) + 'a'  ;
        cout<<__R;
    }
    puts("");
}

int main()
{
    srand((unsigned) time(NULL));
    while(true)
    {
        printf("Please Enter Text you want to encrypt\n");
        string Plain;
        getline(cin,Plain);
        Plain = ToLowChar(Plain,Plain.size());
        string OTP = GenerateOTP(Plain.size());
        cout<<"Unique OTP is: "<<OTP<<"\n";
        string Cipher = CipherEncrypt(Plain,OTP);
        cout<<"THIS CIPHER"<<Cipher<<"\n";
        CipherDecrypt(Cipher,OTP);
    }
}

/*

*/
