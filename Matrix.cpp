#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
/* function to get rows of string   */
int no_rows(string a)
{
    int length_of_string= a.length();
    int rows = 0;
    char element;
    for (int i=0; i<length_of_string ;i++)
    {
        element =a.at(i);
        if(element ==';')
        {
            rows+=1;
        }
    }
    rows+=1;
    return rows;
}
/* function to get columns of string */
int no_columns(string a)
{
    int length_of_string = a.length();
    int no_numbers=0;
    char element;
    int columns;
    for (int i=0; i<length_of_string ; i++)
    {
        element=a.at(i);
        if(element!= ' ' && element!= ';' && element!= '[' && element!= ']')                    /* to know if number is more than one digit or no */
        {
            for (int n=0; n<length_of_string ; n++)
            {
                element=a.at(i+n);
                if(element==' ' || element== ';' || element== ']')
                {
                    no_numbers+=1;
                    i+=n;
                    break;
                }

            }
        }
    }
    columns= (no_numbers) / no_rows(a);
    return columns;
}
/* function to make string array of numbers  */
void no_matrix(string a,float array_of_numbers[100][100])
{
    int position_of_space;
    int position_of_semicolon;
    int position_of_first_number=1;
    int length_of_new_matrix=(a.length())-2;
    string number;                                                                  //string of number that will be printed
    string substring_of_a;                                                          //string of a after removing number printed
    substring_of_a=a.substr(position_of_first_number,(length_of_new_matrix));       //string after removing square brackets
    for (int i=0; i<no_rows(a); i++)
    {
        for (int j=0; j<no_columns(a); j++)
        {
            position_of_space=substring_of_a.find(" ");
            position_of_semicolon=substring_of_a.find(";");
            if((position_of_space<position_of_semicolon) || (position_of_semicolon==-1))
            {
                number=substring_of_a.substr(0,position_of_space);
                array_of_numbers [i][j]=atof(number.c_str());
                position_of_first_number=(position_of_space)+1;
                length_of_new_matrix-=(number.length()+1);
            }
            else
            {
                number=substring_of_a.substr(0,position_of_semicolon);
                array_of_numbers [i][j]=atof(number.c_str());
                position_of_first_number=(position_of_semicolon)+1;
                length_of_new_matrix-=(number.length()+1);
            }
            substring_of_a=substring_of_a.substr(position_of_first_number,(length_of_new_matrix));
        }
    }
}
/* to sum two matrices     */
void sum_matrices(float array_no_matrix1 [100][100],float array_no_matrix2 [100][100],float total_sum_matrices [100][100],string a,string b)
{
    if ((no_rows(a)==no_rows(b))&&(no_columns(a)==no_columns(b)))
    {
        for(int i=0; i<no_rows(a); i++)
    {
        for(int j=0; j<no_columns(b); j++)
        {
            total_sum_matrices [i][j]= array_no_matrix1[i][j]+array_no_matrix2[i][j];

        }
    }
    }
}
/* to convert array to string                                                     */
string string_matrix(float total_operator_matrices[100][100],string a,string b)
{
    string total_matrices="[";
    for (int i=0; i<no_rows(a); i++) /* hna 3malt rows m3 a w columns m3 b 3shan el multiplication hyfr2 ama sum or differ. mosh hyfr2 m3ahom 7aga */
    {
        for(int j=0; j<no_columns(b); j++)
        {
            ostringstream number;
            number << total_operator_matrices[i][j];
            total_matrices+=number.str();
            if (j<no_columns(b)-1)
            {
                total_matrices+=" ";
            }
            else if(j==no_columns(b)-1&& i!=no_rows(a)-1)
            {
                total_matrices+=";";
            }
        }
    }
    total_matrices+="]";
    return total_matrices;
}
/* to subtract two matrices     */
void subtract_matrices(float array_no_matrix1 [100][100],float array_no_matrix2 [100][100],float total_subtract_matrices [100][100],string a,string b)
{
    if ((no_rows(a)==no_rows(b))&&(no_columns(a)==no_columns(b)))
    {
        for(int i=0; i<no_rows(a); i++)
    {
        for(int j=0; j<no_columns(b); j++)
        {
            total_subtract_matrices [i][j]= array_no_matrix1[i][j]- array_no_matrix2[i][j];

        }
    }
    }
}
/* to multiply two matrices           */
void multiply_matrices (float array_no_matrix1 [100][100],float array_no_matrix2 [100][100], float total_multiply_matrices [100][100],string a, string b)
{
    if (no_columns(a)==no_rows(b))
    {
        for (int i=0; i<no_rows(a); i++)
        {
            for (int j=0; j<no_columns(b); j++)
            {
                total_multiply_matrices[i][j]=0;
                for (int k=0; k<no_rows(b); k++)
                {
                    total_multiply_matrices [i][j]+=array_no_matrix1[i][k] * array_no_matrix2 [k][j];
                }
            }
        }
    }
    else
    {
        cout << "ERROR";
    }
}
int main()
{
    /* to take matrix 1 from user and get rows and columns of Matrix 1(string)    */
    string matrix1;
    getline (cin,matrix1);
    int rows_matrix1 = no_rows(matrix1);
    int columns_matrix1= no_columns(matrix1);
    /* to convert a first string to matrix                                        */
    float array_no_matrix1 [100][100];
    no_matrix(matrix1,array_no_matrix1);
    /* to know operator.I made it here to take operator from user before string 2 */
    /* elmafrod makano yb2a 3nd operatot t7t                                      */
    string operator_;
    getline(cin,operator_);
    /* to take matrix 2 from user and get rows and columns of Matrix 2(string)    */
    string matrix2;
    getline (cin,matrix2);
    int rows_matrix2 = no_rows(matrix2);
    int columns_matrix2 = no_columns(matrix2);
    /* to convert a second string to matrix                                       */
    float array_no_matrix2 [100][100];
    no_matrix(matrix2,array_no_matrix2);
    /* to sum,subtract or multiply two matrices and print them string        */

    float total_sum_matrices [100][100];
    float total_subtract_matrices [100][100];
    float total_multiply_matrices [100][100];
    string total_matrices;
    if (operator_=="+")
    {
        if(no_rows(matrix1)==no_rows(matrix2)&&no_columns(matrix1)==no_columns(matrix2))
        {
            sum_matrices(array_no_matrix1,array_no_matrix2,total_sum_matrices,matrix1,matrix2);
            total_matrices=string_matrix(total_sum_matrices,matrix1,matrix2);
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if (operator_=="-")
    {
        if(no_rows(matrix1)==no_rows(matrix2)&&no_columns(matrix1)==no_columns(matrix2))
        {
            subtract_matrices(array_no_matrix1,array_no_matrix2,total_subtract_matrices,matrix1,matrix2);
            total_matrices=string_matrix(total_subtract_matrices,matrix1,matrix2);
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if (operator_=="*")
    {
        if(no_columns(matrix1)==no_rows(matrix2))
        {
            multiply_matrices(array_no_matrix1,array_no_matrix2,total_multiply_matrices,matrix1,matrix2);
            total_matrices=string_matrix(total_multiply_matrices,matrix1,matrix2);
        }
        else
        {
            cout << "ERROR";
        }
    }
    cout << total_matrices << endl;
    return 0;
}
