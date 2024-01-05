#include <bits/stdc++.h>
using namespace std;
#define lld long long int
int main() {
	// your code goes here
	lld n,i,j,k;
	set<lld> A;
	cin>>n;
	lld a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			continue;
		}
		int sum = 0;
		lld temp = a[i];
		while(temp > 0) {
			if (temp%2==1)
				sum++;
			temp/=2;
		}
		if(sum<=2) {
			A.insert(a[i]);
		}
	}
	cout<<A.size()<<endl;
	return 0;
}