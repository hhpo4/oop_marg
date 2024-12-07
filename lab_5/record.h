#ifndef RECORD_H 
#define RECORD_H 

#include <iostream> 
#include <fstream> 
#include <string> 

using namespace std; 

#define MAX_RECORDS 40 

class Record { 
private: 
    string sport; 
    string discipline; 
    string type; 
    string gender; 
    int year; 
    string name; 
    string country; 
    double achievement; 

public: 
    string getSport() const { return sport; } 
    string getDiscipline() const { return discipline; } 
    string getType() const { return type; } 
    string getGender() const { return gender; } 
    int getYear() const { return year; } 
    string getName() const { return name; } 
    string getCountry() const { return country; } 
    double getAchievement() const { return achievement; } 

    void setSport(const string& sport) { this->sport = sport; } 
    void setDiscipline(const string& discipline) { this->discipline = discipline; } 
    void setType(const string& type) { this->type = type; } 
    void setGender(const string& gender) { this->gender = gender; } 
    void setYear(int year) { this->year = year; } 
    void setName(const string& name) { this->name = name; } 
    void setCountry(const string& country) { this->country = country; } 
    void setAchievement(double achievement) { this->achievement = achievement; } 

    bool operator==(const Record& anotherRecord);

    friend ostream& operator<<(ostream& stream, const Record& anotherRecord);
    friend istream& operator>>(istream& stream, Record& anotherRecord);
    friend ofstream& operator<<(ofstream& stream, const Record& anotherRecord);
    friend ifstream& operator>>(ifstream& stream, Record& anotherRecord);
}; 

#endif 
