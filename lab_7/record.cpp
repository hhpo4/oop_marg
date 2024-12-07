#include "record.h"

Record::Record() {
	sport = "";
	discipline = "";
	type = "";
	gender = "";
	year = 0;
	name = "";
	country = "";
	achievement = 0;
}

Record::Record(const string& sport, const string& discipline, const string& type, const string& gender, int year, const string& name, const string& country, double achievement) {
	this->sport = sport;
	this->discipline = discipline;
	this->type = type;
	this->gender = gender;
	this->year = year;
	this->name = name;
	this->country = country;
	this->achievement = achievement;
}

ofstream& operator<<(ofstream& stream, const Record& anotherRecord) {
	stream << anotherRecord.sport << endl;
	stream << anotherRecord.discipline << endl;
	stream << anotherRecord.type << endl;
	stream << anotherRecord.gender << endl;
	stream << anotherRecord.year << endl;
	stream << anotherRecord.name << endl;
	stream << anotherRecord.country << endl;
	stream << anotherRecord.achievement << endl;
	return stream;
}

ifstream& operator>>(ifstream& stream, Record& anotherRecord) {
	getline(stream, anotherRecord.sport);
	getline(stream, anotherRecord.discipline);
	getline(stream, anotherRecord.type);
	getline(stream, anotherRecord.gender);
	stream >> anotherRecord.year;
	stream.ignore();
	getline(stream, anotherRecord.name);
	getline(stream, anotherRecord.country);
	stream >> anotherRecord.achievement;
	stream.ignore();
	return stream;
}

ostream& operator<<(ostream& stream, const Record& anotherRecord) {
	cout << "Спорт: " << anotherRecord.sport << "\n";     
	cout << "Дисциплина: " << anotherRecord.discipline << "\n";     
	cout << "Тип: " << anotherRecord.type << "\n";     
	cout << "Гендер: " << anotherRecord.gender << "\n";     
	cout << "Год: " << anotherRecord.year << "\n";     
	cout << "Рекордсмен: " << anotherRecord.name << "\n";     
	cout << "Страна: " << anotherRecord.country << "\n";     
	cout << "Значение рекорда: " << anotherRecord.achievement << "\n";
	return stream;
}

istream& operator>>(istream& stream, Record& anotherRecord) {
	string tmpLine;
    cout << "Введите вид спорта: "; 
	cin.ignore();
	getline(stream, anotherRecord.sport);
    cout << "Введите дисциплину: "; 
	getline(stream, anotherRecord.discipline);
	cout << "Введите тип: "; 
	getline(stream, anotherRecord.type);
	cout << "Введите пол: "; 
	getline(stream, anotherRecord.gender);
	cout << "Введите год: "; 
	getline(stream, tmpLine);
	anotherRecord.year = stoi(tmpLine);
	cout << "Введите имя рекордсмена: "; 
	getline(stream, anotherRecord.name);
	cout << "Введите страну: ";
	getline(stream, anotherRecord.country);
	cout << "Введите значение рекорда: "; 
	getline(stream, tmpLine);
	anotherRecord.achievement = stod(tmpLine);
	return stream;
}

bool Record::operator==(const Record& anotherRecord) {
	return (
		this->sport == anotherRecord.sport &&
		this->discipline == anotherRecord.discipline &&
		this->type == anotherRecord.type &&
		this->gender == anotherRecord.gender &&
		this->year == anotherRecord.year &&
		this->name == anotherRecord.name &&
		this->country == anotherRecord.country &&
		this->achievement == anotherRecord.achievement
	);
}