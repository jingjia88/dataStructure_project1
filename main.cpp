#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;


int findPeak(vector <vector<long int> > arr, int rows, int columns)
{
   int i =0;
   int k =0;
   vector<int> ivec;
   while(i< rows){
        cout<<"a";
       for(int j=0;j<columns;j++){
           if(i<rows-1 && arr[i][j]<arr[i+1][j]){
                continue;
           }
           if(i>0 && arr[i][j]<arr[i-1][j]){
                continue;
           }
           if(j<columns-1 && arr[i][j]<arr[i][j+1]){
                continue;
           }
           if(j>0 && arr[i][j]<arr[i][j-1]){
                continue;
           }

           ivec.push_back(i+1);
           ivec.push_back(j+1);
           k++;
       }
       cout<<"a";
       i++;

   }
    cout<<k<<endl;
    for(int n=0; n < ivec.size();n=n+2){
        cout << ivec[n] <<","<< ivec[n+1] << endl;
    }
}

int main(int argc,char* argv[])
{
    if(argc!=2){
        cout<<"Input is wrong"<<endl;
        return 1;
    }
    string arg = ".\\"+string(argv[1])+"\\matrix.data";
    ifstream infile(arg.c_str());

    if(!infile){
        cout<<"Something wrong"<<endl;
        return 1;
    }
//    vector<vector<long int> > darr;
//    vector<long int> arr;
//    long int data;
//    int j=0;
//    while(infile >> data){
//        cout<<data;
//        if(j==cols-1){
//            darr.push_back(arr);
//            vector<long int> arr;
//            j=0;
//        }
//        arr.push_back(data);
//        j++;
//
//    }
        string strLine;
	    vector<vector<long int> > Data2D;
	    getline(infile, strLine);
	    int rows,cols;
	    infile>>rows;
	    infile>>cols;
	    while (getline(infile, strLine))
	    {
        stringstream ss(strLine);
	        vector<long int> row;
	        long int data;
	        while (ss >> data)
	        {
	            row.push_back(data);
	        }
	        Data2D.push_back(row);
	    }

cout <<  Data2D[49][2];


//    int arr[11][1000] = {{ 38,80,24,26,28,18,79,55,26,84,24,90,92 },
//                     { 34,88,63,59,23,22,67,59,44,76,28,97,99 },
//                     { 28,98,28,58,70,69,52,20,29,28,38,40,41 },
//                     { 48,27,29,37,88,83,46,83,74,27,18,21,34 },
//                     { 92,48,42,40,28,58,33,94,28,29,42,72,78 },
//                     { 10,90,24,27,11,24,17,72,65,46,28,49,77 },
//                     { 56,38,29,13,10,22,20,34,54,19,29,87,88 },
//                     { 65,34,12,10,28,13,10,58,42,28,14,64,68 },
//                     { 18,48,27,27,20,48,72,59,28,10,19,10,29 },
//                     { 28,74,30,29,17,80,81,10,38,20,18,32,33 },
//                     { 29,75,31,29,18,81,82,11,39,21,19,33,77 } };
//
//    //Number of Columns
//    int rows = 11, columns = 13;
    findPeak(Data2D, rows, cols);
    return 0;
}
