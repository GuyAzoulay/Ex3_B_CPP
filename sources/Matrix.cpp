#include <iostream>
#include "Matrix.hpp"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include<ctype.h>
using namespace std;

namespace zich{


        bool operator==(const Matrix& mat,const Matrix& other){
                try{
                        if(mat._rows != other._rows || mat._cols != other._cols){
                                throw invalid_argument("Number of rows and cols must be equal");
                        }
                        for(uint i = 0; i <mat._rows * mat._cols; i++){
                                if(mat._matrix[i] != other._matrix[i]){
                                        return false;
                                }
                        }
                        return true;
                }
                catch(exception &e){
                        throw e.what();
                }
        }

        bool operator!=(const Matrix& mat,const Matrix& other){
                return !(mat == other);
        }
        
        bool operator<(const Matrix& mat,const Matrix& other){
            try{
                    if(mat._rows != other._rows || mat._cols != other._cols){
                                throw invalid_argument("Number of rows and cols must be equal");
                    }
                    double sumMat = 0;
                    double sumOther = 0;
                    for (uint i = 0; i < mat._rows * mat._cols; i++){
                            sumMat += mat._matrix[i];
                            sumOther += other._matrix[i];
                    }
                        return sumMat < sumOther;    
            }
            catch(exception &e){
                    throw e.what();
            }
        }
        bool operator>(const Matrix& mat,const Matrix& other){
                 try{
                    if(mat._rows != other._rows || mat._cols != other._cols){
                                throw invalid_argument("Number of rows and cols must be equal");
                    }
                    double sumMat = 0;
                    double sumOther = 0;
                    for (uint i = 0; i < mat._rows * mat._cols; i++){
                            sumMat += mat._matrix[i];
                            sumOther += other._matrix[i];
                    }
                        return sumMat > sumOther;    
            }
            catch(exception &e){
                    throw e.what();
            }
        }
        bool operator<=(const Matrix& mat,const Matrix& other){
               try{
                       return !(mat > other);
               }
                 catch(exception &e){
                          throw e.what();
                 }
        }
        bool operator>=(const Matrix& mat, const Matrix& other){
                try{
                       return !(mat < other);
               }
                 catch(exception &e){
                          throw e.what();
                 }
        }


        // ostream operator
       std:: ostream& operator<<(ostream& os, const Matrix& matrix){
               for(uint i =0 ; i < (uint)matrix._rows; i++){
                       os <<"[";
                       for(uint j = 0; j < (uint)matrix._cols-1; j++){
                               os << matrix._matrix[i*(uint)matrix._cols+j] << " ";
                       }
                       os << matrix._matrix[i*(uint)matrix._cols+(uint)matrix._cols-1];
                       if(i != (uint)matrix._rows-1){
                               os << "]" << endl;
                       }
                       else{
                               os << "]";
                       }
               }
               return os;
        }
        // istream operator
        istream& operator>>(istream& is, Matrix& matrix){
                try{
                        
                        string line;
                        int checker=1;
                        int counter=0;
                        int row = 0;
                        getline(is,line);
                        stringstream ss(line);
                        string token;
                        vector<double> arr;
                        
                        if(line[0]!= '['){
                                throw invalid_argument("Matrix must start with [");
                        }
                        counter++;
                        for(uint i = 1; i < line.size()+1; i++){
                                
                                if(line[i] == '[' ){
                                        counter++;
                                }
                                
                                else if (line[i] == ']'){
                                        counter++;
                                        
                                        if(line[i+1] == ','){
                                                checker++;
                                                if(line[i+2]==' '){
                                                
                                                }
                                                else{
                                                        
                                                        throw invalid_argument("Invalid input1");
                                                }
                                        }
                                        else{
                                              
                                                continue;
                                        
                                        }
                                }
                                else{
                                        
                                      continue;                  
                                }
                               
                        }
                        
                        if(counter % 2 != 0){
                               
                                throw invalid_argument("Invalid input2");
                        }

                        if(counter/2 != matrix._rows) {
                                
                                throw invalid_argument("Invalid input3");        
                        }
                        if(checker != matrix._rows){
                                throw invalid_argument("Invalid input33");
                        }
                        bool ans = true;
                        if(ans){
                                row = counter/2;
                                int k =0;
                                //"[1111][1111][1111]"
                               uint j =0 ;
                               int colcounter = 1;
                              int colnum=1;
                              int col=0;
                              line.erase(remove(line.begin(), line.end(), ' '), line.end());
                              line.erase(remove(line.begin(), line.end(), ','), line.end());
                              line.erase(remove(line.begin(), line.end(), '\n'), line.end());
                              int temp = line.size();
                         
                              while(temp > 0){
                                      if(line[j] == '['){
                                              j++;
                                              temp--;
                                              continue;
                                      }
                                      if(isdigit(line[j]) != 0){
                                              
                                            arr.push_back(line[j]-'0'); 
                                            colcounter++; 
                                            colnum++;
                                            j++;
                                            temp--;
                                                       
                                      }
                                      if(line[j] ==']'){
                                              
                                              if((colnum % colcounter) == 0 && ans){
                                                 col = colcounter;
                                                 colnum++;
                                                 colcounter = 1;
                                                 j++;
                                                 temp--;
                                                 continue;
                                              }
                                                       throw invalid_argument("Invalid input5");

                                      }
                                   
                                      

                              }  
                            
                        matrix._matrix = arr;
                        matrix._cols = col-1;
                        matrix._rows = row;
                        }
                        

                }
                catch(exception &e){
                        throw e.what();
                }
                return is;
        } 

        
      

