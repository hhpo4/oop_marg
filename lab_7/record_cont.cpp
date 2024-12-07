#include "record_cont.h" 
#include <iostream> 
#include <fstream> 

RecordContainer::RecordContainer(unsigned int maxRecords, unsigned int numRecords, unsigned int maxOlympicRecords, unsigned int numOlympicRecords) {
    this->maxRecords = maxRecords;
    this->numRecords = numRecords;

    this->maxOlympicRecords = maxOlympicRecords;
    this->numOlympicRecords = numOlympicRecords;

    firstCommonRecordIndex = 0;
    firstOlympicRecordIndex = maxRecords;
    lastOlympicRecordIndex = maxRecords + numOlympicRecords;

    records = new Record[maxRecords]; 
    olympicRecords = new RecordOlympic[maxOlympicRecords];
} 

RecordContainer::~RecordContainer() { 
    delete[] records; 
} 

//добавить сайт в контейнер
void RecordContainer::operator +=(const Record& newRecord) { 
    if (numRecords <= maxRecords) { 
        records[numRecords++] = newRecord;
    } else {
        cout << "Достигнуто максимальное количество записей." << endl; 
    }
}

void RecordContainer::operator +=(const RecordOlympic& newRecordOlympic) { 
    if (numOlympicRecords <= maxOlympicRecords) { 
        olympicRecords[numOlympicRecords++] = newRecordOlympic;
    } else {
        cout << "Достигнуто максимальное количество олимпийских записей." << endl; 
    }
}

//загрузить данные с файла
void RecordContainer::loadFromFile(const string& filename) {
    ifstream file(filename); 
    if (file.is_open()) { 
        for (int i = 0; i < numRecords; i++) { 
            file >> records[i];
        }
        for (int i = 0; i < numOlympicRecords; i++) {
            file >> olympicRecords[i];
        }
    } else {
        cerr << "Ошибка открытия файла для чтения!" << endl; 
    }

    file.close(); 
} 

//сохранение
void RecordContainer::saveToFile(const string& filename) { 
    ofstream file(filename); 
    if (file.is_open()) { 
        for (int i = 0; i < numRecords; i++) { 
            file << records[i];
        }
        
        for (int i = 0; i < numOlympicRecords; i++) {
            file << olympicRecords[i];
        }
    } else {
        cerr << "Ошибка открытия файла для записи!" << endl; 
    }
    file.close(); 
} 

//вывод данных в консоль 
void RecordContainer::displayAll() {
    for (int i = 0; i < numRecords; i++) {
        cout << records[i] << endl;
    }

    for (int i = 0; i < numOlympicRecords; i++) {
        cout << olympicRecords[i] << endl;
    }
}

// Функция для подсчета записей по виду спорта 
//не работает
int RecordContainer::count_Records(const string& sport) { 
    int k = 0; 
    for (int i = 0; i < numRecords; i++) { 
        if (records[i].getSport() == sport) { 
            k++; 
        } 
    } 

    for (int i = 0; i < numOlympicRecords; i++) {
        if (olympicRecords[i].getSport() == sport) {
            k++;
        }
    }
    return k; 
} 

// Функция для отображения рекордов женщин 
void RecordContainer::RecWomen() { 
    cout << "\nМировые рекорды женщин, установленные за 2024 год:\n"; 
    for (int i = 0; i < numRecords; i++) { 
        if (records[i].getYear() == 2024 && records[i].getType() == "Мировой" && records[i].getGender() == "Женский") { 
            cout << records[i] << endl; 
        } 
    } 

    for (int i = 0; i < numOlympicRecords; i++) {
        if (olympicRecords[i].getYear() == 2024 && olympicRecords[i].getType() == "Мировой" && olympicRecords[i].getGender() == "Женский") {
            cout << olympicRecords[i] << endl;
        }
    }
} 
