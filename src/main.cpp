#include "roll.hpp"

int main(int argc, char* argv[])
{
   Args args = process_args(argc, argv);

   for (int i = 0; i < args.repeat_count; ++i)
      play(args);
   return 0;
}
