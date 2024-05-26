#include "pch.h"
#include "CppUnitTest.h"
#include "../main-progect/tel.h"
#include "../main-progect/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    phone_call* build_call(char number[15], int date_day, int date_month, int date_year,
        int time_hour, int time_minute, int time_second,
        int dur_hour, int dur_minute, int dur_second, string tariff, double cost) {
        phone_call* call = new phone_call;
        strcpy_s(call->number, number);
        call->date_.day = date_day;
        call->date_.month = date_month;
        call->date_.year = date_year;
        call->time_.hour = time_hour;
        call->time_.minute = time_minute;
        call->time_.second = time_second;
        call->duration.hour = dur_hour;
        call->duration.minute = dur_minute;
        call->duration.second = dur_second;
        if (tariff == "город") call->tariff_ = GOROD;
        else if (tariff == "межгород") call->tariff_ = MEZHGOROD;
        else if (tariff == "международный") call->tariff_ = MEZHDUNARODNY;
        else if (tariff == "мобильный") call->tariff_ = MOBILNY;
        else call->tariff_ = UNKNOWN;
        call->cost = cost;
        return call;
    }

    void delete_call(vector<phone_call*>& array)
    {
        for (auto call : array) {
            delete call;
        }
        array.clear();
    }


    TEST_CLASS(unittestproject)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            vector<phone_call*> calls;
            calls.push_back(build_call("+375336514832", 24, 9, 23, 5, 9, 0, 0, 6, 3, "мобильный", 1643));
            calls.push_back(build_call("+375294652718", 25, 3, 20, 4, 0, 2, 1, 0, 3, "мобильный", 1643));
            calls.push_back(build_call("+375256391523", 14, 12, 19, 14, 0, 2, 0, 16, 3, "международный", 1643));
            Assert::AreEqual(1.0, process(calls));
            delete_call(calls);
        }

        TEST_METHOD(TestMethod2)
        {
            vector<phone_call*> calls;
            calls.push_back(build_call("+375337123238", 15, 5, 23, 5, 45, 0, 0, 6, 0, "мобильный", 540));
            calls.push_back(build_call("+375321567024", 8, 3, 4, 14, 0, 2, 0, 6, 8, "мобильный", 550));
            calls.push_back(build_call("+375256324523", 3, 5, 14, 14, 0, 2, 0, 16, 12, "международный", 1460));
            Assert::AreEqual(1.5, process(calls));
            delete_call(calls);
        }

        TEST_METHOD(TestMethod3)
        {
            vector<phone_call*> calls;
            calls.push_back(build_call("+375333535333", 16, 5, 23, 5, 45, 0, 0, 0, 10, "мобильный", 15));
            calls.push_back(build_call("+372949364543", 6, 3, 4, 14, 0, 2, 0, 0, 15, "мобильный", 15));
            calls.push_back(build_call("+375802436515", 3, 5, 14, 14, 0, 2, 0, 0, 25, "международный", 20));
            Assert::AreEqual(1.0, process(calls));
            delete_call(calls);
        }
    };
}
