/*
DES Algorithm | Data Encryption Standard
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll Binary[2] = {0,1};
int main()
{
    srand((unsigned) time(NULL));
    vector<ll>Key;
    vector<ll>bit64OfKey;
    // Create a Key of Binary string of 64-bit
    cout<<"Key In Binary Is: ";
    for(ll i = 0; i<64; i++)
    {
        ll bit = rand() % 2;// Generate whether 0 or 1
        Key.push_back(bit);
        //Debug
        cout<<Key[i];
        bit64OfKey.push_back(i+1); // Store index of bits from 1 -> 64
    };
    vector<ll>bit64OfKeyTemp = bit64OfKey;
    vector<ll>InitialPremutation;
    puts("");
    cout<<"Premutation Index (Include All 64-bits) : ";
    while(!bit64OfKeyTemp.empty())
    {
        ll bit = rand() % bit64OfKeyTemp.size();
        InitialPremutation.push_back(bit64OfKeyTemp[bit]);
        bit64OfKeyTemp.erase(bit64OfKeyTemp.begin() + bit);
        cout<<InitialPremutation.back()<<" ";
    }
    puts("");
    puts("");
    //cout<<"SIZE"<<InitialPremutation.size()<<"\n";
    vector<ll>PremutationChoice = InitialPremutation;
    ll idx = 0, i = 1;
    while(i<=8)
    {
        if(PremutationChoice[idx] == 8 || PremutationChoice[idx] == 16|| PremutationChoice[idx] == 24 || PremutationChoice[idx]== 32 || PremutationChoice[idx] == 40 || PremutationChoice[idx] == 48|| PremutationChoice[idx] == 56 || PremutationChoice[idx] == 64)
        {
            PremutationChoice.erase(PremutationChoice.begin() + idx);
            i++;
        }
        else idx++;
    }
    //Debug
    //cout<<"Hi"<<PremutationChoice.size();

    string Kp;
    for(auto &it : PremutationChoice)
    {
        if(Key[it-1] == 1)   Kp += '1';
        else Kp += '0';

    }
    cout<<"key After Premutation & filtaring 8 Parity Bits : "<<Kp;
    //cout<<Kp.size();
    puts("");
    puts("");
    ll RoundNumOfShifts[] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    vector<string>KEYn;
    string KLeft = Kp.substr(0,28);
    string KRight = Kp.substr(28,56);
    cout<<"Left Key                                      Right Key\n";
    cout<<KLeft<<"-------"<<KRight;
    puts("");
    puts("");
    for(ll i =0; i<16; i++)
    {
        if(RoundNumOfShifts[i] == 1)
        {
            KLeft+=KLeft[0];
            KLeft.erase(KLeft.begin());
            //--
            KRight+=KRight[0];
            KRight.erase(KRight.begin());
        }
        else
        {
            KLeft+=KLeft[0];
            KLeft+=KLeft[1];
            KLeft.erase(KLeft.begin(),KLeft.begin()+2);
            //--
            KRight+=KRight[0];
            KRight+=KRight[1];
            KRight.erase(KRight.begin(),KRight.begin()+2);
        }
        string KEY = KLeft + KRight;
        // cout<<KEY<<"\n";
        KEYn.push_back(KEY);
    }
    // cout<<KLeft<<"-------"<<KRight;
    cout<<"\n-------------\n";
    for(auto &it:KEYn) cout<<it<<"\n";
    vector<ll>PremutationChoice2_Temp;
    for(ll i = 1; i<=56; i++) PremutationChoice2_Temp.push_back(i);
    vector<ll>PremutationChoice2;
    puts("");
    while(!PremutationChoice2_Temp.empty())
    {
        ll bit = rand() % PremutationChoice2_Temp.size();
        PremutationChoice2.push_back(PremutationChoice2_Temp[bit]);
        PremutationChoice2_Temp.erase(PremutationChoice2_Temp.begin() + bit);
        cout<<PremutationChoice2.back()<<" ";
    }
    cout<<"\n-------------\n";
    vector<string>KeyForRoundx;
    for(ll i = 0; i<KEYn.size(); i++)
    {
        string Temp;
        for(ll j = 0; j<PremutationChoice2.size(); j++)
        {
            if(j != 9 && j != 18 && j != 22 && j != 25 && j != 35 && j != 38 && j != 43 && j != 54)
                Temp += KEYn[i][PremutationChoice2[j]-1];

        }
        KeyForRoundx.push_back(Temp);
        cout<<KeyForRoundx.back()<<"\n";
    }
    //cout<<KeyForRoundx.size(); // OP 16 Key for each round
    cout<<KeyForRoundx[0].size(); // OP 48 Each key is 56 bits size as 8 bits are execluded

    cout<<"\n-------------\n";
    string PlainText="0101010101010101010101010101010101010101010101010101010101010101";
    //cin>>PlainText;
    //cout<<PlainText.size();//OP 64
    string LPT = PlainText.substr(0,32);
    string RPT = PlainText.substr(32,64);
    string PlainTextIP ;
    for(auto &it :InitialPremutation)
    {
        PlainTextIP += PlainText[it-1];
    }
    cout<<PlainText<<"\n";
    cout<<PlainTextIP;

    cout<<"\n-------------\n";
    cout<<"\n-------------\n";
    cout<<RPT<<"\n\n";
    string ExpPremRPT;
    ll L = 0, EP_L = 0;
    while(L<32 && EP_L < 48)
    {
        cout<<L+1<<"><"<<EP_L+1<<"\n";
        if (EP_L == 0)
        {
            ExpPremRPT += RPT[RPT.size()-1];
            EP_L++;
        }
        else if( (EP_L+1) % 6 == 0)
        {
            ExpPremRPT += RPT[L];
            //cout<<L-1<<"><"<<EP_L<<"\n";
            ExpPremRPT += RPT[L-1];
            EP_L += 2;
        }
        else
        {
            ExpPremRPT += RPT[L];
            EP_L++,L++;
        }
        // cout<<"hi";
    }
    ExpPremRPT+=RPT[0];
    //cout<<ExpPremRPT;
    //cout<<ExpPremRPT.size();




}
