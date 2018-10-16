// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 2
// Program: CS213-2018-A1-T1-P2
// Purpose: Skeleton code for the student to start working
// Author:  Ahmed Magdy / Ahmed Mostafa
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <valarray>
#include <cassert>

using namespace std;

struct matrix
{
    valarray<int> data;
    int row, col;
};

void createMatrix (int row, int col, int num[], matrix& mat);

matrix operator+  (matrix mat1, matrix mat2);
matrix operator-  (matrix mat1, matrix mat2);
matrix operator*  (matrix mat1, matrix mat3);
matrix operator+  (matrix mat1, int scalar);
matrix operator-  (matrix mat1, int scalar);
matrix operator*  (matrix mat1, int scalar);
ostream& operator<< (ostream &out,  matrix mat );
matrix operator+= (matrix& mat1, matrix mat2);
matrix operator-= (matrix& mat1, matrix mat2);
matrix operator+= (matrix& mat, int scalar);
matrix operator-= (matrix& mat, int scalar);
void   operator++ (matrix& mat);
void   operator-- (matrix& mat);
istream& operator>> (istream& in, matrix& mat);


int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6,1,2};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {10,11,12,13,14,15,16,17};
    int data5 [] = {20,200,20,200,20,200,20,200};
    int x, y;

    matrix mat1, mat2, mat3, mat4, mat5;
    createMatrix (4, 2, data1, mat1);
    createMatrix (4, 2, data2, mat2);
    createMatrix (2, 4, data3, mat3);
    createMatrix (2, 4, data4, mat4);
    createMatrix (2, 4, data5, mat5);

    cout << mat1 <<endl;
    cout << mat2 << endl;
    cout << mat3 << endl;
loop:
    cout <<endl<<" Choose"<<endl<<endl;
    cout << ("1- mat1 + mat2") << endl ;
    cout << ("2- mat1 - mat2") << endl ;
    cout << ("3- mat1 * mat2") << endl ;
    cout << ("4- mat1 + scaler") << endl ;
    cout << ("5- mat1 - scaler") << endl ;
    cout << ("6- mat1 * scaler") << endl ;
    cout << ("7- mat1 += mat2") << endl ;
    cout << ("8- mat1 -= mat2") << endl ;
    cout << ("9- mat1 += scaler") << endl ;
    cout << ("10- mat1 -= scaler") << endl ;
    cout << ("11- mat1++") << endl ;
    cout << ("12- mat2++") << endl ;
    cout << ("13- enter new matrix") << endl ;
    cout<<"0- end"<<endl;
    int need;
    cin>>need;
    if (need==0)
    {
        return 0;
    }
    if (need==1)
    {

        cout << (mat1 + mat2) << endl << endl;
        goto loop;
    }


    if (need==2)
    {

        cout << (mat1 - mat2) << endl << endl;
        goto loop;
    }

    if (need==3)
    {

        cout << (mat1 * mat3) << endl << endl;
        goto loop;
    }

    if (need==4)
    {

        cout << (mat1+2) << endl << endl;
        goto loop;
    }

    if (need==5)
    {

        cout << (mat1-2) << endl << endl;
        goto loop;
    }

    if (need==6)
    {

        cout << (mat1*2) << endl << endl;
        goto loop;
    }
    if (need==7)
    {
        mat1 += mat2;
        cout << mat1 << endl << endl;
        goto loop;
    }
    if (need==8)
    {
        mat1 -= mat2;
        cout << mat1 << endl << endl;
        goto loop;
    }
    if (need==9)
    {
        cout << endl;
        cout << "which matrix you want to change? " << endl;
        cout << "1-mat1 , 2-mat2 , 3-mat3" << endl;
        cin >> y;
        switch (y)
        {
        case 1:
            cout << "enter the scalar: " ;
            cin >> x;
            mat1+=x;
            cout << mat1 << endl << endl;
            break;
        case 2:
            cout << "enter the scalar: " ;
            cin >> x;
            mat2+=x;
            cout << mat2 << endl << endl;
            break;
        case 3:
            cout << "enter the scalar: " ;
            cin >> x;
            mat3+=x;
            cout << mat3 << endl << endl;
            break;
        }
        goto loop;
    }
    if (need==10)
    {
        cout << endl;
        cout << "which matrix you want to change? " << endl;
        cout << "1-mat1 , 2-mat2 , 3-mat3" << endl;
        cin >> y;
        switch (y)
        {
        case 1:
            cout << "enter the scalar: " ;
            cin >> x;
            mat1-=x;
            cout << mat1 << endl << endl;
            break;
        case 2:
            cout << "enter the scalar: " ;
            cin >> x;
            mat2-=x;
            cout << mat2 << endl << endl;
            break;
        case 3:
            cout << "enter the scalar: " ;
            cin >> x;
            mat3-=x;
            cout << mat3 << endl << endl;
            break;
        }
        goto loop;
    }
    if (need==11)
    {
        cout << "which matrix you want to change? " << endl;
        cout << "1-mat1 , 2-mat2 , 3-mat3" << endl;
        cin >> y;
        switch (y)
        {
        case 1:
            ++mat1;
            cout << mat1 << endl << endl;
            break;
        case 2:
            ++mat2;
            cout << mat2 << endl << endl;
            break;
        case 3:
            ++mat3;
            cout << mat3 << endl << endl;
            break;
        }
        goto loop;
    }
    if (need==12)
    {
        cout << "which matrix you want to change? " << endl;
        cout << "1-mat1 , 2-mat2 , 3-mat3" << endl;
        cin >> y;
        switch (y)
        {
        case 1:
            --mat1;
            cout << mat1 << endl << endl;
            break;
        case 2:
            --mat2;
            cout << mat2 << endl << endl;
            break;
        case 3:
            --mat3;
            cout << mat3 << endl << endl;
            break;
        }
        goto loop;
    }
    if (need==13)
    {
        cin >> mat4;
        cout << endl;
        cout << mat4;
    }
    return 0;
}

