int recpow(int a, int b) // recursive power : 재귀를 이용해 a의 b제곱을 구하는 함수
{
	if (b == 0)
		return 1;
	int n = recpow(a, b / 2);
	if (b % 2 == 0)
		return n * n;
	else
		return n * n * a;
}


long long recpowm(long long a, long long b, long long p) // recursive power mod : long long 버전, a의 b제곱을 p로 나눈 나머지를 반환한다.
{
	if (b == 0)
		return 1;
	long long n = recpowm(a, b / 2,p) % p;
	long long k= (n * n) % p;
	if (b % 2 == 0)
		return k;
	else
		return (k * a )% p;
}
