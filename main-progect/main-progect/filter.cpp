#include "filter.h"
#include <cstring>
#include <vector>
#include <iostream>
std::vector<phone_call*> filter(std::vector<phone_call*>& array, bool (*check)(phone_call* element)) {
	std::vector<phone_call*> result;
	for (auto& item : array) {
		if (check(item)) {
			result.push_back(item);
		}
	}
	return result;
}
bool check_call_by_tariff(phone_call* element) {
	if (element->tariff_ != MOBILNY)
		return false;
	return true;
}

bool check_call_by_date(phone_call* element) {
	if (element->date_.month != 11 && element->date_.year != 21)
		return false;
	return true;
}
