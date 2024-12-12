#ifndef WORLD_RECORD_H
#define WORLD_RECORD_H

#include "record.h"
#include <string>

class WorldRecord : public Record {
private:
    std::string recordNumber; // Номер рекорда

public:
    WorldRecord();
    WorldRecord(const std::string& sport, const std::string& discipline, const std::string& type,
                const std::string& gender, int year, const std::string& name,
                const std::string& country, double achievement, const std::string& recordNumber);

    std::string getRecordNumber() const { return recordNumber; }
    void setRecordNumber(const std::string& recordNumber) { this->recordNumber = recordNumber; }

    void display() const override;
    void readFromFile(std::istream& file) override;
    void writeToFile(std::ostream& file) const override;
};

#endif
