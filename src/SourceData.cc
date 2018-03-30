#include "SourceData.h"
#include <fstream>
#include <string>

using namespace std;

SourceData::SourceData(): SourceFile{"DefaultLayout.txt"}{
  int Data[19];
  ifstream File;
  File.open (SourceFile);
  string word;
  char x;
  int counter = 0;
  
  while(File>>word){
    Data[counter] = word;
    counter++;
  }
}
    
  
}

SourceData::SourceData(int * Data, String SourceFile, Board * pBoard): SourceFile{SourceFile}, pBoard{pBoard}{
  int Data[19];
  ifstream File;
  File.open (SourceFile);
  string word;
  char x;
  int counter = 0;
  
  while(File>>word){
    Data[counter] = word;
    counter++;
  }
}

int SourceData::Getdata(int num){
  return Data[num];
}

