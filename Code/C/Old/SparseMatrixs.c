#include <stdio.h>
#include <stdlib.h>
#define SMAX 16 //Number of non-zero elements
typedef int datatype;

typedef struct
{
	int i;
	int j;
	datatype val;
}node;

typedef struct
{
	node data[SMAX];
	int m;  //Rows
	int n;  //Number of columns
	int t;  //Number of non-zero elements
}spmatrix;

int main()
{
	spmatrix *a, *b, *c;
	spmatrix * Add(spmatrix *AA, spmatrix *BB);
	spmatrix * InitTriple();
	void Out(spmatrix *S);
	printf("Initialize the first matrix:\n");
	a = InitTriple();
	printf("The first matrix is:\n");
	Out(a);
	printf("Initialize the second matrix:\n");
	b = InitTriple();
	printf("The second matrix is:\n");
	Out(b);
	printf("Addition of two matrices:\n");
	c = Add(a, b);
	Out(c);
    printf("Add two matrices to get a triple:\n");
	printf("m=%d,n=%d,t=%d",c->m,c->n,c->t);

	return 0;
}

spmatrix * Add(spmatrix *A, spmatrix *B)
{
	void Out(spmatrix *S);
	spmatrix *C;
	int i = 0;
	int j = 0;
	int t = 0;
	C = (spmatrix *)malloc(sizeof(spmatrix));
	if (!C)
	{
		printf("Failed to allocate space!\n");
		exit(-1);
	}
	C->m = A->m;
	C->n = A->n;

	if (A->m != B->m || A->n != B->n)
	{
		printf("Matrix shapes are inconsistent! Cannot perform addition!\n");
	}

	while (i < A->t && j < B->t)
	{
		if (A->data[i].i > B->data[j].i)
		{
			C->data[t].i = B->data[j].i;
			C->data[t].j = B->data[j].j;
			C->data[t].val = B->data[j].val;
			j++;
			t++;
		}
		else if (A->data[i].i < B->data[j].i)
		{
			C->data[t].i = A->data[i].i;
			C->data[t].j = A->data[i].j;
			C->data[t].val = A->data[i].val;
			i++;
			t++;
		}
		else
		{
			if (A->data[i].j < B->data[j].j)
			{
				C->data[t].i = A->data[i].i;
				C->data[t].j = A->data[i].j;
				C->data[t].val = A->data[i].val;
				i++;
				t++;
			}
			else if (A->data[i].j > B->data[j].j)
			{
				C->data[t].i = A->data[i].i;
				C->data[t].j = A->data[i].j;
				C->data[t].val = A->data[i].val;
				i++;
				t++;
			}
			else
			{
				C->data[t].i = A->data[i].i;
				C->data[t].j = A->data[i].j;
				C->data[t].val = A->data[i].val + B->data[j].val;
				j++;
				i++;
				t++;
			}
		}
	}

	while (i < A->t)
	{
		C->data[t].i = A->data[i].i;
		C->data[t].j = A->data[i].j;
		C->data[t].val = A->data[i].val;
		i++;
		t++;
	}
	while (j < B->t)
	{
		C->data[t].i = B->data[j].i;
		C->data[t].j = B->data[j].j;
		C->data[t].val = B->data[j].val;
		j++;
		t++;
	}

	C->t = t;
	return C;

}


spmatrix * InitTriple()
{
	int i;
	spmatrix* S;
	S = (spmatrix*)malloc(sizeof(spmatrix));
	if (!S)
	{
		printf("Failed to allocate space!\n");
		exit(-1);
	}
	printf("Please enter the number of rows and columns of the matrix (m,n):\n");
	scanf("%d,%d", &S->m, &S->n);
	//printf("%d,%d", S->m, S->n);
	getchar();
	printf("Please enter the number of non-zero elements of the matrix:\n");
	//getchar();
	scanf("%d", &S->t);
	//printf("%d", S->t);
	for (i = 1; i <= S->t; i++)
	{
		printf("Please enter the number of rows, columns and values ​​of %d non-zero elements (m,n,t):\n", i);
		scanf("%d,%d,%d", &S->data[i - 1].i, &S->data[i - 1].j, &S->data[i - 1].val);
	}
	return S;
}

void Out(spmatrix *S)
{
	int i;
	printf("m  n val\n");
	for (i = 0; i < S->t; i++)
	{
		printf("%d  %d  %d\n", S->data[i].i, S->data[i].j, S->data[i].val);
	}
}

