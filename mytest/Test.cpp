#include "Matrix.hpp"
using namespace zich;
#include <vector>
#include <fstream>
#include <iostream>

#include "doctest.h"

using namespace std;


TEST_CASE("Matrix Creation"){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    CHECK_NOTHROW(Matrix mat(arr,3,3));

   arr = {1.8,0,0,0,1.8,0,0,0,1.8};
   CHECK_NOTHROW(Matrix mat(arr,3,3));


   // number of rows or colums doesnt match to the size of the matrix
   CHECK_THROWS(Matrix mat(arr,3,2));
   CHECK_THROWS(Matrix mat(arr,8,8));

   // number of  raws and cols must be bigger than zero
   CHECK_THROWS(Matrix mat(arr,0,3));
   CHECK_THROWS (Matrix mat(arr,3,0));

   //number of raws and colums must be positive
    CHECK_THROWS(Matrix mat(arr,-3,3));
    CHECK_THROWS(Matrix mat(arr,3,-3));
}

TEST_CASE("The + / - operators"){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    Matrix mat(arr,3,3);
    vector<double> arr2 = {3,1,1,1,3,1,1,1,3};
    Matrix mat2(arr2,3,3);
    Matrix mat3 = 1+mat;
    Matrix mat4 = -1+mat;   
    Matrix mat5 = -2+mat2;
    CHECK(mat3 == mat2);
    CHECK(mat4 == mat5);

}
TEST_CASE("The == / != operators"){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    Matrix mat(arr,3,3);
    vector<double> arr2 = {3,1,1,1,3,1,1,1,3};
    Matrix mat2(arr2,3,3);
    CHECK_FALSE(mat == mat2);
    CHECK(mat != mat);

    vector<double> arr3 = {1,0,0,1};
    Matrix mat3(arr3,2,2);
    vector<double> arr4 = {0,0,1,0,0,1,0,0,1};
    Matrix mat4(arr4,3,3);
    CHECK_FALSE(mat3 == mat4);
    CHECK(mat3 != mat4);

    vector<double> arr5 = {1,0,0,1,0,0,1,0,0,1};
    Matrix mat5(arr5,3,3);
    vector<double> arr6 = {1,0,0,1,0,0,1,0,0,1};
    Matrix mat6(arr6,3,3);
    CHECK(mat5 == mat6);
    CHECK_FALSE(mat5 != mat6);
}

TEST_CASE("The < / > operators"){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    Matrix mat(arr,3,3);
    vector<double> arr2 = {3,1,1,1,3,1,1,1,3};
    Matrix mat2(arr2,3,3);
    CHECK(mat < mat2);
    CHECK_FALSE(mat > mat2);
    CHECK(mat2 > mat);

    vector<double> arr3 = {1,0,0,1};
    Matrix mat3(arr3,2,2);
    vector<double> arr4 = {0,0,1,0,0,1,0,0,1};
    Matrix mat4(arr4,3,3);
    CHECK_FALSE(mat4 < mat3);
    CHECK(mat4 > mat3);

    vector<double> arr5 = {1,0,0,1,0,0,1,0,0,1};
    Matrix mat5(arr5,3,3);
    vector<double> arr6 = {1,0,0,1,0,0,1,0,0,1};
    Matrix mat6(arr6,3,3);
    CHECK_FALSE(mat5 < mat6);
    CHECK_FALSE(mat6 < mat5);
    
}

TEST_CASE("The <= / >= operators"){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    Matrix mat(arr,3,3);
    vector<double> arr2 = {3,1,1,1,3,1,1,1,3};
    Matrix mat2(arr2,3,3);
    CHECK(mat <= mat2);
    CHECK(mat2 >= mat);
    CHECK_FALSE(mat2 <= mat);


    vector<double> arr3 = {1,0,0,1};
    Matrix mat3(arr3,2,2);
    vector<double> arr4 = {0,0,1,0,0,1,0,0,1};
    Matrix mat4(arr4,3,3);
    CHECK_FALSE(mat4 <= mat3);
    CHECK(mat4 >= mat3);
    CHECK(mat3 <= mat4);

    vector<double> arr5 = {1,0,0,1,0,0,1,0,0,1};
    Matrix mat5(arr5,3,3);
    vector<double> arr6 = {1,0,0,1,0,0,1,0,0,1};
    Matrix mat6(arr6,3,3);
    CHECK(mat5 <= mat6);
    CHECK(mat6 >= mat5);
    
}

