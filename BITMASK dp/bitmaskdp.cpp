#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[21][1<<21];
int cost[21][21];

int solve(int i,int n, int mask){
	if(i==n)return 0;
	if(dp[i][mask]!=-1)dp[i][mask];

	int ans=INT_MAX;
	for(int j=0;j<n;j++){
        if(mask&(1<<j))
		ans=min(ans,cost[j][i]+solve(i+1,n,mask^(1<<j)));
	}
	return dp[i][mask]=ans;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>cost[i][j];
    	}
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,n,(1<<n)-1);
    
    
    return 0;
}