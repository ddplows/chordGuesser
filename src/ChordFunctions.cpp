/*
 * ChordFunctions.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: dave
 */
#include "ChordFunctions.h"

//may need something more sophisticated in future?
//will need to account for hand to hand distance modifier in future?
//most guitar chords are played on the lowest frets though
//unless barred I guess
//idk
std::string chooseChord(std::vector<int8_t> chordInfo)
{
    std::string closestChord;
    static int diff = 10000;
    for (auto const& ent1 : chordCatalog) {
        int diff2 = 0;
        // ent1.first is key
        // ent1.second is value
        for (unsigned int i = 0; i < ent1.second.size(); i++) {
            //do not compare unplayed chord notes
            if (ent1.second[i] != -1 || chordInfo[i] != 0) {
                diff2 += abs(ent1.second[i] - chordInfo[i]);
            }
        }
        if (diff2 < diff) {
            diff = diff2;
            closestChord = ent1.first;
        }
    }
    return closestChord;
}

//it may be better/faster to just save chord's midi arrays by themselves rather than using this converter function
std::vector<int8_t> chordToMidi(std::vector<int8_t> fretArr)
{
    std::vector<int8_t> retVec;
    for (unsigned int i = 0; i < fretArr.size(); i++) {
        //I'm just putting this in until we decide how to properly handle unplayed strings in chords
        //skip conversion for string
        if(fretArr[i] == -1) {
            continue;
        }
        if (i == 0) {
            retVec.push_back(fretArr[i] + 4);
        } else if (i == 1) {
            retVec.push_back(fretArr[i] + 11);
        } else {
            retVec.push_back(fretArr[i] + (i * 7 + 5));
        }
    }
    return retVec;
}


