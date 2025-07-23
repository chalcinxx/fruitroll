#include "jackpot.hpp"

#include <iostream>

// Calculation functions

int get_jackpot(fruit::fruit* rew, bool log_crit)
{
   int result[fruit::count] = {};
   for (int i = 0; i < 3; ++i)
      ++result[rew[i]];
   
   int jackpot = 0;
   jackpot += get_match_jackpots(result);
   jackpot += get_combo_jackpots(result);

   if (jackpot != 0)
   {
      jackpot *= get_multipliers(result);
      jackpot *= get_crits(log_crit);
   }

   return jackpot;
}

int get_match_jackpots(int* rew)
{
   if (rew[fruit::apple] == 3)
      return triple_jackpot("APPLE", 2);
   else if (rew[fruit::tomato] == 3)
      return triple_jackpot("TOMATO", 5);
   else if (rew[fruit::pear] == 3)
      return triple_jackpot("PEAR", 10);
   else if (rew[fruit::orange] == 3)
      return triple_jackpot("ORANGE", 25);
   else if (rew[fruit::pineapple] == 3)
      return triple_jackpot("PINEAPPLE", 200);
   else if (rew[fruit::kiwi] == 3)
      return triple_jackpot("KIWI", 250000);
   else if (rew[fruit::banana] == 3)
      return triple_jackpot("BANANA", 1000000);
   else if (rew[fruit::apple] == 2)
      return double_jackpot("APPLE", 1);
   else if (rew[fruit::tomato] == 2)
      return double_jackpot("TOMATO", 2);
   else if (rew[fruit::pear] == 2)
      return double_jackpot("PEAR", 4);
   else if (rew[fruit::orange] == 2)
      return double_jackpot("ORANGE", 8);
   else if (rew[fruit::pineapple] == 2)
      return double_jackpot("PINEAPPLE", 50);
   else if (rew[fruit::kiwi] == 2)
      return double_jackpot("KIWI", 500);
   else if (rew[fruit::banana] == 2)
      return double_jackpot("BANANA", 2000);
   return 0;
}

int get_combo_jackpots(int* rew)
{
   if (rew[fruit::banana] == 1 && rew[fruit::kiwi] == 1 && rew[fruit::pineapple] == 1)
      return special_jackpot(2000);
   else if (rew[fruit::banana] == 1 && rew[fruit::kiwi] == 1 && rew[fruit::orange] == 1)
      return special_jackpot(1000);
   else if (rew[fruit::orange] == 1 && rew[fruit::pineapple] == 1 && rew[fruit::apple] == 1)
      return special_jackpot(25);
   else if (rew[fruit::apple] == 1 && rew[fruit::pear] == 1 && rew[fruit::orange] == 1)
      return special_jackpot(10);
   else if (rew[fruit::apple] == 1 && rew[fruit::pear] == 1 && rew[fruit::tomato] == 1)
      return special_jackpot(5);
   return 0;
}

int get_multipliers(int* rew)
{
   int multiplier = 1;

   if (rew[fruit::apple] > 0 && rew[fruit::pear] > 0)
      multiplier_jackpot("FRUIT BOWL", multiplier, 2);

   if (rew[fruit::apple] > 0 && rew[fruit::pineapple] > 0)
      multiplier_jackpot("APPLE", multiplier, 3);

   if (rew[fruit::banana] == 1)
      multiplier_jackpot("BANANA", multiplier, 3);

   if (rew[fruit::kiwi] == 1)
      multiplier_jackpot("KIWI", multiplier, 2);

   if (rew[fruit::kiwi] == 1 && rew[fruit::tomato] == 1)
      multiplier_jackpot("MUTANT", multiplier, 3);

   if (rew[fruit::banana] + rew[fruit::kiwi] == 3 && rew[fruit::banana] != 3 && rew[fruit::kiwi] != 3)
      multiplier_jackpot("EXOTIC", multiplier, 5);
   return multiplier;
}

int get_crits(bool log_crit)
{
   int value = rand() % 1000;
   if (log_crit)
      std::cout << "Crit landed on " << value << ".\n";

   if (value == 0)
      return crit_jackpot("KIWI", 15);
   else if (value == 999)
      return crit_jackpot("BANANA", 25);
   else if (value == 7 || value == 77 || value == 777)
      return crit_jackpot("LUCKY", 7);
   else if (value < 50)
      return crit_jackpot("CRAZY", 3);
   else if (value < 600 && value > 500)
      return crit_jackpot("INSANE", 2);
   else if (value > 975)
      return crit_jackpot("ENORMOUS", 4);
   return 1;
}

// Print helper functions

int double_jackpot(const char* name, int amount)
{
   std::cout << "DOUBLE " << name << " COMBO! JACKPOT + " << amount << "!\n";
   return amount;
}

int triple_jackpot(const char* name, int amount)
{
   std::cout << "TRIPLE " << name << " COMBO! JACKPOT + " << amount << "!\n";
   return amount;
}

int special_jackpot(int amount)
{
   std::cout << "FRUIT BOWL COMBO! JACKPOT + " << amount << "!\n";
   return amount;
}

void multiplier_jackpot(const char* name, int& mult, int amount)
{
   std::cout << name << " MULTIPLIER! JACKPOT X " << amount << "!\n";
   mult *= amount;
}

int crit_jackpot(const char* name, int amount)
{
   std::cout << name << " CRIT! JACKPOT X " << amount << "!\n";
   return amount;
}

// Print functions

void print_jackpot(int jackpot)
{
   if (jackpot == 0)
   {
      print_phrase();
      return;
   }

   print_exclamation(jackpot);
   std::cout << "Reward: " << jackpot << "$!\n";
}

void print_exclamation(int jackpot)
{
   if (jackpot <= 5)
      std::cout << "\nTINY JACKPOT!\n";
   else if (jackpot <= 15)
      std::cout << "\nSMALL JACKPOT!\n";
   else if (jackpot <= 50)
      std::cout << "\nJACKPOT!\n";
   else if (jackpot <= 250)
      std::cout << "\nBIG JACKPOT!\n";
   else if (jackpot <= 1000)
      std::cout << "\nHUGE JACKPOT!\n";
   else if (jackpot <= 500000)
      std::cout << "\nMASSIVE JACKPOT!\n";
   else
      std::cout << "\nENORMOUS JACKPOT!\n";
}

void print_phrase()
{
   static const char* phrases[]
   {
      "No luck!", "Maybe next time!", "Never give up!", "99% of gamblers quit right before the big jackpot!",
      "Try again!", "Don't give up!", "Keep rolling to win!"
   };
   std::cout << phrases[rand() % (sizeof(phrases) / sizeof(phrases[0]))] << "\n";
}
