#ifndef FRUIT_ENUM_HPP
#define FRUIT_ENUM_HPP

namespace fruit
{
   enum fruit
   { apple, tomato, pear, orange, pineapple, kiwi, banana, count };
}

void print_fruit(fruit::fruit rew, bool no_art);
void print_art(fruit::fruit rew);
void print_name(fruit::fruit rew);

#endif
