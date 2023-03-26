#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[1001][1001];

int solve(int e, int f){

	if(f==0 || f==1) return f;

	if(e==1) return f;

	if(dp[e][f]!=-1) return dp[e][f];

	int mn=INT_MAX;
	int l=1,r=f;
	while(l<=r){

		int mid=(l+r)/2;

		if(dp[e-1][mid-1]==-1) dp[e-1][mid-1]=solve(e-1,mid-1);
		if(dp[e][f-mid]==-1) dp[e][f-mid]=solve(e,f-mid);
		int temp= 1+max(dp[e-1][mid-1], dp[e][f-mid]);
		mn=min(mn,temp);

		if(dp[e-1][mid-1]<dp[e][f-mid]){
			l=mid+1;
		}
		else r= mid-1;
	}

	return dp[e][f]=mn;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp,-1,sizeof(dp));

    int k,n; cin>>k>>n;

    cout<<solve(k,n);
    
    return 0;
}