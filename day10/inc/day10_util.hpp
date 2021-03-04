// header file

#ifndef _GUARD_DAY10_UTIL_HPP_
#define _GUARD_DAY10_UTIL_HPP_

#include <map>
#include <vector>

const long get_final_difference_between_1_and_3_jolts(std::vector<size_t>& input_joltage_ratings);
const std::map<size_t, size_t>* const get_all_jolt_differences(const std::vector<size_t>& input_joltage_ratings);

#endif