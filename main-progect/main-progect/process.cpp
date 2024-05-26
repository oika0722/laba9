#include "processing.h"
#include <vector>
using namespace std;

double process(vector<phone_call*>& array) {
    double totalCost = 0;
    int totalDuration = 0;
    for (phone_call* call : array) {
        totalCost += call->cost;
        totalDuration += call->duration.hour * 3600 + call->duration.minute * 60 + call->duration.second;
    }
    if (totalCost != 0 && totalDuration != 0) return totalCost / totalDuration;
    return 0;
}