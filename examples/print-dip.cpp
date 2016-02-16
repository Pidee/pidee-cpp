#include <iostream>
#include <Pidee.h>
#include <unistd.h>

int main() {

    Pidee::setup();

    std::cout << Pidee::getDip() << std::endl <<  std::flush;
    
    return 0;
}
