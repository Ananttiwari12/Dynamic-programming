#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int cnt=0;


int dp[101][101];


int LCS(string x, string y, int n, int m){
	cnt++;
	if(n==0 || m==0) return 0;

	if(dp[n][m]!=-1) return dp[n][m];

	if(x[n-1]==y[m-1]){
		dp[n][m]= 1+LCS(x,y,n-1,m-1);
	}
	else{
		dp[n][m]= max(LCS(x,y,n,m-1), LCS(x,y,n-1,m));
	}
	return dp[n][m];

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string x,y;
    cin>>x>>y;
    int n=x.length();
   	int m=y.length();

   	memset(dp,-1,sizeof(dp));

    // cout<<LCS(x,y,n,m)<<endl;

	LCS(x,y,n,m);

	cout<<dp[n][m]<<endl;

    cout<<cnt<<endl;

    

    
    
    return 0;
}