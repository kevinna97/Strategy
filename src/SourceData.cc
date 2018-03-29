#include "SourceData.h"

using namespace std;

SourceData::SourceData(int * Data, String SourceFile, Board * pBoard): SourceFile{SourceFile}, pBoard{pBoard}{
  int Data[19];
}

int SourceData::Getdata(int num){
  return Data[num];
}

