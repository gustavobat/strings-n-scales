#include <iostream>
#include "strings-n-scales.h"

int main() {

    std::string instrument_strings = "C, B, E, F#, G#";
    std::string notes_of_interest = "D, E, F, D, D";

    InstrumentTranscriber transc;

    transc.SetInstrumentStrings(instrument_strings);
    transc.SetNotesOfInterest(notes_of_interest);

    std::cout << "E  |---|-●-|---|---|---|---|---|---|---|---|---|---|\n";
    std::cout << "F# |---|---|-●-|---|---|---|---|---|---|---|---|---|\n";
    std::cout << "G  |---|---|---|-●-|---|---|---|---|---|---|---|---|\n";
    std::cout << "B  |---|---|---|---|---|---|---|---|---|---|---|---|\n";
    std::cout << "A  |---|---|---|---|---|---|---|---|---|---|---|---|\n";

    return 0;
}