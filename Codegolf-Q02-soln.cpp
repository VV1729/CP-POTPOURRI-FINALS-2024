#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll rui[101010];
ll nxt[3][101010];
ll eq[101010];
ll dp[101010];
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	rui[i + 1] = (rui[i] + s[i] - '#' + 1) % 3;
	nxt[0][s.size()] = nxt[1][s.size()] = nxt[2][s.size()] = eq[s.size()] = eq[s.size() - 1] = s.size() + 10;
	nxt[rui[s.size()]][s.size()] = s.size();
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (i != 0 && s[i] == s[i - 1])
		    eq[i - 1] = i;
		else if (i != 0)
		    eq[i - 1] = eq[i];
		for (int j = 0; j < 3; j++)
		{
			if (rui[i] == j)nxt[j][i] = i;
			else nxt[j][i] = nxt[j][i + 1];
		}
	}
	dp[0] = 1;
	for (int i = 0; i < s.size(); i++)
	{
		int a, b;
		if (s[i] == '#')
		    a = i + 1;
		else if (eq[i] <= s.size())
		    a = nxt[(rui[i] + 1) % 3][eq[i] + 1];
		else 
		    a = -1;
		if (s[i] == '$')
		    b = i + 1;
		else if (eq[i] <= s.size())
		    b = nxt[(rui[i] + 2) % 3][eq[i] + 1];
		else 
		    b = -1;
		if (a != -1)
		    dp[a] = (dp[a] + dp[i]) % mod;
		if (b != -1)
		    dp[b] = (dp[b] + dp[i]) % mod;
	}
	ll r = 0;
	if (eq[0] <= s.size())
	{
		for (int i = 1; i <= s.size(); i++)
		    if (rui[i] == rui[s.size()])
		        r += dp[i];
	}
	else 
	    r += dp[s.size()];
	printf("%lld\n", r%mod);
}
