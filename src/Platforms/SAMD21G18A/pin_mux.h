/*
    File: pin_mux.h

        - Configure SAMD21 SERCOMs, to give requested SPI pinout
*/

#ifndef __SAMD21_PIN_MUX_H__
#define __SAMD21_PIN_MUX_H__

#ifdef __SAMD21G18A__

#include <SPI.h>
#include <wiring_private.h>

class PinMux {

    public:
        uint8_t setSPIPins(uint8_t sdi, uint8_t clk);
        uint8_t setSPIPins(uint8_t sdi, uint8_t clk, uint8_t miso);     // If useSD() has been called

    private:
        // A call for help
        void SOS();

        // A possible valid mux
        struct Mux {
            uint8_t pin;
            SERCOM* sercom;
            uint8_t pad;
            EPioType type;
        };
        
        // Array of all relevant mux options, for all relevant pins
        const Mux valid_muxs[15] = {
            (Mux) {2, &sercom2, 2, PIO_SERCOM},         // D2,          sercom2/pad[2]
            (Mux) {2, &sercom4, 2, PIO_SERCOM_ALT},     // D2,      alt_sercom4/pad[2]
            (Mux) {3, &sercom2, 1, PIO_SERCOM_ALT},     // D3,      alt_sercom2/pad[1]  
            (Mux) {4, &sercom2, 0, PIO_SERCOM_ALT},     // D4,      alt_sercom2/pad[0]
            (Mux) {5, &sercom2, 3, PIO_SERCOM},         // D5,          sercom2/pad[3]
            (Mux) {5, &sercom4, 3, PIO_SERCOM_ALT},     // D5,      alt_sercom4/pad[3]
            (Mux) {10, &sercom1, 2, PIO_SERCOM},        // D10,         sercom1/pad[2]
            (Mux) {11, &sercom1, 0, PIO_SERCOM},        // D11,         sercom1/pad[0]
            (Mux) {12, &sercom1, 3, PIO_SERCOM},        // D12,         sercom1/pad[3]
            (Mux) {13, &sercom1, 1, PIO_SERCOM},        // D13,         sercom1/pad[1]
            (Mux) {A1, &sercom4, 0, PIO_SERCOM_ALT},    // A1,          sercom4/pad[0]
            (Mux) {A2, &sercom4, 1, PIO_SERCOM_ALT},    // A2,          sercom4/pad[1]
            (Mux) {MISO, &sercom4, 0, PIO_SERCOM_ALT},  // ICSP MISO,   sercom4/pad[0]  - duplicate
            (Mux) {MOSI, &sercom4, 2, PIO_SERCOM_ALT},  // ICSP MOSI,   sercom4/pad[2]
            (Mux) {SCK, &sercom4, 3, PIO_SERCOM_ALT}    // ICSP SCK,    sercom4/pad[3]
        };
};

#endif  // End - Platform SAMD21G18A
#endif  // Include guard