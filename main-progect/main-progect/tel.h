#pragma once
#include "const.h"
struct date {
	int day;
	int month;
	int year;
};
struct times {
	int hour;
	int minute;
	int second;
};

enum tariff {
	GOROD,
	MEZHGOROD,
	MEZHDUNARODNY,
	MOBILNY,
	UNKNOWN
};

struct phone_call {
	char number[15];
	date date_;
	times time_;
	times duration;
	tariff tariff_;
	double cost;
};