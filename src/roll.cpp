#include "roll.hpp"

#include "jackpot.hpp"
#include <chrono>
#include <iostream>
#include <thread>

fruit::fruit roll(bool log_roll)
{
   int number = rand() % 100;
   if (log_roll)
      std::cout << "Rolled a " << number << ".";

   if (number == 0)
      return fruit::kiwi;
   else if (number < 34)
      return fruit::apple;
   else if (number < 54)
      return fruit::tomato;
   else if (number < 74)
      return fruit::pear;
   else if (number < 89)
      return fruit::orange;
   else if (number < 99)
      return fruit::pineapple;
   else
      return fruit::banana;
}

void play(const Args& args)
{
   if (!args.mute && !args.silent)
   {
      std::cout << "Rolling... Deducted 5$ from your bank account!\n\n";
      std::this_thread::sleep_for(std::chrono::duration<float>(args.delay / 1000.f));
   }

   fruit::fruit rew_arr[3];

   for (int i = 0; i < 3; ++i)
   {
      if (!args.mute && !args.silent)
      {
         for (int j = 0; j < 3; ++j)
         {
            std::cout << "." << std::flush;
            std::this_thread::sleep_for(std::chrono::duration<float>(args.delay / 1000.f));
         }
      }

      fruit::fruit rew = roll(args.log_roll);

      if (!args.mute)
         print_fruit(rew, args.no_art);
      rew_arr[i] = rew;
   }

   int jackpot = get_jackpot(rew_arr, args.log_crit);
   print_jackpot(jackpot);

   if (jackpot >= args.stop_on)
      std::exit(0);
}
