#include "record.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Record::Record()
    : sport(""), discipline(""), type(""), gender(""),
      year(0), name(""), country(""), achievement(0.0) {}

Record::Record(const std::string& sport, const std::string& discipline, const std::string& type,
               const std::string& gender, int year, const std::string& name,
               const std::string& country, double achievement)
    : sport(sport), discipline(discipline), type(type), gender(gender),
      year(year), name(name), country(country), achievement(achievement) {}

void Record::display() const {
    std::cout << "Спорт: " << sport << "\n"
              << "Дисциплина: " << discipline << "\n"
              << "Тип: " << type << "\n"
              << "Пол: " << gender << "\n"
              << "Год: " << year << "\n"
              << "Имя: " << name << "\n"
              << "Страна: " << country << "\n"
              << "Достижение: " << achievement << "\n";
}

void Record::readFromFile(std::istream& file) {
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
}

void Record::writeToFile(std::ostream& file) const {
    file << sport << "\n"
         << discipline << "\n"
         << type << "\n"
         << gender << "\n"
         << year << "\n"
         << name << "\n"
         << country << "\n"
         << achievement << "\n";
}