matrix operator+= (matrix& mat1, matrix mat2)
{
    for (int i=0 ; i < mat1.row*mat1.col ; i++)
    {
        mat1.data[i] = mat1.data[i] + mat2.data[i] ;
    }
    return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2)
{
    for (int i=0 ; i < mat1.row*mat1.col ; i++)
    {
        mat1.data[i] = mat1.data[i] - mat2.data[i] ;
    }
    return mat1;
}

matrix operator+= (matrix& mat, int scalar)
{
    for (int i=0 ; i < mat.row*mat.col ; i++)
    {
        mat.data[i] = mat.data[i] + scalar ;
    }
    return mat;
}

matrix operator-= (matrix& mat, int scalar)
{
    for (int i=0 ; i < mat.row*mat.col ; i++)
    {
        mat.data[i] = mat.data[i] - scalar ;
    }
    return mat;
}

void   operator++ (matrix& mat)
{
    for ( int i = 0 ; i < mat.row*mat.col ; i++ )
    {
        mat.data[i]+=1;
    }
}

void operator-- (matrix& mat)
{
    for ( int i = 0 ; i < mat.row*mat.col ; i++ )
    {
        mat.data[i]-=1;
    }
}

istream& operator>> (istream& in, matrix& mat)
{
    cout << "enter col. and row: ";
    in >> mat.row >> mat.col;
    cout << "Enter your matrix: ";
    for (int i=0 ; i<mat.row*mat.col ; i++)
    {
        in >> mat.data[i];
    }
    return in;
}

ostream& operator<< (ostream &out,  matrix mat )
{
    for (int i = 0; i < mat.row; ++i)
    {
        for (int j = 0; j < mat.col; ++j)
            out << " " << mat.data[i * mat.col + j];
        out << endl;
    }
    return out;
}

matrix operator+  (matrix mat1, matrix mat2)
{
    matrix mat4;
    int data4[mat1.row*mat1.col];
    createMatrix (mat1.row, mat1.col, data4, mat4);
    if(mat1.row==mat2.row&&mat1.col==mat2.col)
    {
        for (int i = 0; i < mat1.row*mat1.col; ++i)
        {
            mat4.data[i]=mat1.data[i]+mat2.data[i];
        }

        return mat4;
    }
}

matrix operator-  (matrix mat1, matrix mat2)
{
    matrix mat4;
    int data4[mat1.row*mat1.col];
    createMatrix (mat1.row, mat1.col, data4, mat4);
    if(mat1.row==mat2.row&&mat1.col==mat2.col)
    {
        for (int i = 0; i < mat1.row*mat1.col; ++i)
        {
            mat4.data[i]=mat1.data[i]-mat2.data[i];
        }
    }
    return mat4;
}

matrix operator*  (matrix mat1, matrix mat3)
{
    matrix mat4;
    int data4[mat1.row*mat3.col];
    createMatrix (mat1.row, mat3.col, data4, mat4);
    if(mat1.col==mat3.row)
    {
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat3.col; j++)
            {
                int sum = 0;
                for (int k = 0; k < mat1.col; k++)
                    sum = sum + mat1.data[i * mat1.col + k] * mat3.data[k * mat3.col + j];
                mat4.data[i * mat4.col + j] = sum;
            }

        }
    }
    return mat4;
}

matrix operator+  (matrix mat1, int scalar)
{
    matrix mat4;
    int data4[mat1.row*mat1.col];
    createMatrix (mat1.row,mat1.col, data4, mat4);
    cout <<endl<<"enter scaler : ";
    int x;
    cin >>x;
    for (int i = 0; i < mat1.row*mat1.col; ++i)
    {
        mat4.data[i]=mat1.data[i]+x;
    }
    return mat4;
}

matrix operator-  (matrix mat1, int scalar)
{
    matrix mat4;
    int data4[mat1.row*mat1.col];
    createMatrix (mat1.row, mat1.col,data4, mat4);
    cout <<endl<<"enter scaler : ";
    int x;
    cin >>x;
    for (int i = 0; i < mat1.row * mat1.col; ++i)
    {
        mat4.data[i]=mat1.data[i]-x;
    }
    return mat4;
}

matrix operator*  (matrix mat1, int scalar)
{
    matrix mat4;
    int data4[mat1.row*mat1.col];
    createMatrix (mat1.row,mat1.col, data4, mat4);

    cout <<endl<<"enter scaler : ";
    int x;
    cin >>x;
    for (int i = 0; i < mat1.row*mat1.col; ++i)
    {
        mat4.data[i]=mat1.data[i]*x;
    }
    return mat4;
}

void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data.resize (row * col);
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}
