#ifndef RECORD_CONT_H 
#define RECORD_CONT_H 

#include <vector> 
#include <fstream> 
#include <iostream> 

#include "record.h" 
#include "recordOlympic.h"

using namespace std; 

class RecordContainer { 
private: 
    Record* records; 
    RecordOlympic* olympicRecords;
    
    unsigned int maxRecords;
    unsigned int numRecords;
    unsigned int maxOlympicRecords;
    unsigned int numOlympicRecords;

    unsigned int firstCommonRecordIndex;
    unsigned int firstOlympicRecordIndex;
    unsigned int lastOlympicRecordIndex;
public: 
    RecordContainer(unsigned int maxRecords, unsigned int numRecords, unsigned int maxOlympicRecords, unsigned int numOlympicRecords);  
    ~RecordContainer(); 

    void loadFromFile(const string& filename); 
    void saveToFile(const string& filename); 
    void displayAll();
    int count_Records(const string& sport);
    void RecWomen();

    void operator +=(const Record& newRecord);
    void operator +=(const RecordOlympic& newRecordOlympic);
}; 

#endif 
