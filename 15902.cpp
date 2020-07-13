#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
#define MOD 1000000007
typedef unsigned long long int ulld;
using namespace std;

ulld ct[3001][3001], facto[1501], cdet[3][1500];

ulld ncr(int n, int r){
	if(r==0) return 1;
	if(n==0) return 1;
	if(ct[n][r]!=0) return ct[n][r];
	return ct[n][r]=(ncr(n-1, r-1)+ncr(n-1, r))%MOD;
}

ulld f(int n){
	if(n==0) return 1;
	if(n==1) return 1;
	if(facto[n]!=0) return facto[n];
	ulld t=(n*f(n-1))%MOD;
	return facto[n]=t;
}

ulld c(int n){
	if(n==1) return 2;
	if(cdet[0][n]!=0) return cdet[0][n];
	ulld sigma=0;
	for(int i=2;i<=n-1;i++){
		
		ulld t=((ulld)c(i-1)*(ulld)c(n-i))%MOD;
		sigma+=(t*ncr(2*n, 2*i-1))%MOD;
		sigma=sigma%MOD;
	}
	return cdet[0][n]=(sigma+(ulld)(4*(ulld)c(n-1)*n))%MOD;
}

ulld d(int n){
	if(n==1) return 1;
	if(cdet[1][n]!=0) return cdet[1][n];
	ulld sigma=0;
	for(int i=2;i<=n-1;i++){
		ulld t=(d(i-1)*c(n-i))%MOD;
		sigma+=(t*ncr(2*n-1, 2*i-2))%MOD;
		sigma=sigma%MOD;
	}
	return cdet[1][n]=(sigma+(ulld)(c(n-1)+d(n-1)*(2*n-1)))%MOD;
}

ulld e(int n){
	if(n==1) return 2;
	if(cdet[2][n]!=0) return cdet[2][n];
	ulld sigma=0;
	for(int i=2;i<=n-1;i++){
		ulld t=(d(i-1)*d(n-i))%MOD;
		sigma+=(t*ncr(2*n, 2*i-2))%MOD;
		sigma=sigma%MOD;
	}
	return cdet[2][n]=(sigma+(ulld)(2*d(n)))%MOD;
}

int main()
{
	int L, n, m;
	for(int i=0;i<3001;i++) for(int j=0;j<3001;j++) ct[i][j]=0;
	for(int i=0;i<3001;i++)	ct[i][i]=1, ct[i][1]=i;
	for(int i=0;i<1501;i++) facto[i]=0;
	facto[1]=1, facto[2]=2;
	
	scanf("%d %d", &L, &n);
	vector<int> a(0, 0);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		if(t==1)
			a.push_back(1);
		if(t==2){
			a.push_back(2);
			a.push_back(2);
		}
	}
	scanf("%d", &m);
	vector<int> b(0, 0);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d", &t);
		if(t==1)
			b.push_back(1);
		if(t==2){
			b.push_back(2);
			b.push_back(2);
		}
	}
	int sm=0, alinked=0, blinked=0, cindx=-1, inc=0;
	vector<pair<int, int>> clist;
	for(int i=0;i<L;i++){
		if(a[i]==b[i]){
			if(a[i]==1)
				continue;
			if(alinked && blinked){
				alinked=blinked=0;
			}
			else if(alinked || blinked){
				if(inc==0){
					inc=1;
					cindx++;
					clist.push_back(make_pair(i-1, -1));
				}
				swap(alinked, blinked);
			}
			else
				alinked=blinked=1;
		}
		else{//a[i]!=b[i]
			if(a[i]==1){
				if(blinked){
					if(inc){
						inc=0;
						clist.back().second=i;
					}
					else
						sm++;
					blinked=0;
				}
				else
					blinked=1;
			}
			else{
				if(alinked){
					if(inc){
						inc=0;
						clist.back().second=i;
					}
					else
						sm++;
					alinked=0;
				}
				else
					alinked=1;
			}
		}
	}
	vector<vector<int>> cde(3, vector<int>(0, 0));
	for(int i=0;i<clist.size();i++){
		int diff=clist[i].second-clist[i].first;
		if(diff%2==0){
			cde[1].push_back(diff/2);
			continue;
		}
		if(a[clist[i].first]==1)
			cde[0].push_back(diff/2);
		else
			cde[2].push_back(diff/2);
	}
	int T=sm;
	for(int i=0;i<3;i++){
		for(int j=0;j<cde[i].size();j++){
			T+=cde[i][j]*2;
			if(i==1)
				continue;
			T++;
		}
	}
	
	ulld sol=(ncr(T, sm)*f(sm))%MOD;
	int curT=T-sm;
	for(int i=0;i<cde.size();i++){
		for(int j=0;j<cde[i].size();j++){
			int neededP=cde[i][j]*2+1;
			if(i==1) neededP--;
			sol*=ncr(curT, neededP);
			sol=sol%MOD;
			curT-=neededP;
			if(i==0)
				sol*=c(cde[i][j]);
			else if(i==1)
				sol*=d(cde[i][j]);
			else
				sol*=e(cde[i][j]);
			sol=sol%MOD;
		}
	}
	if(T==0)
		printf("0 1");
	else
		printf("%d %d", T, (int)sol);
	return 0;
}

/*
26
16
1 2 2 1 1 2 1 1 2 2 2 1 2 2 2 2
16
2 1 1 1 2 1 2 2 2 2 2 1 2 2 2 1

20 280640559

*/