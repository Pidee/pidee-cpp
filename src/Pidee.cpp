#include "Pidee.h"
#include "libpidee.h"
#include "wiringPi.h"
#include <pthread.h>
#include <stdexcept>
#include <vector>
#include <iostream>

// Flags, State & Utils
// ====================
#ifdef PIDEE_EVENTS
std::vector<std::function<void(void)>> buttonSubscriberFns;
std::vector<std::function<void(std::string)>> dipSubscriberFns;
std::vector<pidee_feature> eventLog;

pthread_mutex_t interupt_lock;

bool interuptsInitalised = false;

void interupt_handler ( pidee_feature feature ) {
    pthread_mutex_lock( &interupt_lock );
    eventLog.push_back( feature );
    pthread_mutex_unlock( &interupt_lock );
}

void initInterupts () {
    if ( pthread_mutex_init( &interupt_lock, NULL ) != 0 ) {
        printf( "\n Pidee mutex init failed\n" );
        exit( EXIT_FAILURE );
    }
    pidee_feature_enable_interupt( &pidee_feature_button );
    pidee_feature_enable_interupt( &pidee_feature_dip_1 );
    pidee_feature_enable_interupt( &pidee_feature_dip_2 );
    pidee_feature_enable_interupt( &pidee_feature_dip_3 );
    pidee_feature_enable_interupt( &pidee_feature_dip_4 );
    pidee_feature_enable_interupt( &pidee_feature_dip_5 );
    pidee_feature_enable_interupt( &pidee_feature_dip_6 );
    pidee_feature_enable_interupt( &pidee_feature_dip_7 );
    pidee_feature_enable_interupt( &pidee_feature_dip_8 );
    pidee_feature_button.interupt_handler = &interupt_handler;
    pidee_feature_dip_1.interupt_handler = &interupt_handler;
    pidee_feature_dip_2.interupt_handler = &interupt_handler;
    pidee_feature_dip_3.interupt_handler = &interupt_handler;
    pidee_feature_dip_4.interupt_handler = &interupt_handler;
    pidee_feature_dip_5.interupt_handler = &interupt_handler;
    pidee_feature_dip_6.interupt_handler = &interupt_handler;
    pidee_feature_dip_7.interupt_handler = &interupt_handler;
    pidee_feature_dip_8.interupt_handler = &interupt_handler;
    interuptsInitalised = true;
}
#endif

pidee_feature *dipsFeaturesPtrs[ 8 ] = { &pidee_feature_dip_1, 
                                         &pidee_feature_dip_2, 
                                         &pidee_feature_dip_3, 
                                         &pidee_feature_dip_4, 
                                         &pidee_feature_dip_5, 
                                         &pidee_feature_dip_6, 
                                         &pidee_feature_dip_7, 
                                         &pidee_feature_dip_8 };

// Setup
// =====

void Pidee::setup() {

    // Setup WiringPi and all features
    wiringPiSetupSys();

    pidee_feature_setup( &pidee_feature_dip_1 );
    pidee_feature_setup( &pidee_feature_dip_2 );
    pidee_feature_setup( &pidee_feature_dip_3 );
    pidee_feature_setup( &pidee_feature_dip_4 );
    pidee_feature_setup( &pidee_feature_dip_5 );
    pidee_feature_setup( &pidee_feature_dip_6 );
    pidee_feature_setup( &pidee_feature_dip_7 );
    pidee_feature_setup( &pidee_feature_dip_8 );
    pidee_feature_setup( &pidee_feature_button );
    pidee_feature_setup( &pidee_feature_led_red );
    pidee_feature_setup( &pidee_feature_led_green );
    pidee_feature_setup( &pidee_feature_led_yellow );

};

// Button
// ======
bool Pidee::getButton () {
    return pidee_feature_read( &pidee_feature_button );
}

// Dip
// ===
int Pidee::getDip() {
    int dip_value_1 = pidee_feature_read( &pidee_feature_dip_1 );
    int dip_value_2 = pidee_feature_read( &pidee_feature_dip_2 );
    int dip_value_3 = pidee_feature_read( &pidee_feature_dip_3 );
    int dip_value_4 = pidee_feature_read( &pidee_feature_dip_4 );
    int dip_value_5 = pidee_feature_read( &pidee_feature_dip_5 );
    int dip_value_6 = pidee_feature_read( &pidee_feature_dip_6 );
    int dip_value_7 = pidee_feature_read( &pidee_feature_dip_7 );
    int dip_value_8 = pidee_feature_read( &pidee_feature_dip_8 );

    uint8_t value = 0;
    value = dip_value_1 | 
            (dip_value_2<<1) | 
            (dip_value_3<<2) | 
            (dip_value_4<<3) | 
            (dip_value_5<<4) | 
            (dip_value_6<<5) | 
            (dip_value_7<<6) | 
            (dip_value_8<<7);

    return value;
}

bool Pidee::getDip( int index ) {
    if ( index < 0 || index > 7 ) {
        std::cout << "Error:: index out of bounds for Pidee::getDip" << std::endl;
        throw std::invalid_argument( "index out of bounds for Pidee::getDip" );
    }
    return pidee_feature_read( dipsFeaturesPtrs[ index ] );
}

// Led
// ===
void Pidee::setLedYellow( bool isOn ) {
    pidee_feature_write( &pidee_feature_led_yellow, isOn ? 1 : 0 );
}

void Pidee::setLedRed( bool isOn ) {
    pidee_feature_write( &pidee_feature_led_red, isOn ? 1 : 0 );
}

void Pidee::setLedGreen( bool isOn ) {
    pidee_feature_write( &pidee_feature_led_green, isOn ? 1 : 0 );
}

// Events
// ======

#ifdef PIDEE_EVENTS

// Notifications
// =============
void Pidee::notify() {
    std::vector<pidee_feature> lastestEventLog;
    pthread_mutex_lock( &interupt_lock );
    lastestEventLog = eventLog;
    eventLog.clear();
    pthread_mutex_unlock( &interupt_lock );

    // Trigger subscribers
    for ( auto feature : lastestEventLog ) {
        if ( feature.feature_type == PIDEE_FEATURE_BUTTON ) {
            for ( auto fn : buttonSubscriberFns ) {
                fn();
            }
        }
        else if ( feature.feature_type == PIDEE_FEATURE_DIP ) {
            for ( auto fn : dipSubscriberFns ) {
                fn( feature.name );
            }
        }
    }
}

void Pidee::onButton( std::function<void(void)> func ) {
    if ( !interuptsInitalised ) {
        initInterupts();
    }
    buttonSubscriberFns.push_back( func );
}

void Pidee::offButton( std::function<void(void)> func ) {
    std::cout << "TO DO:: offButton " << std::endl;
}

void Pidee::onDip( std::function<void(std::string)> func ) {
    if ( !interuptsInitalised ) {
        initInterupts();
    }
    dipSubscriberFns.push_back( func );
}

void Pidee::offDip( std::function<void(std::string)> func ) {
    std::cout << "TO DO:: offDip " << std::endl;
}

#endif

