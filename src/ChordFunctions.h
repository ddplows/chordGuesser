/*
 * ChordFunctions.h
 *
 *  Created on: Jan 16, 2017
 *      Author: dave
 */

#ifndef CHORDFUNCTIONS_H_
#define CHORDFUNCTIONS_H_

#include <map>
#include <vector>
#include <string>
#include <cstdint>

static std::map<std::string, std::vector<int8_t>> chordCatalog = {
		{"E", std::vector<int8_t> { 0, 2, 2, 1, 0, 0 }},
		{"A", std::vector<int8_t> { -1, 0, 2, 2, 2, 0 }},
		{"D", std::vector<int8_t> { -1, -1, 0, 2, 3, 2 }},
		{"G", std::vector<int8_t> { 3, 2, 0, 0, 0, 3 }},
		{"C", std::vector<int8_t> { -1, 3, 2, 0, 1, 0 }},
		{"E minor", std::vector<int8_t> { 0, 2, 2, 0, 0, 0 }},
		{"A minor", std::vector<int8_t> { 0, 2, 2, 1, 0, 0 }},
		{"D7", std::vector<int8_t> { -1, -1, 0, 2, 1, 2 }},
		{"A7", std::vector<int8_t> { -1, 0, 2, 0, 2, 0 }},
		{"F", std::vector<int8_t> { -1, -1, 3, 2, 1, 1 }}
};

std::string chooseChord(std::vector<int8_t> chordInfo);
std::vector<int8_t> chordToMidi(std::vector<int8_t> fretArr);

#endif /* CHORDFUNCTIONS_H_ */
