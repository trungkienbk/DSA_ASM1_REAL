#include "SymbolTable.h"
using namespace std;
void SymbolTable::run(string filename){
    fstream input_file;
    string line;
    int count = 0;
    input_file.open(filename);
    if(input_file){
        while(std::getline(input_file,line)){
            if( count == 2){
                return;
            }
            cout<<line<<endl;
            count++;
        }
    }
    else {
        cout<<filename<< " not exist";
    }
    input_file.close();
}