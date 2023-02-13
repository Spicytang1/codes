// 두 행렬의 곱셈을 수행하는 프로그램
// 두 행렬 a와 b를 입력받아 res에 저장한다. ( res는 a나 b이면 안 된다 )
// a는 N*M 크기이며 b는 M*K 크기이다.

int N, M, K;

void matmul(int** a, int** b, int** res)
{

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < K;j++)
		{
			int sum = 0;
			for (int l = 0;l < M;l++)
			{
				sum += a[i][l] * b[l][j];
			}
			res[i][j] = sum;
			//printf("%d ", sum);
		}
		//printf("\n");
	}


}
