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
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

times convert_time(char* str) {
    times result;
    if (str == nullptr) {
        cerr << ":   ." << endl;
        return result;
    }
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    if (str_number == nullptr) {
        cerr << ":    ." << endl;
        return result;
    }
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    if (str_number == nullptr) {
        cerr << ":    ." << endl;
        return result; //    
    }
    result.minute = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    if (str_number == nullptr) {
        cerr << ":    ." << endl;
        return result;
    }
    result.second = atoi(str_number);
    return result;
}


tariff convert_tariff(char* str)
{
    if (strcmp(str, "") == 0)
        return GOROD;
    else if (strcmp(str, "") == 0)
        return MEZHGOROD;
    else if (strcmp(str, "") == 0)
        return MEZHDUNARODNY;
    else if (strcmp(str, "") == 0)
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
        throw "     .";
    }
}
