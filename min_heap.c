/*
int A[] 배열에 대해 구현
A[1]부터 heap이 시작함
A[0].freq 에는 heap의 노드 개수를 저장함


사용법:
A[1]~A[n]까지 값을 저장 후
build(A) 호출 시 min heap이 구현됨
*/


typedef struct node
{
	int a;
	int freq;
} NODE;


void hpfy(NODE* A, int i)//MIN-HEAPIFY
{
	int smallest;
	NODE temp;
	int l = 2 * i;
	int r = 2 * i + 1;
	if (l <= A[0].freq && A[l].freq < A[i].freq)
		smallest = l;
	else
		smallest = i;
	if (r <= A[0].freq && A[r].freq < A[smallest].freq)
		smallest = r;
	if (smallest != i)
	{
		temp = A[i];
		A[i] = A[smallest];
		A[smallest] = temp;
		hpfy(A, smallest);
	}
}

void build(NODE* A)//BUILD-MIN-HEAP
{
	for (int i = (A[0].freq / 2);i > 0;i--)
		hpfy(A, i);
}

NODE pop(NODE* A) // 원소 하나(A[1]) 삭제
{
	NODE min = A[1];
	A[1] = A[A[0].freq];
	A[0].freq--;
	//printf("최소는 %d 의 freq %d\n", min.a, min.freq);
	hpfy(A, 1);
	return min;
}

void deckey(NODE* A, int i, int key) // i번째 원소의 freq값을 key로 변경 (감소시킴)
{
	NODE temp;
	if (key > A[i].freq)
		return;//실패
	A[i].freq = key;
	//printf("deckey %d %d %d\n\n", i, A[i].a, key);
	while (i > 1 && A[i / 2].freq > A[i].freq)
	{
		temp = A[i];
		A[i] = A[i / 2];
		A[i / 2] = temp;
		i = i / 2;
	}
}

void push(NODE* A, NODE key) // 새 원소 삽입
{
	NODE temp;
	int i = A[0].freq + 1;
	A[0].freq++;

	A[i] = key;
	while (i > 1 && A[i / 2].freq > A[i].freq)
	{
		temp = A[i];
		A[i] = A[i / 2];
		A[i / 2] = temp;
		i = i / 2;
	}
}
