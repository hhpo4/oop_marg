#ifndef RECORD_OLYMPIC_H
#define RECORD_OLYMPIC_H

#include "record.h"

class RecordOlympic : public Record {
private:
    std::string place;

public:
    RecordOlympic();
    RecordOlympic(const std::string& sport, const std::string& discipline, const std::string& type,
                  const std::string& gender, int year, const std::string& name,
                  const std::string& country, double achievement, const std::string& place);

    std::string getPlace() const { return place; }
    void setPlace(const std::string& place) { this->place = place; }

    void display() const override;
    void readFromFile(std::istream& file) override;
    void writeToFile(std::ostream& file) const override;
};

#endif
