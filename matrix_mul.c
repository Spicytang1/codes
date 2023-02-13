// 두 행렬의 곱셈을 수행하는 프로그램
// 두 행렬 a와 b를 입력받아 res에 저장한다.
// a는 n*m 크기이며 b는 m*k 크기이다.

int n, m, k;

void matmul(int** a, int** b, int** res)
{

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < k;j++)
		{
			int sum = 0;
			for (int l = 0;l < m;l++)
			{
				sum += a[i][l] * b[l][j];
			}
			res[i][j] = sum;
			//printf("%d ", sum);
		}
		//printf("\n");
    //행렬곱의 결과를 출력함
	}


}