TEST_CASE("The * operators"){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    Matrix mat(arr,3,3);
    vector<double> arr2 = {3,1,1,1,3,1,1,1,3};
    Matrix mat2(arr2,3,3);
    vector<double> arr3 = {6,2,2,2,6,2,2,2,6};
    Matrix mat3(arr3,3,3);
    vector<double> arr4 = {3,1,1,1,3,1,1,1,3};
    vector<double> arr5 = {4,0,0,0,4,0,0,0,4};
    Matrix mat5(arr5,3,3);
    Matrix mat4(arr4,3,3);
    CHECK(mat*mat2 == mat3);
    CHECK_FALSE(mat2*mat == mat4);
    CHECK(2*mat == mat5);
    CHECK_FALSE(mat*5 == mat5);
    CHECK(mat*2 == mat5);
    CHECK_FALSE(mat*3 == mat5);

}
TEST_CASE("the operator *= | += | -="){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    Matrix mat(arr,3,3);
    vector<double> arr2 = {3,1,1,1,3,1,1,1,3};
    Matrix mat2(arr2,3,3);
    vector<double> arr3 = {6,2,2,2,6,2,2,2,6};
    Matrix mat3(arr3,3,3);
    vector<double> arr4 = {3,1,1,1,3,1,1,1,3};
    vector<double> arr5 = {4,0,0,0,4,0,0,0,4};
    Matrix mat5(arr5,3,3);
    Matrix mat4(arr4,3,3);
    vector<double> arr6 = {7,1,1,1,7,1,1,1,7};
    Matrix mat6(arr6,3,3);
    vector<double> arr7 = {-1,1,1,1,-1,1,1,1,-1};
    Matrix mat7(arr7,3,3);

    vector <double> arr8 = {3,0,0,3};
    Matrix mat8(arr8,2,2);


    CHECK(mat*mat2 == mat3);
    CHECK_FALSE(mat2*mat == mat4);
    CHECK(2*mat == mat5);
    CHECK_FALSE(mat*5 == mat5);
    CHECK(mat*2 == mat5);
    CHECK_FALSE(mat*3 == mat5);
    mat*=2;
    CHECK(mat == mat5);
    mat+=mat2;
    CHECK(mat == mat6);
    mat3-=mat;
    CHECK(mat3 == mat7);

    CHECK_THROWS(mat8*=mat);
    CHECK_THROWS(mat8+=mat);
    CHECK_THROWS(mat8-=mat);
}
TEST_CASE("increment and decrement operators"){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    Matrix mat(arr,3,3);
    vector<double> arr2 = {3,1,1,1,3,1,1,1,3};
    Matrix mat2(arr2,3,3);
    vector<double> arr3 = {6,2,2,2,6,2,2,2,6};
    Matrix mat3(arr3,3,3);
    vector<double> arr4 = {5,1,1,1,5,1,1,1,5};
    Matrix mat4(arr4,3,3);
    vector<double> arr5 = {4,0,0,0,4,0,0,0,4};
    Matrix mat5(arr5,3,3);
    
    ++mat;
    CHECK(mat == mat2);
    --mat3;
    CHECK(mat3 == mat4);
    
}
TEST_CASE("cout"){
    vector<double> arr = {2,0,0,0,2,0,0,0,2};
    Matrix mat(arr,3,3);
    vector<double> arr2 = {3,1,1,1,3,1,1,1,3};
    Matrix mat2(arr2,3,3);
    vector<double> arr3 = {6,2,2,2,6,2,2,2,6};
    Matrix mat3(arr3,3,3);
    vector<double> arr4 = {3,1,1,1,3,1,1,1,3};
    vector<double> arr5 = {4,0,0,0,4,0,0,0,4};
    Matrix mat5(arr5,3,3);
    Matrix mat4(arr4,3,3);
    vector<double> arr6 = {7,1,1,1,7,1,1,1,7};
    Matrix mat6(arr6,3,3);
    vector<double> arr7 = {-1,1,1,1,-1,1,1,1,-1};
    Matrix mat7(arr7,3,3);

    vector <double> arr8 = {3,0,0,3};
    Matrix mat8(arr8,2,2);

    CHECK_NOTHROW(cout << mat << endl);
    CHECK_NOTHROW(cout << mat2 << endl);
    CHECK_NOTHROW(cout << mat3 << endl);
    CHECK_NOTHROW(cout << mat4 << endl);
    CHECK_NOTHROW(cout << mat5 << endl);
    CHECK_NOTHROW(cout << mat6 << endl);
    CHECK_NOTHROW(cout << mat7 << endl);
    CHECK_NOTHROW(cout << mat8 << endl);

}


