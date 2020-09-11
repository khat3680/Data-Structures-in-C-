/*
 * ---------------------------------
 * Student Name: Anshul Khatri
 * Student ID:193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include "matrix.h"

//-----------------------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid square matrix
 * 		A square matrix is a matrix which the number of rows is the same as the number of columns
 * 		Note that an empty matrix is a square matrix of size 0x0
 */

int is_square() {
	int i= 0,j=0,result;
	if (!is_matrix())
	{ return False;}

	if (get_column_length(0) != get_row_length(0) )
	{	return False;

	}

	char a='n';
	if(is_empty())
		{result = True;}

	else {
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			if ((matrix[i][j] == -1) && (matrix[i+1][0] ==-1))
			{if (j!=0)
			{	j=j-1;}
				a='y';

			break; }

		}
		if (a =='y')
			break;
	}

	if (i==j)
		{result = True;}
	else
		result =False;
	}

	return result;
}
//-----------------------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid identity matrix
 * 		An identity matrix is a square matrix, all diagonal elements equal to 1,
 * 			all other elements equal to 0
 * 		Note that an empty matrix is NOT an identity matrix
 */

int is_identity() {
	int i=0,j,result;


	if (!&is_square || matrix[0][0]!=1)
	{
		return False;}

	if (matrix[0][0] == 1 && (matrix[0][1]==-1 || matrix[1][0]==-1))
	{return True; }

		again:

		for(j=0;j<SIZE;j++)
		{

		if (matrix[i][0]==-1)
					{
						break;
					}

		if (matrix[i][j]==-1 && i <SIZE)
		{
			i=i+1;
			goto again;
		}

		if(matrix[i][j] != 1 && matrix[j][i] != 0)
			{
			   result = False;
			   break;
			}

		else
			result = True;

		}


	return result;
}
//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid uniform matrix
 * 		A uniform matrix is a matrix in which all elements are equal
 * 		Note that an empty matrix is NOT a uniform matrix
 */
int is_uniform() {
	int i=0 ,j,result;
	int r=0,c;

	if (is_empty())
	{
			return False;
			}
	if (matrix[0][0] >=0 && (matrix[0][1]==-1 && matrix[1][0]==-1))
			{
			return True; }


	if (!is_matrix())
		{
		return False;
		}

	int a ;

	again:

			for(j=0;j<SIZE;j++)
			{

			if (matrix[i][0]==-1)
						{
							break;
						}

			if (matrix[i][j]==-1 && i <SIZE)
			{
				i=i+1;
				goto again;
			}
			a = matrix[i][j];

			again_1:

						for(c=0;c<SIZE;c++)
						{

						if (matrix[r][0]==-1)
									{
										break;
									}

						if (matrix[r][c]==-1 && r <SIZE)
						{
							r=r+1;
							goto again_1;
						}

			if(matrix[r][c] != a)
				{
				   result = False;
				   break;
				}

			else
				result = True; }

			}

	return result;
}
//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid unique matrix
 * 		A unique matrix is a matrix in which all elements have unique values
 * 			i.e. no two elements have equal value
 * 		Note that an empty matrix is NOT a unique matrix
 */

int is_unique() {

	int i=0 ,j,result;
	int r=0,c;
	if (is_empty())
			return False;
	if (!is_matrix())

		{
		return False;
		}
	if (matrix[0][0] >=0 && (matrix[0][1]==-1 && matrix[1][0]==-1))
				{
				return True; }

	result = True;
	if (get_column_length(0) == get_row_length(0) )
	{
		for(i=0;i<SIZE;i++)
		{
			for(j=0;j<SIZE;j++)
			{
				if (matrix[i][j]!=-1)
				{
				for(r=0;r<SIZE;r++)
				{ for(c=0;c<SIZE;c++)
				{
					if(i!=r || j!=c)
					{
						if(matrix[i][j]==matrix[r][c])
						result = False;

					}
				}
				}
				}
			}
		}
	}


	else {
	i=0;
	r=0;

	again:
		for(j=0;j<SIZE;j++)
				{

					if (matrix[i][0]==-1)
							{
							break;
										}

							if (matrix[i][j]==-1 && i <SIZE)
								{
										i=i+1;
										goto again;
										}
							again_1:
							for(c=0;c<SIZE;c++)
							{
								if (matrix[r][0] == -1)
									break;

								if (matrix[r][c]==-1 && r <SIZE)
								{
								r=r+1;
								goto again_1;
								}
								if (i!=r || j!=c)
								{

								if (matrix[i][j]==matrix[r][c])

									{
									result = False;}

									else
								{ result = True}

								} }

	}

	}

	return result;
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid symmetric matrix
 * 		A symmetric matrix is a matrix which equals to its transpose
 * 		Note that an empty matrix is a VALID symmetric matrix
 */
int is_symmetric() {
	int i=0,j,result=-99;

		if (is_empty())
					return True;

			if (!is_matrix() && ( matrix[0][0]==-1))
			{
				return False;}

				again:

				for(j=0;j<SIZE;j++)
				{

				if (matrix[i][0]==-1)
							{
								break;
							}

				if (matrix[i][j]==-1 && i <SIZE)
				{
					i=i+1;
					goto again; }

					if(matrix[i][j] == matrix[j][i])

								{
						result = True;}


								else
									{
									result = False;
									break; }

								}

	return result;
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid binary matrix
 * 		A binary matrix is a matrix which all of its elements are equal to either 1 or 0
 * 		Note that an empty matrix is NOT a binary matrix
 */
int is_binary() {
	int i=0,j,result;

	if (is_empty())
				return False;

		if (!is_matrix() && ( matrix[0][0]!= 0 ||  matrix[0][0]!= 1))
		{
			return False;}

			again:

			for(j=0;j<SIZE;j++)
			{

			if (matrix[i][0]==-1)
						{
							break;
						}

			if (matrix[i][j]==-1 && i <SIZE)
			{
				i=i+1;
				goto again;
			}

			if(matrix[i][j]==1 || matrix[i][j]==0)

			{ result = True;}


			else
				{
				result = False;
				break; }

			}

	return result;
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid incremental matrix
 * 		An incremental matrix is:
 * 		a matrix which every element is greater than or equal to the one before it
 * 		Order: left to right, then top to bottom.
 */
int is_incremental() {
	int i=0 ,j,result,k;

		if (is_empty())
				return False;
		if (!is_matrix())

			{
			return False;
			}
		if (matrix[0][0] >=0 && (matrix[0][1]==-1 && matrix[1][0]==-1))
					{
					return True; }

		result = True;
		if (is_matrix())
		{
			again:

						for(j=0;j<SIZE;j++)
						{

						if (matrix[i][0]==-1)
									{
										break;
									}

						if (matrix[i][j]==-1 && i <SIZE)
						{	k = matrix[i][j-1];

							i=i+1;
							goto again;
						}

						if (( matrix[i][j] < k ) && (j==0 && i!=0)) {

							result = False;

							}

						if ((matrix[i][j] > matrix[i][j+1]) &&(matrix[i][j+1] !=-1) )
						{
							result = False;
						}


						}

		}


	return result;
}
