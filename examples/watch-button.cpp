#include <iostream>
#include <Pidee.h>
#include <unistd.h>

int main() {

    Pidee::setup();

    std::function<void(void)> eventHandler = [] () {
        std::cout << "Button " << ( Pidee::getButton() ? "pressed" : "released" ) << std::endl << std::flush;
    };

    Pidee::onButton( eventHandler );

    for ( ;; ) {
    	Pidee::notify();
        usleep( 10000 );
    }
    
    return 0;
}
