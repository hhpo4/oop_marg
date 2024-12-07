#ifndef RECORD_CONT_H 
#define RECORD_CONT_H 

#include "record.h" 
#include <vector> 
#include <fstream> 
#include <iostream> 

using namespace std; 

class RecordContainer { 
private: 
    Record* records; 
    unsigned int maxRecords;
    unsigned int numRecords;
public: 
    RecordContainer(unsigned int maxRecords, unsigned int numRecords);  
    ~RecordContainer(); 

    void addRecord();   
    int loadFromFile(const string& filename); 
    void saveToFile(const string& filename); 
    void displayAll();
    int count_Records(const string& sport);
    void RecWomen();

    void operator +=(const Record& newRecord);
}; 

#endif 
