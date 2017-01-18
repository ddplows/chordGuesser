//============================================================================
// Name        : ChordGuesser.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fluidsynth.h>
#include <unistd.h>
#include "ChordFunctions.h"


int handle_midi_event(void* data, fluid_midi_event_t* event)
{
    printf("event type: %d\n", fluid_midi_event_get_type(event));
    return 0;
}

int main() {
	fluid_settings_t* settings;
	fluid_synth_t* synth = NULL;
    fluid_midi_driver_t* midiDriver;
	fluid_audio_driver_t* adriver = NULL;
	int err = 0;
	std::vector<int8_t> fChordMidi = chordToMidi(chordCatalog["F"]);

	/* Create the settings object. This example uses the default
	 * values for the settings. */
	settings = new_fluid_settings();
	if (settings == NULL) {
		fprintf(stderr, "Failed to create the settings\n");
		err = 2;
		goto cleanup;
	}

	/* Create the synthesizer */
	synth = new_fluid_synth(settings);
	if (synth == NULL) {
		fprintf(stderr, "Failed to create the synthesizer\n");
		err = 3;
		goto cleanup;
	}

	/* Load the soundfont */
	if (fluid_synth_sfload(synth, "TimGM6mb.sf2", 1) == -1) {
		fprintf(stderr, "Failed to load the SoundFont\n");
		err = 4;
		goto cleanup;
	}
    midiDriver = new_fluid_midi_driver(settings, handle_midi_event, NULL);

	/* Create the audio driver. As soon as the audio driver is
	 * created, the synthesizer can be played. */
    fluid_settings_setstr(settings, "audio.driver", "alsa");
	adriver = new_fluid_audio_driver(settings, synth);
	if (adriver == NULL) {
		fprintf(stderr, "Failed to create the audio driver\n");
		err = 5;
		goto cleanup;
	}

	std::cout << chooseChord(std::vector<int8_t> { -1, -1, 3, 0, 1, 1 })
			<< std::endl;


	for(unsigned int i = 0; i < fChordMidi.size(); i++){
		std::cout << i << " is " << (int)fChordMidi[i] << "\n";
		if(fChordMidi[i] != -1){
			fluid_synth_noteon(synth, 0, (int)fChordMidi[i], 100);
		}
	}
	sleep(5);
	cleanup:

	        if (adriver) {
	                delete_fluid_audio_driver(adriver);
	        }
	        if (synth) {
	                delete_fluid_synth(synth);
	        }
	        if (settings) {
	                delete_fluid_settings(settings);
	        }


	return 0;
}
