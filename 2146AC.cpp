#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef vector<int> vi;
int di[4]={-1, 0, 1, 0}, dj[4]={0, 1, 0, -1};

int main()
{
	int n, landsid=1;
	scanf("%d", &n);
	vector<vi> m(102, vector<int>(102)), b(102, vector<int>(102, 0)), lands;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", &m[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(m[i][j]==0 || b[i][j]!=0) continue;
		vi edge;
		queue<int> q;
		q.push(1000*i+j);
		b[i][j]=landsid;
		while(!q.empty()){
			int ci=q.front()/1000, cj=q.front()%1000, isedge=0;
			q.pop();
			for(int i=0;i<4;i++){
				int ni=ci+di[i], nj=cj+dj[i];
				if(m[ni][nj]==0) isedge=1;
				else if(b[ni][nj]==0){
					q.push(ni*1000+nj);
					b[ni][nj]=landsid;
				}
			}
			if(isedge) edge.push_back(ci*1000+cj);
		}
		landsid++;
		lands.push_back(edge);
	}
	
	int minp=987654321;
	for(int i=0;i<lands.size()-1;i++){
		for(int j=i+1;j<lands.size();j++){
			vi iland=lands[i], jland=lands[j];
			for(int k=0;k<iland.size();k++){
				for(int l=0;l<jland.size();l++){
					int p=abs(iland[k]/1000-jland[l]/1000)+abs(iland[k]%1000-jland[l]%1000);
					if(p<minp) minp=p;
				}
			}
		}
	}
	printf("%d", minp-1);
	return 0;
}