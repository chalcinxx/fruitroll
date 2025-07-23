#include "args.hpp"

#include <iostream>

// Argument processing functions

Args process_args(int argc, char* argv[])
{
   Args args = {};

   for (int i = 1; i < argc; ++i)
   {
      std::string arg = argv[i];

      if (arg == "--help")
      {
         print_help();
         std::exit(0);
      }
      else if (arg == "--version")
      {
         print_version();
         std::exit(0);
      }
      else if (arg == "--info")
      {
         print_info();
         std::exit(0);
      }
      else if (arg == "--log-roll")
      {
         args.log_roll = true;
         std::cout << "Roll logging enabled!\n";
      }
      else if (arg == "--log-crit")
      {
         args.log_crit = true;
         std::cout << "Crit logging enabled!\n";
      }
      else if (arg == "--verbose")
      {
         args.log_crit = args.log_roll = true;
         std::cout << "Roll and crit logging enabled!\n";
      }
      else if (arg == "--silent")
      {
         args.silent = args.no_art = true;
         std::cout << "Output will be more silent!\n";
      }
      else if (arg == "--mute")
      {
         args.mute = true;
         std::cout << "All output except jackpot will be muted!\n";
      }
      else if (arg == "--no-art")
      {
         args.no_art = true;
         std::cout << "Fruit names will be used instead of art!\n";
      }
      else if (arg.rfind("--delay", 0) == 0)
      {
         args.delay = std::max(process_numerical_arg(arg), 0);
         std::cout << "Using a delay of " << args.delay << "ms (auto clamped)!\n";
      }
      else if (arg.rfind("--repeat", 0) == 0)
      {
         args.repeat_count = std::min(std::max(process_numerical_arg(arg), 1), 100000);
         std::cout << "Will repeat " << args.repeat_count << " times (auto clamped)!\n";
      }
      else if (arg.rfind("--stop-on", 0) == 0)
      {
         args.stop_on = std::max(process_numerical_arg(arg), 0);
         std::cout << "Will stop when jackpot exceeds or is " << args.stop_on << "$!\n"; 
      }
      else if (arg.rfind("--seed", 0) == 0)
      {
         unsigned seed = std::max(process_numerical_arg(arg), 0);
         srand(seed);
         args.seeded = true;
         std::cout << "Using a fixed RNG seed of " << seed << " (auto clamped).\n";
      }
      else
      {
         std::cout << "Unknown argument: '" << arg << "'.\n";
         std::cout << "See commands with '--help' argument.\n";
         std::exit(-1);
      }
   }

   if (!args.seeded)
      srand(time(nullptr));
   return args;
}

int process_numerical_arg(const std::string& arg)
{
   size_t pos = arg.find("=");

   if (pos == arg.npos || pos == arg.size() - 1)
   {
      std::cout << "Invalid arg: '" << arg << "', expected '[arg]=[number]'.\n";
      std::cout << "See commands with '--help' argument.\n";
      std::exit(-1);
   }

   std::string string = arg.substr(pos + 1);
   int number = 0;

   try
   {
      number = std::stoi(string);
   }
   catch (...)
   {
      std::cout << "Invalid arg: '" << arg << "', could not convert to a number.\n";
      std::cout << "See commands with '--help' argument.\n";
      std::exit(-1);
   }
   return number;
}

// Info functions

void print_help()
{
   std::cout << "--help             Display arguments.\n";
   std::cout << "--version          Display current version.\n";
   std::cout << "--info             Display detailed info.\n";
   std::cout << "--log-roll         Enable roll RNG value logging.\n";
   std::cout << "--log-crit         Enable crit RNG value logging.\n";
   std::cout << "--verbose          Enable roll and crit RNG value logging.\n";
   std::cout << "--silent           Completely disable delays and ASCII art.\n";
   std::cout << "--mute             Only output final result with no delay.\n";
   std::cout << "--no-art           Replace ASCII art with fruit names.\n";
   std::cout << "--repeat=<value>   Repeat game <value> times.\n";
   std::cout << "--delay=<value>    Set all delays to <value>ms.\n";
   std::cout << "--stop-on=<value>  Force stop the game when jackpot is equal or bigger than <value>.\n";
   std::cout << "--seed=<value>     Use a fixed RNG seed.\n";
}

void print_version()
{
   std::cout << "Fruitroll version 1.0.0\n";
   std::cout << "Made with C++ by chalcinxx.\n";
}

void print_info()
{
   std::cout << "   ___            _                 _ _  \n";
   std::cout << "  / __)          (_)_              | | | \n";
   std::cout << " | |__ ____ _   _ _| |_   ____ ___ | | | \n";
   std::cout << " |  __) ___) | | | |  _) / ___) _ \\| | | \n";
   std::cout << " | | | |   | |_| | | |__| |  | |_| | | | \n";
   std::cout << " |_| |_|    \\____|_|\\___)_|   \\___/|_|_| \n";

   std::cout << "\nWelcome to Fruitroll!\n";
   std::cout << "\nUsage:\n";
   std::cout << "fruitroll [arguments]\n";
   
   std::cout << "\nArguments:\n";
   print_help();

   std::cout << "\nExamples:\n";
   std::cout << "fruitroll             Play in standard mode.\n";
   std::cout << "fruitroll --log-roll  Play with internal RNG logging.\n";
   std::cout << "fruitroll --seed=248  Use a fixed RNG seed.\n\n";
   print_version();
}
