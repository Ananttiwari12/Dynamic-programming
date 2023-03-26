#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int p[1001][1001];
int dp[1001][1001];

bool isPallindrome(string s, int i, int j){
	if(i==j) return true;

	while(i<=j){
		if(s[i]!=s[j]){
			return false;
		}
		i++;j--;
	}
	return true;
}

int solve(string s, int i, int j){
	if(i>=j) return 0;

	if(p[i][j]==1) return 0;

	if(isPallindrome(s,i,j)){
		p[i][j]=1;
		return 0;
	}

	int mn=INT_MAX;	
	for(int k=i;k<=j-1;k++){

		if(dp[i][k]==-1) dp[i][k]=solve(s,i,k);
		if(dp[k+1][j]==-1) dp[k+1][j]= solve(s,k+1,j);

		int temp= 1+ dp[i][k]+ dp[k+1][j];
		mn=min(mn,temp);
	}
	return dp[i][j]=mn;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s; cin>>s;

    memset(dp,-1,sizeof(dp));
    memset(p,-1,sizeof(p));

    cout<<solve(s,0,s.length()-1)<<endl;
    

    
   
    return 0;
}