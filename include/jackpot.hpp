#ifndef JACKPOT_HPP
#define JACKPOT_HPP

#include "fruit.hpp"

// Calculation functions

int get_jackpot(fruit::fruit* rew, bool log_crit);
int get_match_jackpots(int* rew);
int get_combo_jackpots(int* rew);
int get_multipliers(int* rew);
int get_crits(bool log_crit);

// Print helper functions

int double_jackpot(const char* name, int amount);
int triple_jackpot(const char* name, int amount);
int special_jackpot(int amount);
void multiplier_jackpot(const char* name, int& mult, int amount);
int crit_jackpot(const char* name, int amount);

// Print functions

void print_jackpot(int jackpot);
void print_exclamation(int jackpot);
void print_phrase();

#endif
