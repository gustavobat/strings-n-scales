# strings-n-scales

`strings-n-scales` is a CLI application that prints the location of a list
of notes in the neck of a string instrument of any tuning. 

## Installation

This program uses [docopt.cpp](https://github.com/docopt/docopt.cpp)
to handle external arguments, so make sure you have it installed first.

Then clone this repo and run:
```
mkdir build
cd build
cmake ..
make install
```
The last command might require `sudo`, according to the install prefix choice.

## Usage
```
./strings-n-scales notes "D, A, F#" strings "E, A, D, G, G#"
```

## TODO

- [x] Handle args externally (using docopt lib)
- [ ] Handle more than 7 notes
- [ ] Print marks for open string notes
- [ ] Actually implement scales
