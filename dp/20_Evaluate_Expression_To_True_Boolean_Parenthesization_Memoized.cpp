#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1003
#define int long long

int dp[1001][1001][2];

int solve(string s, int i, int j, bool istrue){

	if(i>j) return false;

	if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];

	if(i==j){
		if(istrue==true){
			return s[i]=='T';
		}
		else return s[i]=='F';
	}

	int ans=0;
	for(int k=i+1;k<j;k+=2){
		if(dp[i][k-1][1]==-1) dp[i][k-1][1]=solve(s,i,k-1,1);
		if(dp[i][k-1][0]==-1) dp[i][k-1][0]=solve(s,i,k-1,0);
		if(dp[k+1][j][1]==-1) dp[k+1][j][1]=solve(s,k+1,j,1);
		if(dp[k+1][j][0]==-1) dp[k+1][j][0]=solve(s,k+1,j,0);

		if(s[k]=='&'){
			 if(istrue==true) ans+= (dp[i][k-1][1]*dp[k+1][j][1])%mod;
			 else ans+= ((((dp[i][k-1][1]*dp[k+1][j][0] )%mod+ (dp[i][k-1][0]*dp[k+1][j][1])%mod)%mod + 
			 			 			 			(dp[i][k-1][0]*dp[k+1][j][0])%mod))%mod;
			 ans%=mod;
		}
		else if(s[k]=='|'){
			if(istrue==true) ans+=(((dp[i][k-1][1]*dp[k+1][j][0])%mod + (dp[i][k-1][0]*dp[k+1][j][1])%mod)%mod+
												(dp[i][k-1][1]*dp[k+1][j][1])%mod)%mod;
			else ans+=(dp[i][k-1][0]*dp[k+1][j][0])%mod;
			ans%=mod;
		}
		else if(s[k]=='^'){
			if(istrue==true){
				ans+=((dp[i][k-1][1]*dp[k+1][j][0])%mod+(dp[i][k-1][0]*dp[k+1][j][1])%mod)%mod;
			}
			else{
				ans+=((dp[i][k-1][1]* dp[k+1][j][1])%mod + (dp[i][k-1][0]* dp[k+1][j][0])%mod)%mod;
			}
			ans%=mod;
		}
	}
	return ans%mod;
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

    string s; cin>>s;

    int n=s.length();

    cout<<solve(s,0,n-1,true);


    

    
    
    return 0;
}