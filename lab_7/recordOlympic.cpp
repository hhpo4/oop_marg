#include "recordOlympic.h"
#include <iostream>

RecordOlympic::RecordOlympic()
    : Record(), place("") {}

RecordOlympic::RecordOlympic(const std::string& sport, const std::string& discipline, const std::string& type,
                             const std::string& gender, int year, const std::string& name,
                             const std::string& country, double achievement, const std::string& place)
    : Record(sport, discipline, type, gender, year, name, country, achievement), place(place) {}

void RecordOlympic::display() const {
    Record::display();
    std::cout << "Место проведения: " << place << "\n";
}

void RecordOlympic::readFromFile(std::istream& file) {
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

    // Проверка и обработка строки для place     
    if (std::getline(file, place)) {
    } else {
        throw std::invalid_argument("Некорректный формат места проведения");
    }
}

void RecordOlympic::writeToFile(std::ostream& file) const {
    file << sport << "\n"
         << discipline << "\n"
         << type << "\n"
         << gender << "\n"
         << year << "\n"
         << name << "\n"
         << country << "\n"
         << achievement << "\n"
         << place << "\n";
}
