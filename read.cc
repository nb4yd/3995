#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TFile.h"
#include "TROOT.h"
#include "TF1.h"

using namespace std;
   

typedef vector <double> record_t;
typedef vector <record_t> data_t;
istream& operator >> ( istream& ins, record_t& record )
  {
  // make sure that the returned record contains only the stuff we read now
  record.clear();

  // read the entire line into a string (a CSV record is terminated by a newline)
  string line;
  getline( ins, line );

  // now we'll use a stringstream to separate the fields out of the line
  stringstream ss( line );
  string field;
  while (getline( ss, field, ',' ))
    {
    // for each field we wish to convert it to a double
    // (since we require that the CSV contains nothing but floating-point values)
    stringstream fs( field );
    double f = 0.0;  // (default value is 0.0)
    fs >> f;

    // add the newly-converted field to the end of the record
    record.push_back( f );
    }

  // Now we have read a single line, converted into a list of fields, converted the fields
  // from strings to doubles, and stored the results in the argument record, so
  // we just return the argument stream as required for this kind of input overload function.
  return ins;
  }

//-----------------------------------------------------------------------------
// Let's likewise overload the stream input operator to read a list of CSV records.
// This time it is a little easier, just because we only need to worry about reading
// records, and not fields.
istream& operator >> ( istream& ins, data_t& data )
  {
  // make sure that the returned data only contains the CSV data we read here
  data.clear();

  // For every record we can read from the file, append it to our resulting data
  record_t record;
  while (ins >> record)
    {
    data.push_back( record );
    }

  // Again, return the argument stream as required for this kind of input stream overload.
  return ins;  
  }
  
int main(){

char *outFileName = "myNtree.root";
extern int optind;
gROOT->Reset(); 
TROOT troot();  
TFile outFile(outFileName,"recreate");
Double_t Det_x, Det_y, Det_z;

TTree Ntree("Ntree","Ntree");
Ntree.Branch("Det_x",&Det_x,"Det_x/D");    
Ntree.Branch("Det_y",&Det_y,"Det_y/D"); 
Ntree.Branch("Det_z",&Det_z,"Det_z/D");
  
  // Here is the data we want.
  data_t data;

  ifstream infile("./ntuples.csv");
  infile >> data;

  // Complain if something went wrong.
  if (!infile.eof())
    {
    cout << "bad file\n";
    return 1;
    }

  infile.close();

  for (unsigned n = 0; n < data.size(); n++){
    Det_x = data[n][0];
    Det_y = data[n][1];
    Det_z = data[n][2];

    Ntree.Fill();

    }
  
  outFile.Write(); // write to the output file
  outFile.Close(); // close the output file
  
  return 0;
  }
