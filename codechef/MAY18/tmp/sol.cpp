/*
 * @author Santosh Kumar Shaw (devsks)
 * @quote "Code like there's no tommorow!"
 */
#include "bits/stdc++.h"
#define FOR(X,Y) for(ll X = 0; X < Y; ++X)
#define mod 1000000007
#define ll long long
using namespace std;
 
ll arr[100004],brr[100004];
ll getInd(ll n, ll x)
{
	ll low = 0, high = n-1,mid;
	while(low <=  high)
	{
		mid = low+high>>1;
		if(brr[mid]==x)
			return mid;
		else if(brr[mid] > x)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}
int main(void)
{
    ll t;
   	scanf("%lli",&t);
    FOR(tt,t)
    {
        ll n, q, x;
		scanf("%lli %lli",&n,&q);
		unordered_map<ll,ll> mymap;
		
		FOR(i,n)
		{
			scanf("%lli",&arr[i]);
			brr[i] = arr[i];
			mymap[arr[i]] = i;
		}
		sort(brr, brr+n);
		
		while(q--)
		{
			scanf("%lli",&x);
			ll low = 0, high = n-1,mid,ind1=0,ind2=0,flag=0;
			ll index = mymap[x];
			ll lSum = getInd(n, x);
			ll rSum = n -lSum -1;
			
		//	--index;
 
			while(low <= high)
			{
				mid = low+high>>1;
				
				if( mid == index)
					break;
				else if(mid < index)
				{
					if(arr[mid] > x)
					{
						if(lSum > 0)
						{
							++ind1;
						}
						else
						{
							flag=1;
							break;
						}
					}
					--lSum;
 
					low  = mid+1;
				}
				else
				{
					if(arr[mid] < x)
					{
						if(rSum >0)
						{
							++ind2;
							
						}
						else
						{
							flag=1;
							break;
						}
					}
					--rSum;
					high = mid-1;
								
				}
 
			}
			if(flag || rSum < 0 || lSum < 0)
				puts("-1");
			else
				printf("%lli\n",max(ind1,ind2));
 
		}
 
    	
    }    
    return 0;
}    