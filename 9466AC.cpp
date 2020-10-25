#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
typedef vector<int> vi;

int main()
{
	int t, n;
	vi res;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int cidx=0, gidx=1;
		vi g(n), visited(n, 0), group(n, 0);
		for(int i=0;i<n;i++){
			int t;
			scanf("%d", &t);
			g[i]=--t;
		}
		
		while(cidx!=n){
			if(visited[cidx]!=0){
				cidx++;
				continue;
			}
			stack<int> st;
			st.push(cidx);
			visited[cidx]=-1;
			while(!st.empty()){
				int next=g[st.top()];
				if(visited[next]==0){
					st.push(next);
					visited[next]=-1;
				}
				else if(visited[next]==-1){
					while(st.top()!=next){
						group[st.top()]=gidx;
						visited[st.top()]=1;
						st.pop();
					}
					group[next]=gidx;
					visited[next]=1;
					st.pop();
				}
				else{
					while(!st.empty()){
						visited[st.top()]=1;
						st.pop();
					}
				}
			}
			cidx++;
		}
		gidx++;
		int nogcnt=0;
		for(int i=0;i<n;i++) if(group[i]==0) nogcnt++;
		res.push_back(nogcnt);
	}
	for(int i=0;i<res.size();i++) printf("%d\n", res[i]);
}