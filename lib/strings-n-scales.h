//
// Created by Gustavo Batistela on 4/10/21.
//

#ifndef STRINGS_N_SCALES_H
#define STRINGS_N_SCALES_H

#include <array>
#include <string_view>
#include <vector>
#include <set>

class InstrumentTranscriber {
public:
    void SetInstrumentTuning(const std::string &string_list);

    void SetNotesOfInterest(const std::string &notes_list);

    void PrintInstrumentNeck();

private:

    static constexpr int n_frets = 20;

    std::vector<std::string> tuning;

    std::set<std::string> notes_of_interest;

    const std::array<std::string, 12> notes = {
        "C", "C#", "D", "D#",
        "E", "F", "F#", "G",
        "G#", "A", "A#", "B"
    };

    static inline std::string_view red_mark() {
        return "\033[31m●\033[0m";
    }

    static inline std::string_view green_mark() {
        return "\033[32m●\033[0m";
    }

    static inline std::string_view yellow_mark() {
        return "\033[33m●\033[0m";
    }

    static inline std::string_view blue_mark() {
        return "\033[34m●\033[0m";
    }

    static inline std::string_view magenta_mark() {
        return "\033[35m●\033[0m";
    }

    static inline std::string_view cyan_mark() {
        return "\033[36m●\033[0m";
    }

    static inline std::string_view white_mark() {
        return "\033[37m●\033[0m";
    }

    void PrintInstrumentString(int string_id);

    void PrintFret(int color, std::stringstream& ss);

    static std::string StandardizeNote(std::string& note);

};

#endif //STRINGS_N_SCALES_H
