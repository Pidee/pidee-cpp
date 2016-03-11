# pidee-cpp

A c++ or c++11 library for using Pidee in conjuction with [WiringPi](http://wiringpi.com). It can setup all the wiringPi funcationality so your application won't need to be run as`sudo`. It provides methods for setting the leds and reading both the buttons and switches. If c++11 is enabled, there is also an event system.

## Examples

* __flash-leds__
* __print-dip__
* __print-dip-table__
* __watch-button__
* __watch-dip__

## Getting Started

Clone the repo:

    git clone https://github.com/Pidee/pidee-cpp.git
    cd pidee-cpp
    git submodule update --init 

Build test applications:

    cd examples/
    make -j4

*Note add `-j4` on the Raspberry 2 and 3 only.*

Run a test application:

    cd examples/bin/
    ./flash-leds
    
Rebuild all examples:

    make clean
    make -j4
