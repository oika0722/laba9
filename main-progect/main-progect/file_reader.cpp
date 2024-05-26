#include "file_reader.h"
#include "const.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

date convert_date(char* str)
{
    date result;
    if (str == nullptr) {
        cerr << "Ошибка: передан нулевой указатель." << endl;
        return result;
    }
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    if (str_number == nullptr) {
        cerr << "Ошибка: строка не содержит ." << endl;
        return result;
    }
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    if (str_number == nullptr) {
        cerr << "Ошибка: строка не содержит день ." << endl;
        return result;
    }
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    if (str_number == nullptr) {
        cerr << "Ошибка: строка не содержит месяц ." << endl;
        return result;
    }
    result.year = atoi(str_number);
    return result;
}

times convert_time(char* str) {
    times result;
    if (str == nullptr) {
        cerr << "Ошибка: передан нулевой указатель." << endl;
        return result;
    }
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    if (str_number == nullptr) {
        cerr << "Ошибка: строка не содержит часы." << endl;
        return result;
    }
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    if (str_number == nullptr) {
        cerr << "Ошибка: строка не содержит минуты." << endl;
        return result; // Здесь была пропущена скобка
    }
    result.minute = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    if (str_number == nullptr) {
        cerr << "Ошибка: строка не содержит секунды." << endl;
        return result;
    }
    result.second = atoi(str_number);
    return result;
}


tariff convert_tariff(char* str)
{
    if (strcmp(str, "город") == 0)
        return GOROD;
    else if (strcmp(str, "межгород") == 0)
        return MEZHGOROD;
    else if (strcmp(str, "международный") == 0)
        return MEZHDUNARODNY;
    else if (strcmp(str, "мобильный") == 0)
        return MOBILNY;
    else
        return UNKNOWN;
}
void read(const char* file_name, std::vector<phone_call*>& array_) {
    ifstream file(file_name);
    if (file.is_open()) {
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof()) {
            phone_call* item = new phone_call;
            file >> item->number;
            file >> tmp_buffer;
            item->date_ = convert_date(tmp_buffer);
            file >> tmp_buffer;
            item->time_ = convert_time(tmp_buffer);
            file >> tmp_buffer;
            item->duration = convert_time(tmp_buffer);
            file >> tmp_buffer;
            item->tariff_ = convert_tariff(tmp_buffer);
            file >> item->cost;
            array_.push_back(item);
        }
        file.close();
    }
    else {
        throw "Не удалось открыть файл с данными.";
    }
}