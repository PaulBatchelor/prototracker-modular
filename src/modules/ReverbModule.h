#pragma once

#include "../SynthModule.h"

class ReverbModule: public SynthModule
{
	struct Filter {
		const int mLength;
		int mHead;
		float *mBuffer;

		Filter(int length);
		~Filter();
	};

	struct CombFilter: public Filter {
		float cycle(float input, float gain);
		CombFilter(int length);
	};

	struct AllpassFilter: public Filter {
		float cycle(float input, float gain);
		AllpassFilter(int length);
	};

	static const int numAllpassFilters = 7;
	static const int numCombFilters = 7;

	CombFilter *mComb[numCombFilters];
	AllpassFilter *mAllpass[numAllpassFilters];

	ReverbModule(ModularSynth& synth);

public:
	virtual ~ReverbModule();

	static const int moduleId = 25;
	static const int maxInstances = -1;
	static const int maxBufferSizeMs = 2000;
	static constexpr const char *moduleName = "Reverb";

	static SynthModule * createModule(ModularSynth& synth);

	virtual void cycle();

	virtual const char * getName() const;
	virtual const char * getInputName(int input) const;
	virtual const char * getOutputName(int output) const;

	virtual void setSampleRate(int newRate);
};
