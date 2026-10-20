/******************************
* Автор: Чеботников Александр *
* Задание: Обработка массивов *
* Вариант: 30                 *
******************************/

#include <iostream>

using namespace std;

int main() {
  double matrix[20][20];
  double maxValue;
  double minValue;
  double temporary;

  int matrixSize;
  int maxRowIndex;
  int maxColumnIndex;
  int minRowIndex;
  int minColumnIndex;

  cout << "Matrix size (2-20) = ";
  if (!(cin >> matrixSize) || matrixSize < 2 || matrixSize > 20) {
    cout << "INVALID" << endl;
    return 1;
  }

  for (int rowIndex = 0; rowIndex < matrixSize; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < matrixSize; ++columnIndex) {
      cout << "Element [" << rowIndex + 1 << "][" << columnIndex + 1 << "] = ";
      if (!(cin >> matrix[rowIndex][columnIndex]) ||
        matrix[rowIndex][columnIndex] < -1000.0 ||
        matrix[rowIndex][columnIndex] > 1000.0) {
        cout << "INVALID" << endl;
        return 1;
      }
    }
  }

  cout << "Original matrix:" << endl;
  for (int rowIndex = 0; rowIndex < matrixSize; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < matrixSize; ++columnIndex) {
      if (columnIndex > 0) {
        cout << " ";
      }
      cout << matrix[rowIndex][columnIndex];
    }
    cout << endl;
  }

  maxValue = matrix[0][1];
  maxRowIndex = 0;
  maxColumnIndex = 1;

  minValue = matrix[1][0];
  minRowIndex = 1;
  minColumnIndex = 0;

  for (int rowIndex = 0; rowIndex < matrixSize; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < matrixSize; ++columnIndex) {
      if (rowIndex < columnIndex && matrix[rowIndex][columnIndex] > maxValue) {
        maxValue = matrix[rowIndex][columnIndex];
        maxRowIndex = rowIndex;
        maxColumnIndex = columnIndex;
      }

      if (rowIndex > columnIndex && matrix[rowIndex][columnIndex] < minValue) {
        minValue = matrix[rowIndex][columnIndex];
        minRowIndex = rowIndex;
        minColumnIndex = columnIndex;
      }
    }
  }

  temporary = matrix[maxRowIndex][maxColumnIndex];
  matrix[maxRowIndex][maxColumnIndex] = matrix[minRowIndex][minColumnIndex];
  matrix[minRowIndex][minColumnIndex] = temporary;

  cout << "Maximum above main diagonal: " << maxValue
       << " at [" << maxRowIndex + 1 << "][" << maxColumnIndex + 1 << "]" << endl;
  cout << "Minimum below main diagonal: " << minValue
       << " at [" << minRowIndex + 1 << "][" << minColumnIndex + 1 << "]" << endl;

  cout << "Modified matrix:" << endl;
  for (int rowIndex = 0; rowIndex < matrixSize; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < matrixSize; ++columnIndex) {
      if (columnIndex > 0) {
        cout << " ";
      }
      cout << matrix[rowIndex][columnIndex];
    }
    cout << endl;
  }

  return 0;
}