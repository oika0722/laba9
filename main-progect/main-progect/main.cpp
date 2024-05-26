#include <iostream>
#include "tel.h"
#include "file_reader.h"
#include "const.h"
#include "filter.h"
#include "sort.h"
#include <iomanip>
#include <vector>
#include <clocale>

using namespace std;

void output(const phone_call* call) {
    cout << "�������. �����: ";
    cout << call->number << "\n" << "���� ������: ";
    cout << call->date_.day << ".";
    cout << call->date_.month << ".";
    cout << call->date_.year << ".\n";
    cout << "����� ������: ";
    cout << call->time_.hour << ":";
    cout << call->time_.minute << ":";
    cout << call->time_.second << ".\n";
    cout << "����������������� ������: ";
    cout << call->duration.hour << ":";
    cout << call->duration.minute << ":";
    cout << call->duration.second << ".\n";
    cout << "�����: ";
    cout << call->tariff_ << "\n";
    cout << "��������� �� ������:";
    cout << call->cost << "\n";
}

int main() {
    setlocale(LC_ALL, "russian");
    cout << "������������ ������ #9. GIT\n";
    cout << "������� #9. ���������� ���������\n";
    cout << "�����: ��������� �����\n";
    cout << "������: 23����1�\n";
    vector<phone_call*> calls;
    try {
        read("data.txt", calls);
        cout << "/////////////////////////////////////////\n";
        bool (*check_function)(phone_call*) = NULL;
        int n;
        cout << "��������, ����� ���� �� ������ ������\n";
        cout << "1. ������� ��� ���������� ��������� � ������ 2021 ����.\n";
        cout << "2. ������� ��� ���������� ��������� �� ��������� ��������.\n";
        cin >> n;
        vector<phone_call*> filtered;
        switch (n) {
        case 1:
            cout << "//////////////////////////////////////////\n";
            filtered = filter(calls, check_call_by_date);
            if (!filtered.empty()) {
                Heap_sort(filtered);
                for (auto& call : filtered) {
                    output(call);
                }
                cout << "/////////////////////////////////////////\n";
                Quick_sort(filtered, 0, filtered.size() - 1);
                for (auto& call : filtered) {
                    output(call);
                }
            }
            for (auto& call : calls) {
                delete call;
            }
            break;
        case 2:
            cout << "//////////////////////////////////////////\n";
            filtered = filter(calls, check_call_by_tariff);
            if (!filtered.empty()) {
                
                cout << "/////////////////////////////////////////\n";
                Quick_sort(filtered, 0, filtered.size() - 1);
                for (auto& call : filtered) {
                    output(call);
                }
            }
            for (auto& call : calls) {
                delete call;
            }
            break;
        default:
            throw runtime_error("Incorrect choice");
        }
    }
    catch (const runtime_error& error)
    {
        cout << error.what() << '\n';
        return -1;
    }
    return 0;
}