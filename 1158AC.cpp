#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int n, k, curk;
	scanf("%d %d", &n, &k);
	vector<int> sol, a(n);
	for(int i=0;i<n;i++) a[i]=i+1;
	curk=k;
	for(int i=n;i>0;i--){
		curk=curk%i;
		if(curk<=0) curk+=i;
		sol.push_back(a[curk-1]);
		a.erase(a.begin()+curk-1);
		curk=k-(i-curk);
	}
	printf("<");
	for(int i=0;i<sol.size()-1;i++) printf("%d, ", sol[i]);
	printf("%d>", sol.back());
}