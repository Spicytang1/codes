//소수 판정 함수
//정수를 입력받아 소수면 true, 소수가 아니면 false를 반환

bool primeyn(int a)
{
	if (a == 1)
		return false;
	int k = a;
	for (int i = 2;i <= k;i++)
	{
		if (a % i == 0)
		{
			return false;
		}
		k = a / i;
	}
	return true;
}
