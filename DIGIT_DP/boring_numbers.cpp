#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[20][2][2][2];

int solve(string &R, int n,bool even, bool leading, bool tight){

	if(n==0) return 1;

	if(dp[n][even][leading][tight]!=-1) return dp[n][even][leading][tight];
	if(even){
		vector<int>digits={0,2,4,6,8};

		int ans=0;
		int upper_bound= tight? (R[R.length()-n]-'0'):9;



		for(int dig: digits){
			if(dig<=upper_bound){
			ans+=solve(R,n-1,0,0, tight&(upper_bound==dig)) ;
		}
		}
		return dp[n][even][leading][tight]=ans;
	}

	else{

		vector<int>digits={1,3,5,7,9};

		int ans=0;
		int upper_bound=tight ? (R[R.length()-n]-'0'):9;

		if(leading==1)
		ans+=solve(R,n-1,0,1,0);

		for(int dig: digits){

			if(dig<=upper_bound){
			ans+=solve(R,n-1,1,0, tight&(dig==upper_bound));
		}
	}
		return dp[n][even][leading][tight]=ans;

	}

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
    for(int i=0;i<t;i++){
    int L,R; cin>>L>>R;

    L--;

    string l=to_string(L);
    string r=to_string(R);


    cout<<"Case #"<<i+1<<": ";
    memset(dp,-1,sizeof(dp));
    int ans1=solve(r,r.length(),0,1,1);
    memset(dp,-1,sizeof(dp));
    int ans2=solve(l,l.length(),0,1,1);
    cout<<ans1- ans2<<endl;


}
    return 0;
}