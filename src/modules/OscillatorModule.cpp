#include "OscillatorModule.h"
#include <cmath>

OscillatorModule::OscillatorModule(ModularSynth& synth)
	:SynthModule(synth, moduleId, 3, 2, 0), mAccumulator(0.0f), mPreviousSync(0.0f)
{
}

void OscillatorModule::cycle()
{
	float phase = getInput(2) * 0.5f;

	if (getInput(1) > 0.5f && mPreviousSync <= 0.5f)
		mAccumulator = 0;

	mPreviousSync = getInput(1);

	mAccumulator = fmod(mAccumulator + getInput(0) / mSampleRate * 1000, 1.0f);
	setOutput(0, sin((mAccumulator + phase) * (3.14157 * 2)));
	setOutput(1, fmod(mAccumulator + phase, 1.0f) * 2.0f - 1.0f);
}



const char * OscillatorModule::getInputName(int input) const
{
	static const char *names[] = {"Frequency", "Sync", "Phase"};
	return names[input];
}


const char * OscillatorModule::getOutputName(int output) const
{
	static const char *names[] = {"Sine", "Saw"};
	return names[output];
}


const char * OscillatorModule::getName() const
{
	return moduleName;
}


SynthModule * OscillatorModule::createModule(ModularSynth& synth)
{
	return new OscillatorModule(synth);
}
