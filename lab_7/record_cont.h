#ifndef RECORD_CONT_H
#define RECORD_CONT_H

#include "record.h"
#include <string>

class RecordContainer {
private:
    Record** records;
    unsigned int capacity;
    unsigned int size;

public:
    RecordContainer(unsigned int initialCapacity);
    ~RecordContainer();

    void addRecord(Record* newRecord);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
    void displayAll() const;
    void findWomenRecords2024() const;
    int countRecordsBySport(const std::string& sport) const;
};

#endif
