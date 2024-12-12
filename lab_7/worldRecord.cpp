#include "worldRecord.h"
#include <iostream>

WorldRecord::WorldRecord()
    : Record(), recordNumber("") {}

WorldRecord::WorldRecord(const std::string& sport, const std::string& discipline, const std::string& type,
                         const std::string& gender, int year, const std::string& name,
                         const std::string& country, double achievement, const std::string& recordNumber)
    : Record(sport, discipline, type, gender, year, name, country, achievement), recordNumber(recordNumber) {}

void WorldRecord::display() const {
    Record::display();
    std::cout << "Номер рекорда: " << recordNumber << "\n";
}

void WorldRecord::readFromFile(std::istream& file) {
    std::string tmpLine;

    std::getline(file, sport);
    std::getline(file, discipline);
    std::getline(file, type);
    std::getline(file, gender);

    // Проверка и обработка строки для year
    if (std::getline(file, tmpLine) && !tmpLine.empty()) {
        year = std::stoi(tmpLine);
    } else {
        throw std::invalid_argument("Некорректный формат года");
    }

    std::getline(file, name);
    std::getline(file, country);

    // Проверка и обработка строки для achievement
    if (std::getline(file, tmpLine) && !tmpLine.empty()) {
        achievement = std::stod(tmpLine);
    } else {
        throw std::invalid_argument("Некорректный формат достижения");
    }

    std::getline(file, recordNumber);
}


void WorldRecord::writeToFile(std::ostream& file) const {
    file << sport << "\n"
         << discipline << "\n"
         << type << "\n"
         << gender << "\n"
         << year << "\n"
         << name << "\n"
         << country << "\n"
         << achievement << "\n"
         << recordNumber << "\n";
}
