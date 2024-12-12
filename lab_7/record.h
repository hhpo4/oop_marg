#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>

class Record {
protected:
    std::string sport;
    std::string discipline;
    std::string type;
    std::string gender;
    int year;
    std::string name;
    std::string country;
    double achievement;

public:
    Record();
    Record(const std::string& sport, const std::string& discipline, const std::string& type,
           const std::string& gender, int year, const std::string& name,
           const std::string& country, double achievement);

    virtual ~Record() {}

    // Геттеры
    std::string getSport() const { return sport; }
    std::string getDiscipline() const { return discipline; }
    std::string getType() const { return type; }
    std::string getGender() const { return gender; }
    int getYear() const { return year; }
    std::string getName() const { return name; }
    std::string getCountry() const { return country; }
    double getAchievement() const { return achievement; }

    // Сеттеры
    void setSport(const std::string& sport) { this->sport = sport; }
    void setDiscipline(const std::string& discipline) { this->discipline = discipline; }
    void setType(const std::string& type) { this->type = type; }
    void setGender(const std::string& gender) { this->gender = gender; }
    void setYear(int year) { this->year = year; }
    void setName(const std::string& name) { this->name = name; }
    void setCountry(const std::string& country) { this->country = country; }
    void setAchievement(double achievement) { this->achievement = achievement; }

    virtual void display() const;
    virtual void readFromFile(std::istream& file);
    virtual void writeToFile(std::ostream& file) const;
};

#endif
