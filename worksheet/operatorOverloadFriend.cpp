#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix
{
private:
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data.resize(rows, vector<T>(cols, 0));
    }

    void setElement(int r, int c, T value)
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            data[r][c] = value;
        }
    }

    // Friend function to overload << for Matrix class
    friend ostream &operator<<(ostream &os, const Matrix<T> &matrix)
    {
        for (int i = 0; i < matrix.rows; i++)
        {
            for (int j = 0; j < matrix.cols; j++)
            {
                os << matrix.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

int main()
{
    // Create a 3x3 matrix of integers
    Matrix<int> intMatrix(3, 3);
    intMatrix.setElement(0, 0, 1);
    intMatrix.setElement(0, 1, 2);
    intMatrix.setElement(0, 2, 3);
    intMatrix.setElement(1, 0, 4);
    intMatrix.setElement(1, 1, 5);
    intMatrix.setElement(1, 2, 6);
    intMatrix.setElement(2, 0, 7);
    intMatrix.setElement(2, 1, 8);
    intMatrix.setElement(2, 2, 9);

    cout << "Integer Matrix: " << endl;
    cout << intMatrix;

    // Create a 2x2 matrix of doubles
    Matrix<double> doubleMatrix(2, 2);
    doubleMatrix.setElement(0, 0, 1.1);
    doubleMatrix.setElement(0, 1, 2.2);
    doubleMatrix.setElement(1, 0, 3.3);
    doubleMatrix.setElement(1, 1, 4.4);

    cout << "Double Matrix: " << endl;
    cout << doubleMatrix;

    return 0;
}
/*
2. Which << operator does the friend function overload, as there are many << operators in the code?
The << operator being overloaded in the friend function is specifically the stream insertion operator used for outputting data to an output stream (like cout).

There are many << operators in C++, used for various purposes, but in the context of ostream, the << operator is part of the C++ standard library and is used for outputting values to a stream. The friend function in your class is overloading this specific version of the << operator to work with custom objects.

Here's how it works:

cpp
Copy code
friend ostream& operator<<(ostream& os, const Matrix<T>& matrix);
This is overloading the << operator that works with ostream. When you write something like cout << myObject;, this operator is called, and the friend function allows you to specify how to print myObject to the output stream (cout).

What is ostream?

ostream is a standard output stream type in C++ (used for cout, ofstream, etc.).
The standard library defines how basic types like int, double, char, etc., should be printed using <<. For example, cout << 5; prints an integer to the console.
You are extending this functionality so that when the compiler encounters cout << myMatrix;, it knows to use your overloaded << operator to print the matrix.
Which << operator is overloaded?
In this case, you are only overloading the ostream insertion operator for your custom class (Matrix<T>). When you do something like cout << obj;, the compiler checks whether an appropriate overload for << exists. If it's a primitive type (like int or double), the default ostream operator is used. If it's a custom class (like Matrix<T>), the compiler will use the overloaded version you defined in your friend function.

Example:
cpp
Copy code
friend ostream& operator<<(ostream& os, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.data[i][j] << " ";  // Overloading << to print Matrix<T>
        }
        os << endl;
    }
    return os;
}
In this case:

When you write cout << matrix;, the compiler calls this overloaded << operator to print the contents of the matrix.
Summary of Overloading:
The friend function is overloading the ostream version of the << operator, allowing you to print custom objects (e.g., Matrix<T>) to the output stream.
Other << operators (like bitwise shift) are not affected by this overload. You are only overloading the ostream insertion operator for outputting your class objects.

*/