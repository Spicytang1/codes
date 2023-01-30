int max(int n, int m)
{
	return (n > m) ? n : m;
}

//euclidean algorithm
int gcd(int n, int m)
{
	while (1)
	{
		m = m % n;
		if (m == 0)
			break;
		n = n % m;
		if (n == 0)
			break;
	}
	return max(m, n);
	
}
