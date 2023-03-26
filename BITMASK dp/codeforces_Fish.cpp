#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

float prob[20][20];
float dp[1<<19];

float pMove(int prev_mask, int j, int &n){

	int k=__builtin_popcount(prev_mask);
	int deno=(k*(k-1))/2;

	float moveprob=0;
	for(int i=0;i<n;i++){

		if((1<<i)&prev_mask){
			moveprob+=prob[i+1][j+1];
		}
	}	
	return moveprob/(deno*1.0);
}


float solve(int& n,int mask){

	int alive=__builtin_popcount(mask);
	if(alive==n)return 1;
	if(dp[mask]>  -0.9)return dp[mask];

	float ans=0;
	for(int fish=0;fish<n;fish++){

		if(!(mask & (1<<fish))){
			int prev_mask=mask^(1<<fish);
			float prev_day=solve(n,prev_mask);
			ans+=prev_day*pMove(prev_mask,fish,n);
		}
	}
	return dp[mask]=ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;   

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		cin>>prob[i][j];
    	}
    }

    memset(dp,-1,sizeof(dp));
   	
   	for(int i=0;i<n;i++){
   		cout<<fixed<<setprecision(10)<<solve(n,(1<<i))<<" ";
   	}
    return 0;
}