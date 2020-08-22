#include<cstdio>
#include<vector>
#include<tuple>
using namespace std;
typedef vector<int> vi;
typedef tuple<int, int, int> ti;

int mid(int s, int e){return (s+e)>>1;}
int init(vi& num, vi& st, int tidx, int s, int e);
int query1(vi& st, int tidx, int s, int e, int fl, int fr);//return partial sum
ti query2(vi& st, int tidx, int s, int e, int val);//return index of e, sum(0, e)==val
int findlast1(vi& st, int n, int tidx, int s, int e);
void update(vi& st, int tidx, int s, int e, int nidx, int diff);

int main()
{
	int n, k, curk, curp, sz=1;
	scanf("%d %d", &n, &k);
	for(;sz<n;sz*=2);
	vi st(2*sz), num(n, 1), sol;
	init(num, st, 1, 0, n-1);
	curp=-1;
	for(int i=n;i>0;i--){
		int idx, s, e, aftercurp, curk;
		if(curp==n-1) aftercurp=0;
		else aftercurp=query1(st, 1, 0, n-1, curp+1, n-1);
		if(aftercurp>=k) curk=(k+i-aftercurp)%i;
		else curk=(k-aftercurp)%i;
		if(curk==0) curk=i;
		tie(idx, s, e)=query2(st, 1, 0, n-1, curk);
		curp=findlast1(st, n, idx, s, e);
		sol.push_back(curp+1);
		update(st, 1, 0, n-1, curp, -1);
	}
	printf("<");
	for(int i=0;i<sol.size()-1;i++) printf("%d, ", sol[i]);
	printf("%d>", sol.back());
}

int init(vi& num, vi& st, int tidx, int s, int e){
	if(s==e) return st[tidx]=num[s];
	return st[tidx]=init(num, st, tidx*2, s, mid(s, e))+init(num, st, tidx*2+1, mid(s, e)+1, e);
}

int query1(vi& st, int tidx, int s, int e, int fl, int fr){
	if(s>fr || e<fl) return 0;
	if(s>=fl && e<=fr) return st[tidx];
	return query1(st, tidx*2, s, mid(s, e), fl, fr)+query1(st, tidx*2+1, mid(s, e)+1, e, fl, fr);
}

ti query2(vi& st, int tidx, int s, int e, int val){
	if(st[tidx]==val) return make_tuple(tidx, s, e);
	if(val>st[tidx*2]) return query2(st, tidx*2+1, mid(s, e)+1, e, val-st[tidx*2]);
	return query2(st, tidx*2, s, mid(s, e), val);
}

int findlast1(vi& st, int n, int tidx, int s, int e){
	if(s==e) return s;
	if(st[tidx*2+1]==0) return findlast1(st, n, tidx*2, s, mid(s, e));
	return findlast1(st, n, tidx*2+1, mid(s, e)+1, e);
}

void update(vi& st, int tidx, int s, int e, int nidx, int diff){
	if(s>nidx || e<nidx) return;
	st[tidx]+=diff;
	if(s!=e){
		update(st, tidx*2, s, mid(s, e), nidx, diff);
		update(st, tidx*2+1, mid(s, e)+1, e, nidx, diff);
	}
}