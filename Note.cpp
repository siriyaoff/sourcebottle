//string으로 입력
for(int i=0;i<n;i++){
	getline(cin, s, '\n');
	while(s=="") getline(cin, s, '\n');
	for(int j=0;j<n;j++) m[i][j]=s[j]-48;
}

//2차원 psum배열 선언
sum[0][0]=p[0][0];
for(int i=1;i<n;i++) sum[i][0]=sum[i-1][0]+p[i][0];
for(int j=1;j<m;j++) sum[0][j]=sum[0][j-1]+p[0][j];
for(int i=1;i<n;i++) for(int j=1;j<m;j++)
	sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+p[i][j];
//[(i1, j1), (i2, j2)] 합
if(i1>0 && j1>0) return sum[i2][j2]-sum[i1-1][j2]-sum[i2][j1-1]+sum[i1-1][j1-1];
else if(i1>0) return sum[i2][j2]-sum[i1-1][j2];
else if(j1>0) return sum[i2][j2]-sum[i2][j1-1];
else return sum[i2][j2];

//sieve of eratosthenes, 0:prime
bool check[N];
void e(){
	check[1] = true;
	for(int i=2; i*i<=n; i++) if(!check[i]) for(int j=i*i; j<=n; j+=i)
		check[j] = true;
}

<algorithm>에 __gcd(a, b) 존재

//pow(T, int) 구현
//inline : 함수 호출을 줄여줌(컴파일 단계에서 함수 호출을 함수 내용으로 대체함)
//static 선언 : 이 함수가 선언된 코드에서만 사용가능하게 해줌
//static 변수 : 한 번만 초기화됨
//constexpr : 리턴값을 컴파일 시간 상수로 만들어줌(그냥 상수는 사용자 입력으로 초기화해도 됨, 컴파일 시간 상수는 컴파일 단계에서 상수 값이 확정되어야함)
template<typename T>
static constexpr inline T pown(T x, unsigned p) {
    T r = 1;
	while (p) {
        if (p & 0x1) r *= x;
        x *= x;
        p >>= 1;
    }
    return r;
}

//(p1, p2), (p3, p4)로 주어진 직사각형 2개의 교차 판별, 오름차순 정렬되어 있어야함, 1:inter
bool inter(p1, p2, p3, p4){
	return !(p1.i>p4.i || p2.i<p3.i || p1.j>p4.j || p2.j<p3.j
			 || (p3.i<p1.i && p2.i<p4.i && p3.j<p1.j && p2.j<p4.j)
			 || (p1.i<p3.i && p4.i<p2.i && p1.j<p3.j && p4.j<p2.j));
}

//Segment tree
for(sz=1;sz<n;sz*=2);
vi st(sz*2), num(n, 0);

int init(vi& num, vi& st, int tidx, int s, int e){
	if(s==e) return st[tidx]=num[s];
	else
		return st[tidx]=init(num, st, tidx*2, s, mid(s, e))+init(num, st, tidx*2+1, mid(s, e)+1, e);
}

int findsum(vi& st, int tidx, int s, int e, int fl, int fr){
	if(s>fr || e<fl) return 0;
	if(s>=fl && e<=fr) return st[tidx];
	return findsum(st, tidx*2, s, mid(s, e), fl, fr)+findsum(st, tidx*2+1, mid(s, e)+1, e, fl, fr);
}

void update(vi& st, int tidx, int s, int e, int nidx, int diff){
	if(nidx<s || nidx>e) return ;
	st[tidx]+=diff;
	if(s!=e){
		update(st, tidx*2, s, mid(s, e), nidx, diff);
		update(st, tidx*2+1, mid(s, e)+1, e, nidx, diff);
	}
}

