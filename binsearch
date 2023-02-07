//binary search 이분 탐색
//값을 찾은 경우에 주소 반환, 못 찾은 경우에 -1 반환

int bs(int* a, int n, int key)
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] == key)
			return m;
		if (a[m] < key)
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}
