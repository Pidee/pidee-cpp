all:
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp print-dip-table.cpp -o print-dip-table
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp print-dip.cpp -o print-dip
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp watch-dip.cpp -o watch-dip
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp watch-button.cpp -o watch-button
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp flash-leds.cpp -o flash-leds