#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[1001][1001];

int solve(int arr[],int i, int j){

	if(i>=j) return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	int mn=INT_MAX;

	for(int k=i;k<j;k++){
		int temp= solve(arr,i,k)+solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];

		if(temp<mn){
			mn=temp;
		}
	}

	return dp[i][j]=mn;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int n; cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    for(int i=0;i<=n;i++){
    	for(int j=0;j<=n;j++){
    		dp[i][j]=-1;
    	}
    }

    cout<<solve(a,0,n-1);



    
    
    return 0;
}