#include <iostream>
#include <vector>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data.resize(rows, std::vector<T>(cols));
    }

    T& operator()(int row, int col) {
        return data[row][col];
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Matrix<float> matrixFloat(3, 2);
    matrixFloat(0, 0) = 1.2;
    matrixFloat(0, 1) = 2.3;
    matrixFloat(1, 0) = 3.4;
    matrixFloat(1, 1) = 4.5;
    matrixFloat(2, 0) = 5.6;
    matrixFloat(2, 1) = 6.7;

    std::cout << "Matrix<float>:" << std::endl;
    matrixFloat.print();

    Matrix<double> matrixDouble(2, 3);
    matrixDouble(0, 0) = 1.1;
    matrixDouble(0, 1) = 2.2;
    matrixDouble(0, 2) = 3.3;
    matrixDouble(1, 0) = 4.4;
    matrixDouble(1, 1) = 5.5;
    matrixDouble(1, 2) = 6.6;

    std::cout << "\nMatrix<double>:" << std::endl;
    matrixDouble.print();

    Matrix<int> matrixInt(2, 2);
    matrixInt(0, 0) = 1;
    matrixInt(0, 1) = 2;
    matrixInt(1, 0) = 3;
    matrixInt(1, 1) = 4;

    std::cout << "\nMatrix<int>:" << std::endl;
    matrixInt.print();

    return 0;
}