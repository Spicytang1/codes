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
