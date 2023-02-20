//nCk를 DIV로 나눈 값을 계산해주는 알고리즘
//단, DIV는 소수
//시간복잡도는 O(n+log(DIV))

//recpowm 함수는 https://github.com/Spicytang1/codes/blob/main/recpow_recpowm.c


#define DIV 1000000007


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


long long comb(long long n, long long k)
{
	long long nn, kk, nmk;
	nn = 1;
	kk = 1;
	nmk = 1;
	for (int i = 1;i < n + 1;i++)
	{
		nn *= i;
		nn %= DIV;
	}
	for (int i = 1;i < k + 1;i++)
	{
		kk *= i;
		kk %= DIV;
	}
	for (int i = 1;i < n - k + 1;i++)
	{
		nmk *= i;
		nmk %= DIV;
	}
		long long ans = (nn * recpowm(kk, DIV - 2, DIV)) % DIV;
	ans = (ans * recpowm(nmk, DIV - 2, DIV)) % DIV;
	return ans;


}
