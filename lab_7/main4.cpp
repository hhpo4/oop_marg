#include "record.h"
#include "recordOlympic.h"
#include "worldRecord.h"
#include "record_cont.h"
#include <iostream>

int main() {
    RecordContainer container(10);

    // Загрузка данных из файла
    std::cout << "Загрузка данных из файла 'data.txt'..." << std::endl;
    container.loadFromFile("data.txt");

    // Вывод всех записей
    std::cout << "\nВсе записи:\n";
    container.displayAll();

    // Поиск записей женщин за 2024 год
    std::cout << "\nЗаписи женщин за 2024 год:\n";
    container.findWomenRecords2024();

    // Подсчёт записей по определённому спорту
    std::string sport = "football";
    int footballCount = container.countRecordsBySport(sport);
    std::cout << "\nКоличество записей по спорту '" << sport << "': " << footballCount << "\n";

    // Добавление нового мирового рекорда
    WorldRecord* newWorldRecord = new WorldRecord(
        "Плавание", "Баттерфляй", "Индивидуальный", "мужчина", 2024,
        "Майкл Фелпс", "США", 50.2, "WR-2024-001"
    );
    container.addRecord(newWorldRecord);

    // Добавление нового олимпийского рекорда
    RecordOlympic* newOlympicRecord = new RecordOlympic(
        "Легкая атлетика", "Бег на 100м", "Индивидуальный", "женщина", 2024,
        "Шелли-Энн Фрейзер-Прайс", "Ямайка", 10.61, "Париж"
    );
    container.addRecord(newOlympicRecord);

    // Сохранение всех данных в файл
    std::cout << "\nСохранение данных в файл 'output.txt'..." << std::endl;
    container.saveToFile("output.txt");

    std::cout << "Программа завершена.\n";
    return 0;
}
