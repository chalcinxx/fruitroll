# Fruitroll
## About
Fruitroll is a fruit-themed CLI slot machine with zero dependencies for destroying productivity.
## Features
- 7 unique fruits with different roll chances
- Crit mechanic with high-tier multipliers
- A ton of combos with varying rewards
- Full CLI argument system (see `fruitroll --info`)
- Different jackpot tiers

## Installation
Fruitroll is very easy to install and does not require any build system. It requires C++11 or later. Example with `clang`:
```bash
clang++ -std=c++11 -O2 -Iinclude src/*.cpp -o fruitroll
```
Example with `gcc`:
```bash
g++ -std=c++11 -O2 -Iinclude src/*.cpp -o fruitroll
```
To install globally, simply move the executable to `/usr/bin`:
```bash
sudo cp fruitroll /usr/bin/fruitroll
```

## Usage
```bash
./fruitroll [arguments]
```
or, alternatively, if your executable is found in `/usr/bin`:
```bash
fruitroll [arguments]
```
Arguments:
- `--help`             Display arguments.
- `--version`          Display current version.
- `--info`             Display detailed info.
- `--log-roll`         Enable roll RNG value logging.
- `--log-crit`         Enable crit RNG value logging.
- `--verbose`          Enable roll and crit RNG value logging.
- `--silent`           Completely disable delays and ASCII art.
- `--mute`             Only output final result with no delay.
- `--no-art`           Replace ASCII art with fruit names.
- `--repeat=<value>`   Repeat game `<value>` times.
- `--delay=<value>`    Set all delays to `<value>`ms.
- `--stop-on=<value>`  Force stop the game when jackpot is equal or bigger than `<value>`.
- `--seed=<value>`     Use a fixed RNG seed.


Made with C++ by chalcinxx.

## License
MIT License. See [LICENSE](LICENSE) for details.

## Contributing
This project is made for fun, but PRs are welcome.

#### WARNING!
Fruitroll is not responsible for unfinished work, excess time spent gambling or broken objects. Roll responsibly and in moderation.