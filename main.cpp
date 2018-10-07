#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;


void findPeak(vector <vector<long int> >arr, int rows, int columns)
{
   int i =0;
   int k =0;
   vector<int> ivec;
   while(i< rows){
       for( int j=0;j < columns;j++){
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
           j++;
       }
       i++;

   }
    cout<<k<<endl;
    for(unsigned int n=0; n < ivec.size();n=n+2){
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
int rows,cols;

	    infile>>rows;
	    infile>>cols;

        string strLine;
	    vector<vector<long int> > Data2D;
	    getline(infile, strLine);
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

    findPeak(Data2D, rows, cols);
    return 0;
}
