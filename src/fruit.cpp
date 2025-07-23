#include "fruit.hpp"

#include <iostream>

void print_fruit(fruit::fruit rew, bool no_art)
{
   std::cout << "\n=============================================================\n";

   if (no_art)
      print_name(rew);
   else
      print_art(rew);

   std::cout << "\n=============================================================\n";
}

void print_art(fruit::fruit rew)
{
   if (rew == fruit::apple)
   {
      std::cout << "  ,(. \n";
      std::cout << " (   ) \n";
      std::cout << "  `\"'";
   }
   else if (rew == fruit::tomato)
   {
      std::cout << "  ,v. \n";
      std::cout << " ((  ) \n";
      std::cout << "  `\"'";
   }
   else if (rew == fruit::pear)
   {
      std::cout << "   ( \n";
      std::cout << "  / \\ \n";
      std::cout << " (   ) \n";
      std::cout << "  `\"'";
   }
   else if (rew == fruit::orange)
   {
      std::cout << "  ,=. \n";
      std::cout << " (.`:) \n";
      std::cout << "  `-'";
   }
   else if (rew == fruit::pineapple)
   {
      std::cout << "  \\|/ \n";
      std::cout << "  AXA \n";
      std::cout << " /XXX\\ \n";
      std::cout << " \\XXX/ \n";
      std::cout << "  `^' ";
   }
   else if (rew == fruit::kiwi)
   {
      std::cout << "  _ \n";
      std::cout << " (:) \n";
      std::cout << "  \"";
   }
   else
   {
      std::cout << " , \n";
      std::cout << " \\`.__. \n";
      std::cout << "  `._,'";
   }
}

void print_name(fruit::fruit rew)
{
   if (rew == fruit::apple)
      std::cout << "APPLE";
   else if (rew == fruit::tomato)
      std::cout << "TOMATO";
   else if (rew == fruit::pear)
      std::cout << "PEAR";
   else if (rew == fruit::orange)
      std::cout << "ORANGE";
   else if (rew == fruit::pineapple)
      std::cout << "PINEAPPLE";
   else if (rew == fruit::kiwi)
      std::cout << "KIWI";
   else
      std::cout << "BANANA";
}
