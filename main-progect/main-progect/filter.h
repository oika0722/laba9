#pragma once
#include "tel.h"
#include <vector>
std::vector<phone_call*> filter(std::vector<phone_call*>& array, bool (*check)(phone_call* element));
bool check_call_by_tariff(phone_call* element);
bool check_call_by_date(phone_call* element);