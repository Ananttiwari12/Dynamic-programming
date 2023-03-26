#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n]; int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    bool dp[n+1][sum+1];
    for(int i=0;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]= dp[i-1][j]|dp[i-1][j-a[i-1]];
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    int ans=0;
    for(int i=0;i<=(sum/2);i++){
        if(dp[n][i]==1){
            ans=i;
        }
    }
    cout<<abs(sum-2*ans)<<endl;

    }
    return 0;
}