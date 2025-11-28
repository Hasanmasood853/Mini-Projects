#include <iostream>
using namespace std;
void createMatrix(int matrix[][3], int row, int col);
int main()
{
    // Multiplication of 3x3 Square Matrix
    const int n = 3;
    cout << "Enter entries of First Matrix\n";
    int firstMatrix[n][n];
    createMatrix(firstMatrix, n, n);
    cout << "Enter entries of 2nd Matrix\n";
    int secondMatrix[n][n];
    createMatrix(secondMatrix, n, n);
    cout << endl;
    int resultantMatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            resultantMatrix[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                resultantMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << resultantMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
void createMatrix(int matrix[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}