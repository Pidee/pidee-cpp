#include <iostream>
#include <Pidee.h>
#include <unistd.h>

int main() {

    Pidee::setup();

    Pidee::setLedYellow( false );
    Pidee::setLedRed( false );
    Pidee::setLedGreen( false );

    int frame = 0;

    for ( ;; ) {
    	frame++;
        if ( frame > 3 ) { 
            frame = 0;
        };
        Pidee::setLedYellow( frame == 0 );
        Pidee::setLedRed( frame == 1 );
        Pidee::setLedGreen( frame == 2 );

        usleep( 1000000 );
    }
    
    return 0;
}