        // function to the minus operator
       Matrix operator-(const Matrix& mat ,const Matrix &other){
               
               if(mat._rows != other._rows || mat._cols != other._cols){
                       throw "Matrix dimensions do not match";
               }
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] - other._matrix[(uint)i];
                }
                return result;
       
         } 
         // minus between two matrixs
       Matrix Matrix::operator-(const Matrix &mat){
               
                 if(this->_rows != mat._rows || this->_cols != mat._cols){
                         throw "Matrix dimensions do not match";
                 }
                        Matrix result(this->_rows,this->_cols);
                        for(int i=0;i<this->_rows*this->_cols;i++){
                                result._matrix[(uint)i] = this->_matrix[(uint)i] - mat._matrix[(uint)i];
                        }
            
            return result;
            
             }
             
              // minus between this matrix and other   
       
       Matrix operator-(const Matrix & mat, int a){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] - a;
                }
                return result;
           
           }
           
           // minus between matrix and a int number
       Matrix operator-(int a, const Matrix & mat){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = a - mat._matrix[(uint)i];
                }
                return result;
              
              }
              
              // minus between a int number and matrix
       
       Matrix operator-(double a, const Matrix & mat){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = a - mat._matrix[(uint)i];
                }
                return result;
               }
               
               // minus between a double number and matrix
       
       Matrix operator-(const Matrix & mat, double a){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] - a;
                
                }
                return result;
       }
                
                // minus between matrix and a double number
       
       Matrix operator-=(Matrix & mat, double a){
                for(int i=0;i<mat._rows*mat._cols;i++){
                        mat._matrix[(uint)i] = mat._matrix[(uint)i] - a;
                }
                return mat;
                
                }


        // minus between matrix and a double number
       Matrix operator-=(Matrix & mat, int a){
                for(int i=0;i<mat._rows*mat._cols;i++){
                        mat._matrix[(uint)i] = mat._matrix[(uint)i] - a;
                }
                return mat;
                
                }// minus between matrix and a int number


       Matrix operator-=(Matrix & mat, const Matrix & other){
                if(mat._rows != other._rows || mat._cols != other._cols){
                        throw "Matrix dimensions do not match";
                }
                for(int i=0;i<mat._rows*mat._cols;i++){
                        mat._matrix[(uint)i] = mat._matrix[(uint)i] - other._matrix[(uint)i];
                }
                return mat;
        }
        
        // minus between matrix and a int number
              
       
       Matrix& Matrix::operator--(){
            
                for(int i=0;i<this->_rows*this->_cols;i++){
                        this->_matrix[(uint)i]-= 1;
                }
                
                return *this;
                
                } // decrement matrix by 1
       
       Matrix Matrix::operator--(int){
            Matrix result(*this);
                for(int i=0;i<this->_rows*this->_cols;i++){
                                this->_matrix[(uint)i]--;
                }
                return result;
                } // decrement matrix by 1
       




        // function to the multiplication operator
        
