#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;


void findPeak(vector <vector<long int> >arr, int rows, int columns,string argf)
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
       }
       i++;
   }
    fstream file;
    
    file.open(".\\"+argf+"\\final2.peak", ios::out | ios::trunc);
    if(!file){
        cout << "Couldn't open file!\n";
        return ;
    }
    file << k << "\n";
    for(unsigned int n=0; n < ivec.size();n=n+2){
        file << ivec[n] <<","<< ivec[n+1] << "\n";
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
    int rows,cols;
    infile>>rows;
    infile>>cols;
    long int data;
    string strLine;
    int j=0;
    int i =0;
    vector<vector<long int> > darr;
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
        darr.push_back(row);
    }
    string argf =argv[1];
    findPeak(darr, rows, cols, argf);
    return 0;
}
