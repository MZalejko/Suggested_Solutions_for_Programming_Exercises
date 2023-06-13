#ifndef PE_7_HXX
#define PE_7_HXX

#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <ctime>

constexpr int shuffle_times_max{19};


void mode_choose(int& num_of_args, char** values, int& num_of_balls, int& num_of_choosen_balls);
std::vector<int> Lotto(const int& num_of_balls, const int& num_of_choosen_balls);
std::vector<int> Filling_the_drawing_chamber(const int& num_of_balls);
void choose_your_numbers(std::vector<int>& your_numbs, const int& num_of_choosen_balls, const std::vector<int>& all_balls);
void show(const std::vector<int>& your_nums, const std::vector<int>& winning_nums);
void shuffle(std::vector<int>& shuffle_vect);

#endif // PE_7_HXX