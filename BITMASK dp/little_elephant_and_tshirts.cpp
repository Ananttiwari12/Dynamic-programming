#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[101][(1<<10)+1];

bool people[11][101];
void in(int n)
{
    string s;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        stringstream in(s);
        int a;
        while(in>>a)
        {
            people[i+1][a] = 1;
        }
    }
}


int solve(int shirts, int n, int mask){

	if(mask==(1<<n)-1)return 1;
	// if(mask==0)return 1;
	if(shirts>100)return 0;
	if(dp[shirts][mask]!=-1)return dp[shirts][mask];

	int ans=0;
		for(int j=0;j<n;j++){
		if(people[j+1][shirts]){
			if(!(mask&(1<<j))){
			// if((mask&(1<<j))){
				ans=(ans+solve(shirts+1, n,mask^(1<<j)))%mod;
				ans%=mod;
			}
		}
	}
		ans%=mod;
		ans=(ans+solve(shirts+1,n,mask))%mod;
		return dp[shirts][mask]=ans%mod;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t; cin>>t;

    while(t--){

    	int n; cin>>n;
    	memset(dp,-1,sizeof(dp));
    	memset(people,0,sizeof(people));

    	in(n);
    	cout<<solve(1,n,0)<<endl;
    	// cout<<solve(1,n,(1<<n)-1)<<endl;
    }
    return 0;
}