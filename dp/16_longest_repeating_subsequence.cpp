#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

	int LongestRepeatingSubsequence(string str){
		    
		    int n=str.length();
		    string s=str;
		    
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++){
		        dp[i][0]=0;
		    }
            for(int i=0;i<=n;i++){
		        dp[0][i]=0;
		    }
		    
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(str[i-1]==s[j-1] and i!=j){
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else{
		                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    
		    return dp[n][n];
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
    cout<<LongestRepeatingSubsequence(s);
    
    return 0;
}