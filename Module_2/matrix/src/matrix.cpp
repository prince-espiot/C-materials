#include <iostream>
#include <vector>

#include "matrix.hpp"

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

Matrix ReadMatrix(int n){

    std::vector<int> row;
    
    Matrix  a;
    int c;

    for (int i=0; i<n; i++)  
    {     
        
        for(int j =0; j<n; j++)
        {
            std::cin >> c;
            row.push_back(c);
            
        }
        a.push_back(row);
        row.clear();
    }

return a;
}

Matrix Rotate90Deg(const Matrix & num ){

    Matrix a(num.size()); // size of matrix num defined into a
    std::vector<int> row;
       

    for(size_t i = 0 ;i<num.size();i++ ){
        a[i]= std::vector<int> (num.size()) ;
        }
    
   for(size_t i = 0; i<num.size();i++){
       for(size_t j = 0  ; j <num.size();j++ ){
           a[j][num.size()-i-1]=num[i][j]; 
       }
            
                    
        }
    return a;
    }

    



void Print(const Matrix & num ){

  //Printing out a N x N matrix:
    size_t n = num.size();
    std::cout<< "Printing out a "<< n <<" x "<< n <<" matrix:"<<std::endl;
   for (const auto i : num)
   {
       for(const auto j :i){
           std::cout<<j<<" ";
       }
       std::cout<<std::endl;
       
   }
   
    
}