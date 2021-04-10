//
// Created by Gustavo Batistela on 4/10/21.
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include "strings-n-scales.h"

void InstrumentTranscriber::SetInstrumentTuning(const std::string &string_list) {
    std::stringstream ss(string_list);
    std::string substr;
    while (ss.good()) {
        getline(ss, substr, ' ');

        std::istringstream iss(substr);
        std::string note;

        while (getline(iss, note, ',')) {
            tuning.push_back(note);
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

void InstrumentTranscriber::PrintInstrumentNeck() {

    std::stringstream ss;
    ss << "Instrument tuning:";
    for (int string_id = 0; string_id < tuning.size(); string_id++) {
        ss << ' ' << tuning[string_id];
        if (string_id == tuning.size() - 1) {
            ss << ".\n";
        } else {
            ss << ',';
        }
    }
    ss << "Notes of interest:";
    auto itr = notes_of_interest.begin();
    int n = 0;
    while (itr != notes_of_interest.end()) {
        ss << ' ' << (*itr);
        if (n == notes_of_interest.size() - 1) {
            ss << ".\n\n";
        } else {
            ss << ',';
        }
        //Increment the iterator
        itr++;
        n++;
    }
    std::cout << ss.str();
    for (int string_id = 0; string_id < tuning.size(); string_id++) PrintInstrumentString(string_id);

    std::cout << "\nCaption:\n";
    int color = -1;
    for (const auto& note : notes_of_interest) {
        std::cout << "- " << note << ": ";
        color++;
        switch (color) {
            case 0:
                std::cout << red_mark();
                break;
            case 1:
                std::cout << blue_mark();
                break;
            case 2:
                std::cout << green_mark();
                break;
            case 3:
                std::cout << yellow_mark();
                break;
            case 4:
                std::cout << magenta_mark();
                break;
            case 5:
                std::cout << cyan_mark();
                break;
            case 6:
                std::cout << white_mark();
                break;
            default:
                exit(0);
        }
        std::cout << '\n';
    }

}

void InstrumentTranscriber::PrintInstrumentString(const int string_id) {
    std::stringstream ss;
    std::string_view string = tuning[string_id];
    ss << "\033[1m" << string << "\033[0m";
    ss << "\t|";

    std::vector<int> string_data(n_frets, -1);

    std::string open_note = StandardizeNote(tuning[string_id]);

    auto itr = std::find(notes.begin(), notes.end(), open_note);
    auto initial_pos = std::distance(notes.begin(), itr);

    int n = 0;
    for (auto note : notes_of_interest) {
        std::string note_of_interest = StandardizeNote(note);
        itr = std::find(notes.begin(), notes.end(), note_of_interest);
        auto note_pos = std::distance(notes.begin(), itr) - initial_pos - 1;
        while (note_pos < n_frets) {
            if (note_pos >= 0) {
                string_data[note_pos] = n;
            }
            note_pos += 12;
        }
        n++;
    }

    for (int fret_id = 0; fret_id < n_frets; fret_id++) {
        PrintFret(string_data[fret_id], ss);
    }
    ss << '\n';
    std::cout << ss.str();
}

void InstrumentTranscriber::PrintFret(int color, std::stringstream &ss) {
    switch (color) {
        case -1:
            ss << "---";
            break;
        case 0:
            ss << "-" << red_mark() << "-";
            break;
        case 1:
            ss << "-" << blue_mark() << "-";
            break;
        case 2:
            ss << "-" << green_mark() << "-";
            break;
        case 3:
            ss << "-" << yellow_mark() << "-";
            break;
        case 4:
            ss << "-" << magenta_mark() << "-";
            break;
        case 5:
            ss << "-" << cyan_mark() << "-";
            break;
        case 6:
            ss << "-" << white_mark() << "-";
            break;
        default:
            exit(0);
    }
    ss << "|";
}

std::string InstrumentTranscriber::StandardizeNote(std::string &note) {
    if (note == "Cb") return "B";
    if (note == "Db") return "C#";
    if (note == "Eb") return "D#";
    if (note == "Fb") return "E";
    if (note == "Gb") return "F#";
    if (note == "Ab") return "G#";
    if (note == "Bb") return "A#";
    if (note == "B#") return "C";
    if (note == "E#") return "F";
    return note;
}