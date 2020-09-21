// C++ implementation of the above approach 
#include <iostream> 
using namespace std; 
 
	int maxLengthSquare(int row, int column, 
						int arr[][4], int k) 
	{ 
		// Matrix to store prefix sum 
		int sum[row + 1][column + 1] ; 
	
		for(int i = 0; i <= row; i++) 
			for(int j = 0; j <= column; j++) 
				sum[i][j] = 0; 
				
		// Current maximum length 
		int cur_max = 1; 
	
		// Variable for storing 
		// maximum length of square 
		int max = 0; 
			
		for (int i = 1; i <= row; i++) 
		{ 
			for (int j = 1; j <= column; j++) 
			{ 
				// Calculating prefix sum 
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + 
							arr[i - 1][j - 1] - sum[i - 1][j - 1]; 

				for(int k=0; k<=row; k++)
				{
					for(int l=0; l<=column; l++) cout<<sum[k][l]<<" "; cout<<"\n";
				} cout<<"\n";
		
				
				if(i >= cur_max && j >= cur_max && sum[i][j]<= k) 
				{ 
					max = cur_max++; 
				} 
			} 
		} 
	
		// Returning the 
		// maximum length 
		return max; 
	} 

	// Driver code 
	int main() 
	{ 
		
		int row = 4, column = 4; 
		int matrix[4][4] = { {1, 1, 1, 1}, 
						{1, 0, 0, 0}, 
						{1, 0, 0, 0}, 
						{1, 0, 0, 0} 
						}; 
	
		int k = 6; 
		int ans = maxLengthSquare(row, column, matrix, k); 
		cout << ans; 
		
		return 0; 
	} 

// This code is contributed by AnkitRai01 
