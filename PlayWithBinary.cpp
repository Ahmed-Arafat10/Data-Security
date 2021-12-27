// This Code WIll be used in DES Algorithm to convert plaintext into binart then into 64-bits blocks , ans after
// encryption to convert binary encrypted into ciphertext 
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//Convert From Binary To Decimal Function
ll BinaryToChar(string Text)
{
    ll res = 0 ;
    for(ll i = 0; i<Text.size(); i++)
    {
        if(Text[i] == '1') res += pow(2,Text.size()-(i+1));
    }
    return res;
}
int main()
{
//Convert From Binary To Decimal Then to A Character
    
      string str;
      // cin>>str;
      ll x = BinaryToChar(str);
      //cout<<x;
      char c = (char)x;
      //cout<<c;
    

//------------------------------------------------------------

//Convert string From Decimal To Binary Then Create a 64-Bits Block for DES Alogrithm
    
     string Text;
     getline(cin,Text);
     vector<string> CharInBinary;
     for(ll i =0; i<Text.size(); i++)
     {
         if(Text[i] == ' ') continue;
         char c = Text[i];
         ll x = c;
         //cout<<x;
         string res;
         stack<char>st;
         while(x>0)
         {
             if(x & 1)st.push('1');
             else st.push('0');
             x/=2;
         }
         while(!st.empty())
         {
             // cout<<st.top();
             res+=st.top();
             st.pop();
         }
         CharInBinary.push_back(res);
         //cout<<" ";
     }
     for(auto &it : CharInBinary )cout<<it<<" ";
     puts("");
     vector<string> Blocks;
     ll cnt = 0;
     string ss = "";
     for(ll i = 0; i<CharInBinary.size(); i++)
     {
         ss += CharInBinary[i];
         cnt += 7;
         if( cnt == 63)
         {
             Blocks.push_back(ss);
             cnt = 0, ss ="";
         }
     }
     Blocks.push_back(ss);
     for(auto &it : Blocks) cout<<it<<" ";
     
}
