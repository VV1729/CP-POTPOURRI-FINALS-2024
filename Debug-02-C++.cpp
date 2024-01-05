#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define ll long long
#define amax(a,n) *max_element(a,a+n)
#define amin(a,n) *min_element(a,a+n)
#define vmax(a) *max_element(a.begin(),a.end())
#define vmin(a) *min_element(a.begin(),a.end())
#define rev(a) a.rbegin(), a.rend()
#define vsort(v) sort(v.begin(),v.end())
#define asort(a) sort(a,a+n)
#define vresort(v) sort(rev(v))
#define rev(a) a.rbegin(), a.rend()
#define rsrt(v) sort(rev(v))
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <b; i++)
#define vdel(x,i) x.erase(x.begin()+i)
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll gcd(ll a, ll b)
{
  if (b == 0) 
    return a;
  return gcd(b, a % b);
}
int main()
    {
	ios::sync_with_stdio(0); 
        cin.tie(NULL);
        cout.tie(NULL);
        
              ll n,k;
              cin>>n>>k;
              string s1=to_string(n);    
              ll f[10]={0};
              ll temp[k];
              REP(i,0,k)
                {
                 cin>>temp[i];
                }
               //cout<<s1<<'\n';          
               REP(i,0,k)
                {
                while(temp[i]>0)
                    {
                     f[temp[i]%10]++;
                     temp[i]=temp[i]/10;
                    }
                    
                }
              ll p=9;    
              REP(i,0,s1.length())    
                {
                    while(p>s1[i]-'0')
                        {
                            REP(i,0,f[p])
                                cout<<p;
                            p--;    
                        }
                    
                    cout<<s1[i]-'0';
                    
                }
              while(p!=-1)
                {
                   REP(i,0,f[p])
                       cout<<p;
                    p--;  
                }                
        return 0;    
    }