#include "recordOlympic.h"
#include "record.h"

RecordOlympic::RecordOlympic() : Record() { place = ""; }

RecordOlympic::RecordOlympic(const string& sport, const string& discipline, const string& type, const string& gender, int year, const string& name, const string& country, double achievement, int place) : Record(sport, discipline, type, gender, year, name, country, achievement) { 
    this->place = place; 
}

istream &operator>>(istream &stream, RecordOlympic &anotherRecordOlympic) {
    stream >> static_cast<Record&>(anotherRecordOlympic);
    cout << "Введите место проведения: ";
    getline(stream, anotherRecordOlympic.place);
}

ostream &operator<<(ostream &stream, const RecordOlympic &anotherRecordOlympic) {
    stream << static_cast<const Record&>(anotherRecordOlympic);
    stream << "Место проведения: " << anotherRecordOlympic.place << endl;
}

ifstream &operator>>(ifstream &stream, RecordOlympic &anotherRecordOlympic) {
    stream >> static_cast<Record&>(anotherRecordOlympic);
    getline(stream, anotherRecordOlympic.place);
}

ofstream &operator<<(ofstream &stream, const RecordOlympic &anotherRecordOlympic) {
    stream << static_cast<const Record&>(anotherRecordOlympic) << anotherRecordOlympic.place << endl;
}

bool RecordOlympic::operator==(const RecordOlympic &anotherRecordOlympic) {
    return Record::operator==(anotherRecordOlympic) && place == anotherRecordOlympic.place;
}