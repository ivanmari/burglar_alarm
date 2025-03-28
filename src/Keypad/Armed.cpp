#include "Armed.h"

#include "Disarmed.h"

#include "io_defs.h"

#include   <Keypad.h>

const long DELAY_BEFORE_ARMED = 20 * SECONDS;

const byte ROWS = 4; // Constants for row sizes
const byte COLS = 3; // Constants for   column sizes


Armed::Armed(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi), 
m_sw(VIBRATION_SENSOR_1, HIGH, asi),
m_disarm_sw(DISARM, HIGH, asi),
m_delay(asi->getPlatform(), DELAY_BEFORE_ARMED),
m_input_timeout(asi->getPlatform(), DELAY_BEFORE_ARMED)
{}

Armed*
Armed::Instance(Fsm* fsm, ASi* asi)
{
    static Armed Armed(fsm, asi);
    return &Armed;
}

void
Armed::execute()
{
  char hexaKeys[ROWS][COLS] = {  // Array to represent keys on   keypad
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};

#define   PWD_LEN 5     // Length of password + 1 for null character
char Data[PWD_LEN] = {0};      // Character to hold password input
char Master[PWD_LEN] = "1984";    // Password
byte rowPins[ROWS] = {8, 5, 6, 3};  // Connections to   Arduino
byte colPins[COLS] = { 7, 4, 2};

    Serial.print("Armed\n");
    delay(1000);
    m_asi->getPlatform()->setPin(ARMED, false);
    Keypad customKeypad = Keypad(makeKeymap(hexaKeys),   rowPins, colPins, ROWS, COLS);

    m_input_timeout.start();
    int data_count = 0;
  
    while(!m_input_timeout.expired())
    {
        char customKey = customKeypad.getKey();
        if (customKey){
           m_input_timeout.reset();
           m_input_timeout.start();
            Data[data_count++] = customKey;
            //beep();
            delay(300);
            Serial.print(customKey);
            delay(300);
        
  
            if(PWD_LEN - 1 == data_count) {
                if (!strcmp(Data, Master)) {
                    m_input_timeout.reset();
                    m_fsm->setState(Disarmed::Instance(m_fsm, m_asi));
                    return;
                }
                else {
                    Serial.print("Wrong Pwd\n");
                    for (auto i = 0; i < PWD_LEN; i++) {
                        Data[i] = 0;
                    }
    
                    m_input_timeout.reset();
                    m_fsm->setState(Armed::Instance(m_fsm, m_asi));
                    return;
                }
            }
        }
    }

    Serial.print("Timeout Pwd\n");
    m_input_timeout.reset();
    m_fsm->setState(Armed::Instance(m_fsm, m_asi));
    return;
}

void
Armed::reset()
{
}
