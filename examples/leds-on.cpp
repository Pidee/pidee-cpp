#include <iostream>
#include <Pidee.h>
#include <unistd.h>

int main() {

    Pidee::setup();

    Pidee::setLedYellow( true );
    Pidee::setLedRed( true );
    Pidee::setLedGreen( true );
    
    return 0;
}
