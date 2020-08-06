#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int mid(int s, int e){return (s+e)>>1;}
int query(vector<int>& st, int tidx, int s, int e, int t);
void update(vector<int>& st, int tidx, int s, int e, int nidx, int diff);
int searchlb(vector<int>& st, int s, int e, int nth);

int main()
{
	int n, sz, a, flv=1000000;
	for(sz=1;sz<flv;sz*=2);
	vector<int> st(sz*2, 0), leaf(flv, 0), sol;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		if(a>>1){//replace c candies with b rank
			int b, c;
			scanf("%d %d", &b, &c);
			leaf[--b]+=c;
			update(st, 1, 0, flv-1, b, c);
		}
		else{//pop bth candy
			int b, cur;
			scanf("%d", &b);
			cur=query(st, 1, 0, flv-1, b);
			leaf[cur]--;
			update(st, 1, 0, flv-1, cur, -1);
			sol.push_back(cur+1);
		}
	}
	for(int i=0;i<sol.size();i++) printf("%d\n", sol[i]);
	return 0;
}

void update(vector<int>& st, int tidx, int s, int e, int nidx, int diff){
	if(nidx<s || nidx>e) return;
	st[tidx]+=diff;
	if(s!=e){
		update(st, tidx*2, s, mid(s, e), nidx, diff);
		update(st, tidx*2+1, mid(s, e)+1, e, nidx, diff);
	}
}

int query(vector<int>& st, int tidx, int s, int e, int t){
	if(s==e) return s;
	if(t<=st[tidx*2]) return query(st, tidx*2, s, mid(s, e), t);
	else return query(st, tidx*2+1, mid(s, e)+1, e, t-st[tidx*2]);
}