// #include<cstdio>
// #include<vector>
// using namespace std;

// int main(){
// 	int n;
// 	scanf("%d", &n);
// 	if(n%2){
// 		printf("0");
// 		return 0;
// 	}
// 	n/=2;
// 	vector<int> c(n);
// 	if(n==1){
// 		printf("3");
// 		return 0;
// 	}
// 	c[0]=3, c[1]=11;
// 	for(int i=2;i<n;i++){
// 		c[i]=c[i-1]*3;
// 		for(int j=2;j<i+1;j++) c[i]+=c[i-j]*2;
// 		c[i]+=2;
// 	}
// 	printf("%d", c[n-1]);
// 	return 0;
// }

#include<cstdio>
int c[31], n;
int main()
{
	c[0]=1;
	for(int i=2;i<31;i+=2){
		c[i]=c[i-2];
		for(int j=i;j>0;j-=2)
			c[i]+=c[i-j]*2;
	}
	scanf("%d", &n);
	printf("%d", c[n]);
}