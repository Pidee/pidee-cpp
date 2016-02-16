#pragma once

// Pidee
// =======
// C++ Library for the Pidee breakout board

#if __cplusplus > 199711L
#define PIDEE_EVENTS
#include <functional>
#endif

#define PIDEE_CPP_VERSION "0.1.0"

namespace Pidee {
    // Setup
    // =====
    void setup();

    // Button
    // ======
    bool getButton();

    // Dip
    // ===
    int getDip();
    bool getDip( int index );

    // Led
    // ===
    void setLedYellow( bool isOn );
    void setLedRed( bool isOn );
    void setLedGreen( bool isOn );

    // Events
    // ======
    #ifdef PIDEE_EVENTS 
    // Notifications
    void notify();
    void onButton( std::function<void(void)> func );
    void offButton( std::function<void(void)> func );
    void onDip( std::function<void(string)> func );
    void offDip( std::function<void(string)> func );
    #endif

};
