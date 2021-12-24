#include <iostream>
#include "strings-n-scales.h"
#include <docopt.h>

static const char USAGE[] =
        R"(strings-n-scales.

    Usage: strings-n-scales
      strings-n-scales notes <n> strings <s>
      strings-n-scales (-h | --help)
      strings-n-scales --version

    Options:
      -h --help     Show this screen.
      --version     Show version.
)";

int main(int argc, const char** argv)
{
    try {
        std::map<std::string, docopt::value> args
                = docopt::docopt(USAGE,
                                 {argv + 1, argv + argc},
                                 true, // show help if requested
                                 "strings-n-scales 0.1"); // version string

        if (!args.find("notes")->second.asBool()) throw std::invalid_argument("Empty 'notes' parameter.");
        if (!args.find("strings")->second.asBool()) throw std::invalid_argument("Empty 'strings' parameter.");
        std::string instrument_strings = args.find("<s>")->second.asString();
        std::string notes_of_interest = args.find("<n>")->second.asString();

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