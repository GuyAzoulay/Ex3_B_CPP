#include <iostream>
#include "Matrix.hpp"
#include <vector>
using namespace std;
using namespace zich;

int main(){
    Matrix mat1(2,2);
    Matrix mat2(2,2);
    mat1.set_element(0,0,1);
    mat1.set_element(0,1,2);
    mat1.set_element(1,0,3);
    mat1.set_element(1,1,4);
    mat2.set_element(0,0,1);
    mat2.set_element(0,1,2);
    mat2.set_element(1,0,3);
    mat2.set_element(1,1,4);
    cout<<mat1<<endl;
    cout<<mat2<<endl;
    // cout<<mat1==mat2<<endl;
    // cout<<mat1!=mat2<<endl;
    // cout<<mat1<mat2<<endl;
    // cout<<mat1>mat2<<endl;
    // cout<<mat1<=mat2<<endl;
    // //cout<<mat1>=mat2<<endl;
    return 0;
}