// 조합 i C j 를 배열 co[i][j]에 저장하는 dynamic program

#define MAX 1004


int co[MAX][MAX];//combination

void calcom() // MAX C MAX 까지 저장함
{
	co[1][1] = 1;
 	co[1][0] = 1;
	for (int i = 2;i < MAX;i++)
	{
		co[i][0] = 1;
		co[i][1] = i;
		co[i][i - 1] = i;
		co[i][i] = 1;
		for (int j = 2;j < i - 1;j++)
		{
			co[i][j] = co[i - 1][j - 1] + co[i - 1][j];
			//co[i][j] %= DIV;
	 		//DIV로 나눈 값을 배열에 저장
		}
	}
	
}
