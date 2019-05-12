# MUD PROJECT

This is a simple MUD (multi-user dungeon) written in C++

## Dependencies

- Linux x86_64
- [GCC](http://gcc.gnu.org/)
- [Cmake](http://www.cmake.org/)
- [Boost](http://www.boost.org/) (only tested with 1.69.0)

## Building

To build this project, change to the project's root directory, then run the following:

    cmake -DCMAKE_BUILD_TYPE=Debug .

If everything was successful, you should now have a **Makefile**. Then you can run:

    make

Again, if everything was good, you'll now have an executable named **mud** in the project root.

## Unit Tests

These will use the Boost unit test library; the project already depends on Boost anyway. :)

Coming soon.
