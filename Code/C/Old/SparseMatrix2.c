#include<stdio.h> 
int main() 
{ 
	int r1,c1,d1,r2,c2,d2,i,j,temp; 
	//Enter the two Sparse Matrices 
	printf("Sparse Matrix 1:\n"); 
	printf("\nEnter no.of rows:"); 
	scanf("%d",&r1); 
	printf("\nEnter no. of columns:"); 
	scanf("%d",&c1); 
	printf("\nEnter no. elements:"); 
	scanf("%d",&d1); 
	printf("Sparse Matrix 2:\n"); 
	printf("\nEnter no.of rows:"); 
	scanf("%d",&r2); 
	printf("\nEnter no. of columns:"); 
	scanf("%d",&c2); 
	printf("\nEnter no. elements:"); 
	scanf("%d",&d2); 
	//Note the no. of rows used for Sparse Matrix declaration 
	int sparse1[d1+1][3],sparse2[d2+1][3]; 
	//Storing the no.of rows,columns and elements 
	sparse1[0][0]=r1; 
	sparse1[0][1]=c1; 
	sparse1[0][2]=d1; 
	sparse2[0][0]=r2; 
	sparse2[0][1]=c2; 
	sparse2[0][2]=d2; 
	printf("\nEnter elements of sparse matrix 1:\n"); 
	for(i=1;i<=d1;++i) 
		for(j=0;j<3;++j) 
			scanf("%d",&sparse1[i][j]); 
	printf("\nEnter elements of sparse matrix 2:\n"); 
	for(i=1;i<=d2;++i) 
		for(j=0;j<3;++j) 
			scanf("%d",&sparse2[i][j]); 
	//Now we need to find the transpose of 2nd Matrix 
	//Sorting the second Matrix on the basis of column data 
	for(i=1;i<d2;++i) 
	{ 
		for(j=i+1;j<=d2;++j) 
		{ 
			if(sparse2[i][1]>sparse2[j][1]) 
			{ 
				temp=sparse2[i][0]; 
				sparse2[i][0]=sparse2[j][0]; 
				sparse2[j][0]=temp; 
				temp=sparse2[i][1]; 
				sparse2[i][1]=sparse2[j][1]; 
				sparse2[j][1]=temp; 
				temp=sparse2[i][2]; 
				sparse2[i][2]=sparse2[j][2]; 
				sparse2[j][2]=temp; 
			} 
		} 
	} 
	//Sorting the second Matrix on the basis of row data for elements having same column data 
	for(i=1;i<d2;++i) 
	{ 
		for(j=i+1;j<=d2;++j) 
		{ 
			if(sparse2[i][1]==sparse2[j][1]) 
			{ 
				if(sparse2[i][0]>sparse2[j][0]) 
				{ 
					temp=sparse2[i][0]; 
				sparse2[i][0]=sparse2[j][0]; 
				sparse2[j][0]=temp; 
				temp=sparse2[i][1]; 
				sparse2[i][1]=sparse2[j][1]; 
				sparse2[j][1]=temp; 
				temp=sparse2[i][2]; 
				sparse2[i][2]=sparse2[j][2]; 
				sparse2[j][2]=temp; 
				} 
			} 
		} 
	} 
	//Swapping the row data and column data 
	for(i=1;i<=d2;++i) 
	{ 
		temp=sparse2[i][0]; 
		sparse2[i][0]=sparse2[i][1]; 
		sparse2[i][1]=temp; 
	}//Found the transpose of 2nd Matrix 
 
	//Now finding the no. of possible combinations in both the Matrices for calculation of product 
	temp=0; 
	for(i=1;i<=d1;++i) 
	{ 
		for(j=1;j<=d2;++j) 
		{ 
			if(sparse1[i][1]==sparse2[j][1]) 
				++temp; 
		} 
	} 
	//Creating and initializing the Matrix which will store the product 
	int sparse3[temp+1][3]; 
	sparse3[0][0]=r1; 
	sparse3[0][1]=c2; 
	sparse3[0][2]=0; 
	int k=1;			//Used for Traversing the Product Matrix 
	//Storing only the product terms in the Product Matrix 
	//on the basis of column terms which are same in Multiplicand and Multiplier Matrices 
	for(i=1;i<=d1;++i) 
	{ 
		for(j=1;j<=d2;++j) 
		{ 
			if(sparse1[i][1]==sparse2[j][1]) 
			{ 
				sparse3[k][0]=sparse1[i][0]; 
				sparse3[k][1]=sparse2[j][0]; 
				sparse3[k][2]=sparse1[i][2]*sparse2[j][2]; 
				++k; 
			} 
		} 
	} 
	//Sorting the Product Matrix on the basis of row data 
	for(i=1;i<temp;++i) 
	{ 
		for(j=i+1;j<=temp;++j) 
		{ 
			if(sparse3[i][0]>sparse3[j][0]) 
			{ 
				temp=sparse3[i][0]; 
				sparse3[i][0]=sparse3[j][0]; 
				sparse3[j][0]=temp; 
				temp=sparse3[i][1]; 
				sparse3[i][1]=sparse3[j][1]; 
				sparse3[j][1]=temp; 
				temp=sparse3[i][2]; 
				sparse3[i][2]=sparse3[j][2]; 
				sparse3[j][2]=temp; 
			} 
		} 
	} 
	//Sorting the Product Matrix on the basis of column data having same row data 
	for(i=1;i<temp;++i) 
	{ 
		for(j=i+1;j<=temp;++j) 
		{ 
			if(sparse3[i][0]==sparse3[j][0]) 
			{ 
				if(sparse3[i][1]>sparse3[j][1]) 
				{ 
				temp=sparse3[i][0]; 
				sparse3[i][0]=sparse3[j][0]; 
				sparse3[j][0]=temp; 
				temp=sparse3[i][1]; 
				sparse3[i][1]=sparse3[j][1]; 
				sparse3[j][1]=temp; 
				temp=sparse3[i][2]; 
				sparse3[i][2]=sparse3[j][2]; 
				sparse3[j][2]=temp; 
				} 
			} 
		} 
	} 
	int temp1; 
	k=0; 
	//Calculating the product terms which are to be added 
	//to get the final product term 
	//by adding those data which has same row data and column data 
	//and shifting the rows of the Product Matrix 
	for(i=1;i<temp;++i) 
	{ 
		if((sparse3[i][0]==sparse3[i+1][0])&&(sparse3[i][1]==sparse3[i+1][1])) 
		{ 
			sparse3[i][2]+=sparse3[i+1][2]; 
			for(j=i+1;j<temp;++j) 
			{ 
				sparse3[j][0]=sparse3[j+1][0]; 
				sparse3[j][1]=sparse3[j+1][1]; 
				sparse3[j][2]=sparse3[j+1][2]; 
			} 
			//Setting the unused rows to -1 
			sparse3[j][0]=-1; 
			sparse3[j][1]=-1; 
			sparse3[j][2]=-1; 
			++k;				//Calculating the unused rows 
		} 
	} 
	temp-=k;	//Reducing the size of the Product Matrix by subtracting the no. of unused rows 
	int d3=temp; 
	sparse3[0][2]=d3;	//Setting the no. of elements of Product Matrix 
	//Printing the Product Matrix 
	printf("\nProduct of sparse matrices:\n"); 
	for(i=0;i<(d3+1);++i) 
	{ 
		for(j=0;j<3;++j) 
			printf("%d ",sparse3[i][j]); 
		printf("\n"); 
	} 
} 