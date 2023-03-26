#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[20][10][2][2];


int solve(string &R, int n,int prev,bool leading_zeros, bool tight){
	if(n==0) return 1;

	if(dp[n][prev][leading_zeros][tight]!=-1) return dp[n][prev][leading_zeros][tight];

	int ub= tight? R[R.length()-n]-'0' :9;
	int ans=0;
	for(int dig=0;dig<=ub;dig++){

		if(dig==prev and leading_zeros==0) continue;

			ans+=solve(R,n-1,dig,leading_zeros & (dig==0),tight&(dig==ub));
		
		
	}
	return dp[n][prev][leading_zeros][tight]=ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int a,b; cin>>a>>b;
    int c=a;
    if(a!=0) a--;
    string l=to_string(a);
    string r=to_string(b);

    memset(dp,-1,sizeof(dp));
    int ans1=solve(r,r.length(),-1,1,1);

    memset(dp,-1,sizeof(dp));
    int ans2=solve(l,l.length(),-1,1,1);
    if(c==0) cout<<ans1-ans2+1;
    else cout<<ans1-ans2;


    
    
    return 0;
}