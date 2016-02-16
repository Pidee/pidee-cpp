#include <iostream>
#include <Pidee.h>
#include <unistd.h>

int main() {

    Pidee::setup();

    std::function<void(std::string)> eventHandler = [] ( std::string name ) {
        std::cout << "Dip " << name << " changed. Value now: " << Pidee::getDip() << std::endl <<  std::flush;
    };

    Pidee::onDip( eventHandler );

    for ( ;; ) {
    	Pidee::notify();
        usleep( 10000 );
    }
    
    return 0;
}
