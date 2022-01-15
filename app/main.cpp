#include <iostream>
#include "strings-n-scales.h"
#include <docopt.h>

int main(int argc, const char **argv) {
    try {
        const auto usage = R"(
            strings-n-scales

            Usage:
              strings-n-scales notes <n> strings <s>
              strings-n-scales (-h | --help)
              strings-n-scales --version

            Options:
              -h --help     Show this screen.
              --version     Show version.
        )";

        const auto args = docopt::docopt(usage, {argv + 1, argv + argc}, true, "strings-n-scales 0.1");

        if (!args.find("notes")->second.asBool()) throw std::invalid_argument("Empty 'notes' parameter.");
        if (!args.find("strings")->second.asBool()) throw std::invalid_argument("Empty 'strings' parameter.");

        const auto instrument_strings = args.find("<s>")->second.asString();
        const auto notes_of_interest = args.find("<n>")->second.asString();

        InstrumentTranscriber transc;

        transc.SetInstrumentTuning(instrument_strings);
        transc.SetNotesOfInterest(notes_of_interest);
        transc.PrintInstrumentNeck();
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}