#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

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

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
    	dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
    	dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(x[i-1]==y[j-1]){
    			dp[i][j]=1+dp[i-1][j-1];
    		}
    		else{
    			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    		}
    	}
    }


    int i=n,j=m;

    string res="";

    while(i>0 and j>0){
    	if(x[i-1]==y[j-1]){
    		res.push_back(x[i-1]);
    		i--;
    		j--;
    	}
    	else{
    		if(dp[i-1][j]>dp[i][j-1]){
    			i--;
    		}
    		else{
    			j--;
    		}
    	}
    }

    reverse(res.begin(), res.end());

    cout<<res<<endl;
    
    return 0;
}