// header file

#ifndef _GUARD_DAY3_UTIL_HPP_
#define _GUARD_DAY3_UTIL_HPP_

#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> vec_str;
typedef std::string::size_type str_size;
typedef std::vector<std::string>::size_type vec_str_size;
typedef std::vector<std::string>::iterator vec_str_iter;
typedef std::vector<std::string>::const_iterator vec_str_citer;

size_t count_of_tree_encountered(vec_str& forest, vec_str_iter& forest_iter, str_size& pos_col, size_t trees_met);
void duplicate_column(vec_str_iter& forest_iter, const str_size& pos_col);

#endif