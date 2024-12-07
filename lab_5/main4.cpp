#include <iostream> 
#include <fstream> 
#include <string> 
#include "record.h" 
#include "record_cont.h"

#define FILE_NAME "records.txt"

using namespace std; 


int main() { 
    RecordContainer records(10, 5);

    int choice;     
    do {     
        cout << "\nВыберите действие:\n";     
        cout << "1. Показать все записи\n";   
        cout << "2. Загрузить данные из файла\n";
        cout << "3. Занести данные в файл\n";     
        cout << "4. Показать мировые рекорды женщин за 2024 год\n";     
        cout << "5. Подсчитать количество рекордов по виду спорта\n";   
        cout << "6. Добавить новую запись\n";  
        cout << "7. Выход\n";     
        cout << "> ";    
        
        cin >> choice;     
        switch (choice) {     
            case 1: {     
                cout << "\nЗаписи из файла:\n";     
                records.displayAll();
                break;     
            }     
            case 2: {
                records.loadFromFile(FILE_NAME);
                break;   
            }
            case 3: {
                records.saveToFile(FILE_NAME);
                break;
            }
            case 4: {
                records.RecWomen();     
                break;                 
            }    
            case 5: {     
                string sport;     
                cout << "Введите вид спорта: ";     
                cin.ignore();
                getline(cin, sport);  
                int RCount = records.count_Records(sport);     
                cout << "Количество рекордов в " << sport << ": " << RCount << "\n";     
                break;     
            }     
            case 6: {
                Record newRecord;
                cout << "\nВведите данные новой записи:\n";
                cin >> newRecord;
                records += newRecord;     
                break; 
            }
            case 7: {
                cout << "Выход из программы." << endl;     
                break;   
            }  
            default: {
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
                break;
            }

        }          
    } while (choice != 7);     
    
    return 0;     
}
