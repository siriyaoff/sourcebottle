// // BFS
// #include<bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;

// int main()
// {
// 	int n, k, ccnt, cur, cnt;
// 	int v[100001];
// 	fill(v, v+100001, 100001);
// 	cin>>n>>k;
// 	ccnt=abs(k-n);
// 	queue<pii> q;
// 	q.push({n, 0});
// 	cur=n, cnt=0;
// 	while(cur!=k && cnt<ccnt){
// 		cur=q.front().first, cnt=q.front().second;
// 		q.pop();
// 		if(cur-1>-1 && v[cur-1]>cnt+1){
// 			q.push({cur-1, cnt+1});
// 			v[cur-1]=cnt+1;
// 		}
// 		if(cur+1<100001 && v[cur+1]>cnt+1){
// 			q.push({cur+1, cnt+1});
// 			v[cur+1]=cnt+1;
// 		}
// 		if(cur*2<100001 && v[cur*2]>cnt+1){
// 			q.push({cur*2, cnt+1});
// 			v[cur*2]=cnt+1;
// 		}
// 	}
// 	cout<<cnt;
// }

// Divide and conquer
#include<bits/stdc++.h>
using namespace std;

int f(int n, int k){
	if(n>=k) return n-k;
	else if(k==1) return 1;
	else if(k&1) return 1+min(f(n, k-1), f(n, k+1));
	else return min(k-n, 1+f(n, k/2));
}

int g(int n, int k){
	if(n>=k) return n-k;
	else if(n>0) return 1+min(f(n+1, k), min(f(n-1, k), f(n*2, k)));
	else return 1+min(f(n+1, k), f(n*2, k));
}

int main()
{
	int n, k;
	cin>>n>>k;
	cout<</*f(n, k)<<' '<<*/g(n, k);
}