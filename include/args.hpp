#ifndef ARGS_HPP
#define ARGS_HPP

#include <limits>
#include <string>

struct Args
{
   bool log_roll = false;
   bool log_crit = false;
   bool seeded = false;
   bool no_art = false;
   bool mute = false;
   bool silent = false;
   int delay = 250;
   int repeat_count = 1;
   int stop_on = std::numeric_limits<int>::max();
};

// Argument processing functions

Args process_args(int argc, char* argv[]);
int process_numerical_arg(const std::string& arg);

// Info functions

void print_help();
void print_version();
void print_info();

#endif
