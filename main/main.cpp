#include <iostream>
#include "strings-n-scales.h"

int main() {

    std::string instrument_strings = "E, B, G#, E, B";
    std::string notes_of_interest = "D, F, A";

    InstrumentTranscriber transc;

    transc.SetInstrumentTuning(instrument_strings);
    transc.SetNotesOfInterest(notes_of_interest);
    transc.PrintInstrumentNeck();

    return 0;
}