//           } // multiplication between two matrixs
       
       Matrix Matrix::operator*(const Matrix &other){
               
                if(this->_cols != other._rows){
                        
                                throw "Matrix dimensions do not match";
                }
               
                Matrix result(this->_rows,other._cols);
               
                 
                for (uint i = 0; i < this->_rows; i++)
                {
                        
                        for (uint j = 0; j < other._cols; j++)
                        {
                                
                                for (uint k = 0; k < this->_cols; k++)
                                {
                 
               
           result._matrix[i*(uint)other._cols + j] += this->_matrix[i*(uint)this->_cols + k] * other._matrix[k*(uint)other._cols + j];
                                        
                                }
                        }
                }
                return result;

                             } // multiplication between this matrix and other
       
       Matrix operator*(int a, const Matrix &mat){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] * a;
                }
                return result;
              
              }// multiply between a int number and matrix  
       
       Matrix operator*(const Matrix &mat, int a){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] * a;
                }
                return result;
                
                }// multiply between matrix and a int number
       
       Matrix operator*(double a, const Matrix &mat){
           
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] * a;
                }
                return result;
                
                }// multiply between a double number and matrix
       
       Matrix operator*(const Matrix &mat, double a){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] * a;
                }
                return result;
                
                
                }// multiply between matrix and a double number
       
       Matrix operator*=( Matrix & mat, double a){
                for(int i=0;i<mat._rows*mat._cols;i++){
                        mat._matrix[(uint)i] = mat._matrix[(uint)i] * a;
                }
                return mat;
                }// multiply between matrix and a double number
       
       Matrix operator*=( Matrix & mat, int a){
                for(int i=0;i<mat._rows*mat._cols;i++){
                        mat._matrix[(uint)i] = mat._matrix[(uint)i] * a;
                }
                return mat;
                
                }// multiply between matrix and a int number

        Matrix operator*=( Matrix & mat, const Matrix & other){
                 if(mat._cols != other._rows){
                          throw "Matrix dimensions do not match";
                 }
                Matrix result(mat._rows,other._cols);
                for (uint i = 0; i < mat._rows; i++){
                        for (uint j = 0; j < other._cols; j++){
                                for (uint k = 0; k < mat._cols; k++){
                                        double m = mat._matrix[i*(uint)mat._cols + k];
                                        double o = other._matrix[k*(uint)other._cols + j];
                                        result._matrix[i*(uint)other._cols + j] += m * o;
                                        
                                }
                        }
                }
               mat = result;
                return mat;
                }
       
       

        // function to the plus operator

              // plus between two matrixs
       
        Matrix Matrix::operator+(const Matrix &mat){
               if(this->_rows != mat._rows || this->_cols != mat._cols){
                        throw "Matrix dimensions do not match";
                }
                Matrix result(this->_rows,this->_cols);
                for(int i=0;i<this->_rows*this->_cols;i++){
                        result._matrix[(uint)i] = this->_matrix[(uint)i] + mat._matrix[(uint)i];
                }
                return result;
                
                
             } // plus between this matrix and other
        
       
                
        //         }// plus between a int number and matrix    
        
        Matrix operator+(double a, const Matrix & mat){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] + a;
                }
                return result;
                
                }// plus between a double number and matrix 
        
        Matrix operator+(const Matrix &mat, double a){
                Matrix result(mat._rows,mat._cols);
                for(int i=0;i<mat._rows*mat._cols;i++){
                        result._matrix[(uint)i] = mat._matrix[(uint)i] + a;
                }
                return result;
                
                }// plus between matrix and a double number
        ///////PLUS UNARY///////
        Matrix operator+(const Matrix &mat){
                return 1*mat;
        }
         ///////MINUS UNARY///////
         Matrix operator-(const Matrix &mat){
                return -1*mat;
        }
        Matrix operator+=(Matrix & mat, double a){
                for(int i=0;i<mat._rows*mat._cols;i++){
                        mat._matrix[(uint)i] = mat._matrix[(uint)i] + a;
                }
                return mat;
                
                }// plus between matrix and a double number 
       
        Matrix operator+=(Matrix & mat, int a){
                 for(int i=0;i<mat._rows*mat._cols;i++){
                        mat._matrix[(uint)i] = mat._matrix[(uint)i] + a;
                }
                return mat;
                
                }// plus between matrix and a int number

        Matrix operator+=(Matrix & mat, const Matrix & other){
                if(mat._rows != other._rows || mat._cols != other._cols){
                        throw "Matrix dimensions do not match";
                }
                for(uint i=0;i<mat._rows*mat._cols;i++){
                        mat._matrix[(uint)i] = mat._matrix[(uint)i] + other._matrix[(uint)i];
                }
                return mat;


                }
      
        Matrix& Matrix::operator++(){
               
                for(int i=0;i<this->_rows*this->_cols;i++){
                        this->_matrix[(uint)i]+=1;
                }
                //cout <<*this<<endl;
                return *this;
                
                }// increment matrix by 1
      
        Matrix Matrix::operator++(int){
                
                
                Matrix result(*this);
                for(int i=0;i<this->_rows*this->_cols;i++){
                        this->_matrix[(uint)i]++;
                }
                
                return result;
                
                }// increment matrix by 1
}