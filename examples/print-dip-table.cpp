#include <iostream>
#include <Pidee.h>
#include <unistd.h>

int main() {

    Pidee::setup();

    printf( "|-----|-------|\n" );
    printf( "| DIP | Value |\n" );
    printf( "|-----|-------|\n" );

    for ( int i = 0; i <8 ; i++ ) {
    	printf( "|  %d  |   %d   | \n", i+1, Pidee::getDip( i ) );
    }
    
    printf( "|-----|-------|\n" );

    return 0;
}
