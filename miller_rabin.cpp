typedef unsigned long long ull;


ull recpowm(ull a, ull b, ull p) // recursive power mod : long long 버전, a의 b제곱을 p로 나눈 나머지를 반환한다.
{
	if (b == 0)
		return 1;
	ull n = recpowm(a, b / 2, p) % p;
	ull k = n*n % p;
	if (b % 2 == 0)
		return k;
	else
		return k*a % p;
}

bool checkmr(ull a, ull d, ull n, ull r)
{
	a %= n;
	if (a <= 1) return 1;

	ull x = recpowm(a, d, n);
	if (x == 1 || x == n - 1) return 1;
	for (ull i = 0;i < r-1;i++)
	{
		x = x * x;
		x %= n;
		if (x == n - 1)
			return 1;
	}
	return 0;
}


bool is_prime(ull n)//밀러 라빈 방법을 통해 소수인지 아닌지를 판별한다. long long 범위 모든 수에 대해 판정 가능하다.
{
	if (n == 2) return 1;
	if (n < 2 || n % 2 == 0) return 0;

	ull d = n - 1;
	ull r = 0;
	while (!(d & 1))
	{
		d >>= 1;
		r++;
	}
	ull a[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
  // ull a[]={2,7,61} // n이 int범위 안일 때
	bool q = 1;
	for (auto j : a)
	{
		q = q && checkmr(j, d, n, r);
		if (!q)
		{
			break;
		}
	}
	//	cout << n;
	//q ? cout << " is prime\n" : cout << "is not prime\n";
	return q;
}
