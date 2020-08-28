// #include<iostream>
// #include<string>
// using namespace std;

// int main()
// {
// 	int n;
// 	long long int d[35], sum[35];
// 	long long int t=1;
// 	for(int i=0;i<35;i++){
// 		d[34-i]=t;
// 		t*=-2;
// 		if(i==0) sum[34]=1;
// 		else if(i==1) sum[33]=-2;
// 		else sum[34-i]=d[34-i]+sum[34-i+2];
// 	}
// 	string str("00000000000000000000000000000000000");
// 	cin>>n;
// 	if(n==0){
// 		printf("0");
// 		return 0;
// 	}
// 	int startbit=0;
// 	long long int remained=0;
// 	for(int i=34;i>-1;i--){
// 		if(n<0 && sum[i]<=n){
// 			startbit=i;
// 			break;
// 		}
// 		else if(n>0 && sum[i]>=n){
// 			startbit=i;
// 			break;
// 		}
// 	}
// 	str[startbit]='1';
// 	remained=n-d[startbit];
// 	for(int i=startbit+1;i<33;i++){
// 		if(d[i]>0){
// 			if(remained>sum[i+2]){
// 				remained-=d[i];
// 				str[i]='1';
// 			}
// 		}
// 		else{
// 			if(remained<sum[i+2]){
// 				remained-=d[i];
// 				str[i]='1';
// 			}
// 		}
// 	}
// 	if(remained==-2) str[33]='1';
// 	else if(remained==-1){
// 		str[33]='1';
// 		str[34]='1';
// 	}
// 	else if(remained==1) str[34]='1';
// 	for(n=0;n<35;n++) if(str[n]=='1') break;
// 	str.erase(0, n);
// 	printf("%s", str.c_str());
// }

#include<cstdio>

void go(int n) {
	if (n == 0) return;
	else{
		if (n % 2 == 0) {
			go(-n / 2);
			printf("0");
		}
		else {
			if(n>0) go(-n / 2);
			else go((-n + 1) / 2);
			printf("1");
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	if (n == 0) printf("0");
	else go(n);	
	return 0;
}