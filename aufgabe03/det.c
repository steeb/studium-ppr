#define MAX_SIZE 5

double get_determinant (double matrix[MAX_SIZE][MAX_SIZE], int size);

double get_determinant (double matrix[MAX_SIZE][MAX_SIZE], int size)
{
    if (size == 1)
    {
        return matrix[0][0];
    }
    else if (size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        int i;

        for (i = 0; i < size - 1; i++)
        {
            
        }        
    }
}
