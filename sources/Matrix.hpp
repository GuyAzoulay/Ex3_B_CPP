#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



namespace zich{

class Matrix{

private:
    vector<double> _matrix;
    int _rows;
    int _cols;

public:
        Matrix(int rows,int cols){
            if(rows<=0 || cols<=0){
                throw invalid_argument("Number of rows and cols must be positive");
            }
            vector<double> arr((uint)(rows*cols),0);
            this->_matrix = arr;
            this->_rows = rows;
            this->_cols = cols;
        }
        Matrix(vector<double> arr, int rows, int cols){
            if(rows<=0 || cols<=0){
                throw invalid_argument("Number of rows and cols must be positive");
            }
            if(arr.size() != rows*cols){
                throw invalid_argument("The size of the vector must be equal to the number of rows and cols");
            }
            this->_rows = rows;
            this->_cols = cols;
            this->_matrix = arr;
        }
         Matrix(const Matrix &other)
    {
        this->_rows = other._rows;
        this->_cols = other._cols;
        this->_matrix = other._matrix;
    }
        ~Matrix(){
            // for(uint i = 0 ; i < this->_rows ; i++){
            //     this->_matrix[i].clear();
            // }
           // this->_matrix.clear();

        }
        


        friend bool operator==(const Matrix& mat,const Matrix& other);
        friend bool operator!=(const Matrix& mat,const Matrix& other);
        friend bool operator<(const Matrix& mat,const Matrix& other);
        friend bool operator>(const Matrix& mat,const Matrix& other);
        friend bool operator<=(const Matrix& mat,const Matrix& other);
        friend bool operator>=(const Matrix& mat, const Matrix& other);


        // ostream operator
        friend ostream& operator<<(ostream& os, const Matrix& matrix);
        // istream operator
        friend istream& operator>>(istream& is, Matrix& matrix);

        
      

        // function to the minus operator
       friend Matrix operator-(const Matrix& mat ,const Matrix &other); // minus between two matrixs
       friend Matrix operator-(const Matrix &mat); //unary minus
       Matrix operator-(const Matrix &mat); // minus between this matrix and other
       friend Matrix operator-(const Matrix & mat, int a); // minus between matrix and a int number
       friend Matrix operator-(int a, const Matrix & mat); // minus between a int number and matrix
       friend Matrix operator-(double a, const Matrix & mat); // minus between a double number and matrix
       friend Matrix operator-(const Matrix & mat, double a); // minus between matrix and a double number
       friend Matrix operator-=(Matrix & mat, double a); // minus between matrix and a double number
       friend Matrix operator-=(Matrix & mat, int a); // minus between matrix and a int number
       friend Matrix operator-=(Matrix & mat, const Matrix & other); // minus between matrix and other matrix
       Matrix &operator--(); // decrement matrix by 1
       Matrix operator--(int); // decrement matrix by 1

      



        // function to the multiplication operator
       //friend Matrix operator*(const Matrix& mat , const Matrix &other); // multiplication between two matrixs
       
       Matrix operator*(const Matrix &other); // multiplication between this matrix and other
       friend Matrix operator*(int a, const Matrix &mat); // multiply between a int number and matrix
       friend Matrix operator*(const Matrix &mat, int a); // multiply between matrix and a int number
       friend Matrix operator*(double a, const Matrix &mat); // multiply between a double number and matrix
       friend Matrix operator*(const Matrix &mat, double a); // multiply between matrix and a double number
       friend Matrix operator*=( Matrix & mat, double a); // multiply between matrix and a double number
       friend Matrix operator*=( Matrix & mat, int a); // multiply between matrix and a int number
       friend Matrix operator*=( Matrix & mat, const Matrix & other); // multiply between matrix and other matrix
       

      




        // function to the plus operator
        //friend Matrix operator+(const Matrix& mat , const Matrix & other); // plus between two matrixs
        friend Matrix operator+(const Matrix &mat);
        Matrix operator+(const Matrix &mat); // plus between this matrix and other
        //Matrix operator+(const Matrix & mat, int a); // plus between matrix and a int number
        //Matrix operator+(int a, const Matrix & mat); // plus between a int number and matrix
        friend Matrix operator+(double a, const Matrix & mat); // plus between a double number and matrix
        friend Matrix operator+(const Matrix &mat, double a); // plus between matrix and a double number
        friend Matrix operator+=(Matrix & mat, double a); // plus between matrix and a double number
        friend Matrix operator+=(Matrix & mat, int a); // plus between matrix and a int number
        friend Matrix operator+=(Matrix & mat, const Matrix & other); // plus between matrix and other matrix

        Matrix &operator++(); // increment matrix by 1
        Matrix operator++(int); // increment matrix by 1
        



    
    

    void set_element(int i, int j, double value){
        if(i<0 || i>=this->_rows || j<0 || j>=this->_cols){
            throw invalid_argument("Index out of range");
        }
        this->_matrix[(uint)i*(uint)this->_cols+(uint)j] = value;
    }



    

};
}


