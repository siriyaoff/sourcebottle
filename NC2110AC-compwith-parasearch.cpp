#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c;
	cin>>n>>c;
	vi x(n);
	for(int i=0;i<n;i++) cin>>x[i];
	sort(x.begin(), x.end());
	int l=1, r=x[n-1];
	while(l<=r){
		int m=(l+r)/2, f=1;
		vi cl(c, 0);
		for(int i=1;i<c;i++){
			int cil=lower_bound(x.begin(), x.end(), x[cl[i-1]]+m)-x.begin();
			if(cil==n){
				f=0;
				break;
			}
			cl[i]=cil;
		}
		if(f) l=m+1;
		else r=m-1;
	}
	cout<<l-1;
}
//이분탐색을 해야 할 변화량을 공유기간 거리로 둬야 하는데, 처음에는 공유기간 거리를 정해놓고(집간 총거리/공유기 개수) 그걸로 공유기의 위치를 하나하나 정하는 느낌으로 해서 답이 제대로 나오지 않음, 즉 이분탐색의 대상을 공유기 하나하나의 위치로 둬버림.
//+난 이 문제도 parametric search를 사용했다 생각하는데 백준에는 태그가 없음. parametric search문제 하나 풀어볼 필요 있을 것 같음.