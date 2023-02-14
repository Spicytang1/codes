//에라스토테네스의 체의 linear sieve 버전
//https://ahgus89.github.io/algorithm/Linear-sieve/ 참고
//1부터 MAX까지 모든 소수를 pl에 저장함
//ac[i]는 i가 소수면 0이고 합성수면 가장 작은 소인수 값이다

#define MAX 5005

int ac[MAX] = { 0 };

void linear_sieve()
{
	vector<int> pl;
	for (int i = 2;i <= MAX;i++)
	{
		if (!ac[i])
		{
			pl.push_back(i);

		}
		for (auto j : pl)
		{
			if (i * j > MAX) break;
			ac[i * j] = j;
		}
	}
}
