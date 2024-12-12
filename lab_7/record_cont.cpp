#include "record_cont.h"
#include "recordOlympic.h"
#include "worldRecord.h"
#include <fstream>
#include <iostream>
#include <string>

RecordContainer::RecordContainer(unsigned int initialCapacity)
    : capacity(initialCapacity), size(0) {
    records = new Record*[capacity];
}

RecordContainer::~RecordContainer() {
    for (unsigned int i = 0; i < size; ++i) {
        delete records[i];
    }
    delete[] records;
}

void RecordContainer::addRecord(Record* newRecord) {
    if (size < capacity) {
        records[size++] = newRecord;
    } else {
        std::cout << "Достигнуто максимальное количество записей." << std::endl;
    }
}

void RecordContainer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return;
    }

    while (!file.eof()) {
        std::string type;
        getline(file, type);
        
        Record* record = nullptr;

        if (type == "olympic") {
            record = new RecordOlympic();
        } else if (type == "world") {
            record = new WorldRecord();
        } else if (type == "common") {
            record = new Record();
        }

        record->readFromFile(file);
        addRecord(record);
    }
    file.close();
}

void RecordContainer::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return;
    }

    for (unsigned int i = 0; i < size; ++i) {
        records[i]->writeToFile(file);
    }
    file.close();
}

void RecordContainer::displayAll() const {
    for (unsigned int i = 0; i < size; ++i) {
        records[i]->display();
        std::cout << "-----------------------------" << std::endl;
    }
}

void RecordContainer::findWomenRecords2024() const {
    for (unsigned int i = 0; i < size; ++i) {
        if (records[i]->getGender() == "female" && records[i]->getYear() == 2024) {
            records[i]->display();
            std::cout << "-----------------------------" << std::endl;
        }
    }
}

int RecordContainer::countRecordsBySport(const std::string& sport) const {
    int count = 0;
    for (unsigned int i = 0; i < size; ++i) {
        if (records[i]->getSport() == sport) {
            ++count;
        }
    }
    return count;
}
