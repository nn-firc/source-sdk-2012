#include "soundsystem/audio_mix.h"

CAudioProcessor::CAudioProcessor( const char *pDebugName, int nChannelCount )
{
}
void CAudioProcessor::SetDebugName( const char *pName )
{
}
void CAudioProcessor::Process( CAudioMixBuffer *pInput, CAudioMixBuffer *pOutput, int nChannelCount, dspglobalvars_t *pGlobals )
{
}
void CAudioProcessor::ProcessSingleChannel( const CAudioMixBuffer &input, CAudioMixBuffer *pOutput, int nChannelIndex )
{
}
bool CAudioProcessor::SetControlParameter( CUtlStringToken name, float flValue )
{
	return false;
}
float CAudioProcessor::GetControlParameter( CUtlStringToken name, float flDefaultValue )
{
	return 0.f;
}
bool CAudioProcessor::SetNameParameter( CUtlStringToken name, uint32 nNameValue )
{
	return false;
}
uint32 CAudioProcessor::GetNameParameter( CUtlStringToken name, uint32 nDefaultValue )
{
	return NULL;
}

bool CAudioProcessor::ShouldProcess()
{
	return false;
}
float CAudioProcessor::GetPrevMix( float flMix )
{
	return 0.f;
}
void CAudioProcessor::ApplyMonoProcessor( CAudioMixBuffer *pInput, CAudioMixBuffer *pOutput, int nOutputChannelCount, float flMix )
{
}
void CAudioProcessor::ApplyStereoProcessor( CAudioMixBuffer *pInput, CAudioMixBuffer *pOutput, int nOutputChannelCount, float flMix )
{
}
void CAudioProcessor::ApplyNChannelProcessor( CAudioMixBuffer *pInput, CAudioMixBuffer *pOutput, int nChannelCount, float flMix )
{
}
