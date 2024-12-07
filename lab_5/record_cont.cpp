#include "record_cont.h" 
#include <iostream> 
#include <fstream> 

RecordContainer::RecordContainer(unsigned int maxRecords, unsigned int numRecords) { 
    this->maxRecords = maxRecords;
    this->numRecords = numRecords;

    records = new Record[maxRecords]; 
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

//загрузить данные с файла
int RecordContainer::loadFromFile(
    const string& filename) {
    ifstream file(filename); 
    if (!file.is_open()) { 
        cerr << "Ошибка открытия файла для чтения!" << endl; 
        return 0; 
    } 
    int count = 0; 
    while (count < maxRecords) { 
        file >> records[count]; 
        if (file.eof()) break;  // Проверка конца файла 
        count++; 
    } 
    file.close(); 
    return count; 
} 

//сохранение
void RecordContainer::saveToFile(const string& filename) { 
    ofstream file(filename); 
    if (!file.is_open()) { 
        cerr << "Ошибка открытия файла для записи!" << endl; 
        return; 
    } 
    for (int i = 0; i < numRecords; i++) { 
        file << records[i];
    } 
    file.close(); 
} 

//вывод данных в консоль 
void RecordContainer::displayAll() {
    for (int i = 0; i < numRecords; i++) {     
        cout << "Спорт: " << records[i].getSport() << "\n";     
        cout << "Дисциплина: " << records[i].getDiscipline() << "\n";     
        cout << "Тип: " << records[i].getType() << "\n";     
        cout << "Гендер: " << records[i].getGender() << "\n";     
        cout << "Год: " << records[i].getYear() << "\n";     
        cout << "Рекордсмен: " << records[i].getName() << "\n";     
        cout << "Страна: " << records[i].getCountry() << "\n";     
        cout << "Значение рекорда: " << records[i].getAchievement() << "\n\n";     
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
    return k; 
} 

// Функция для отображения рекордов женщин 
void RecordContainer::RecWomen() { 
    cout << "\nМировые рекорды женщин, установленные за 2024 год:\n"; 
    for (int i = 0; i < numRecords; i++) { 
        if (records[i].getYear() == 2024 && records[i].getType() == "Мировой" && records[i].getGender() == "Женский") { 
            cout << records[i]; 
        } 
    } 
} 
