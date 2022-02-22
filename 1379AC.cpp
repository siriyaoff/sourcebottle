#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long lld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vi ord(n, 0);
	vector<vi> l(n, vi(3, 0));
	for(int i=0;i<n;i++){
		cin>>l[i][2]>>l[i][0]>>l[i][1];
		ord[i]=l[i][2];
	}
	sort(l.begin(), l.end());

	int pidx=1;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(l[0][1], pidx++));
	ord[l[0][2]-1]=1;
	for(int i=1;i<n;i++){
		if(pq.top().first<=l[i][0]){
			pii t=pq.top();
			pq.pop();
			ord[l[i][2]-1]=t.second;
			pq.push(make_pair(l[i][1], t.second));
		}
		else{
			ord[l[i][2]-1]=pidx;
			pq.push(make_pair(l[i][1], pidx++));
		}
	}
	cout<<pidx-1<<'\n';
	for(int i=0;i<n;i++)
		cout<<ord[i]<<'\n';
	return 0;
}
