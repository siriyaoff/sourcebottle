#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    int nw, nq;
    int w[30], dt[80001];
    cin>>nw;
    for(int i=0;i<nw;i++) cin>>w[i];
    for(int i=0;i<80001;i++) dt[i]=0;
    dt[-w[0]+40000]=1;
    dt[40000]=1;
    dt[w[0]+40000]=1;
    for(int i=1;i<nw;i++){
        for(int j=0;j<80001;j++){
            if(dt[j]==1){
                if(dt[j-w[i]]==0) dt[j-w[i]]=2;
                if(dt[j+w[i]]==0) dt[j+w[i]]=2;
            }
        }
        for(int j=0;j<80001;j++)
            if(dt[j]==2) dt[j]=1;
    }
    cin>>nq;
    for(int i=0;i<nq;i++){
        int tt;
        cin>>tt;
        if(dt[tt+40000] || dt[-tt+40000]) cout<<"Y ";
        else cout<<"N ";
    }
    return 0;
}