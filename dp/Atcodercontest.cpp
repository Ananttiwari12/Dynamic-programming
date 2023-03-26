#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,l;
    cin>>n>>l;
    int a[n];

    int o=0;
    int se=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)o++;
        else se++; 
    }
    se*=2;
    int oo=o;
    int se2=se;
    int cnt1=0;
    int cnt2=0;
    for(int i=1;i<=l;i++){
        if((i%3==1 || i%3==2) and se!=0){
            se--;
        }
        else if(i%2==0 and o!=0){
            o--;
        }
        if(se==0 and o>=0){
            cnt1++;
            break;
        }
    }
    for(int i=1;i<=l;i++){
        if((i%3==2 || i%3==0) and se2!=0){
            se2--;
        }
        else if(i%2==1 and oo!=0){
            oo--;
        }
        if(se2==0 and oo>=0){
            cnt2++;
            break;
        }
    }

    if(cnt1==1 and cnt2==1) cout<<"Yes";
    else cout<<"No";



    




    return 0;
}