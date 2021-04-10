//
// Created by Gustavo Batistela on 4/10/21.
//

#include <sstream>
#include <iostream>
#include "strings-n-scales.h"

void InstrumentTranscriber::SetInstrumentStrings(const std::string &string_list) {
    std::stringstream ss(string_list);
    std::string substr;
    while (ss.good()) {
        getline(ss, substr, ' ');

        std::istringstream iss(substr);
        std::string note;

        while (getline(iss, note, ',')) {
            strings.push_back(note);
        }
    }
}

void InstrumentTranscriber::SetNotesOfInterest(const std::string &notes_list) {

    std::stringstream ss(notes_list);
    std::string substr;
    while (ss.good()) {
        getline(ss, substr, ' ');

        std::istringstream iss(substr);
        std::string note;

        while (getline(iss, note, ',')) {
            notes_of_interest.insert(note);
        }
    }
}
