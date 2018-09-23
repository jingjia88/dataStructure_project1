#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;
int findPeak(int (*arr)[MAX], int rows, int columns) 
{ 
   int i =1;
   int k =0;
   vector<int> ivec;
   while(i< columns-1){
       for(int j=1;j<rows-1;j++){
           if(arr[i][j]<arr[i+1][j]){
                continue;
           }
           if(arr[i][j]<arr[i-1][j]){
                continue;
           }
           if(arr[i][j]<arr[i][j+1]){
                continue;
           }
           if(arr[i][j]<arr[i][j-1]){
                continue;
           }
           
           ivec.push_back(i);
           ivec.push_back(j);
           k++;
       }
       i++;
   }
    
    for(int n=0; n< ivec.size();n++){
        cout << ivec[n] << endl;
    }
} 

int main() 
{ 
    int arr[][MAX] = {{ 1, 8, 10, 10 }, 
                     { 1, 13, 10, 11 }, 
                     { 1, 9, 11, 2 }, 
                     { 1, 17, 10, 20 } }; 
  
    // Number of Columns 
    int rows = 4, columns = 4; 
    findPeak(arr, rows, columns); 
    return 0; 
} 
  

  