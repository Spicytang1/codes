// 수열의 길이 n을 입력받은 뒤 n개의 정수를 입력받아 수열을 완성 후 가장 긴 증가하는 부분수열 LCS의 길이를 출력
//시간복잡도는 O(n^2)
//백준 https://www.acmicpc.net/problem/11053 의 해답
//백준 https://www.acmicpc.net/problem/2631 응용 가능

int max(int n, int m)
{
	return (n > m) ? n : m;
}


int lcs()
{
	int  n;
	scanf("%d", &n);
	int a[1004];// 1004는 n의 최대 길이에 따라 변경
	int l[1004];// 1004는 n의 최대 길이에 따라 변경
	for (int i = 1;i < n + 1;i++)
	{
		scanf("%d", a + i);
	}

	
	l[1] = 1;
	int mini = a[1];
	int maxi = l[1];
	for (int i = 2;i < n + 1;i++)
	{
		if (a[i] <= mini)
		{
			mini = a[i];
			l[i] = 1;
			continue;
		}
		l[i] = 0;

		for (int j = 1;j < i;j++)
		{
			if (a[j] < a[i])
			{
				l[i] = max(l[i], l[j]);
			}
		}
		l[i]++;
		maxi = max(maxi, l[i]);
		//printf("%d %d\n", i, l[i]);
	}
	printf("%d", maxi);


}
