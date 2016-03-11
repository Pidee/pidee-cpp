.PHONY: all
all: bin/watch-dip bin/watch-button bin/flash-leds bin/print-dip bin/print-dip-table

bin/print-dip-table: print-dip-table.cpp ../src/Pidee.cpp ../libs/libpidee/src/libpidee.h
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp print-dip-table.cpp -o bin/print-dip-table

bin/print-dip: print-dip.cpp ../src/Pidee.cpp ../libs/libpidee/src/libpidee.h
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp print-dip.cpp -o bin/print-dip

bin/watch-dip: watch-dip.cpp ../src/Pidee.cpp ../libs/libpidee/src/libpidee.h
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp watch-dip.cpp -o bin/watch-dip

bin/watch-button: watch-button.cpp ../src/Pidee.cpp ../libs/libpidee/src/libpidee.h
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp watch-button.cpp -o bin/watch-button

bin/flash-leds: flash-leds.cpp ../src/Pidee.cpp ../libs/libpidee/src/libpidee.h
	g++ -std=c++11 -g -lwiringPi -I../libs/libpidee/src -Wall -I../src ../src/Pidee.cpp flash-leds.cpp -o bin/flash-leds

.PHONY: clean
clean:
	rm bin/*
