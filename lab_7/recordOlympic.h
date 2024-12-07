#ifndef RECORD_OLYMPIC_H
#define  RECORD_OLYMPIC_H

#include <string>
#include "record.h"

class RecordOlympic : public Record {
    private: 
        string place;

    public:
        RecordOlympic();
        RecordOlympic(const string& sport, const string& discipline, const string& type, const string& gender, int year, const string& name, const string& country, double achievement, int place);

        string getPlace() const { return place; }
        void setPlace(int place) { this->place = place; }

        bool operator==(const RecordOlympic& anotherRecordOlympic);
        friend ostream& operator<<(ostream& stream, const RecordOlympic& anotherRecordOlympic);
        friend istream&operator>>(istream &stream, RecordOlympic &anotherRecordOlympic);
        friend ifstream& operator>>(ifstream& stream, RecordOlympic& anotherRecordOlympic);
        friend ofstream& operator<<(ofstream& stream, const RecordOlympic& anotherRecordOlympic);
};

#endif