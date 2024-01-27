/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
    #define AUDIO_HPP_
    #include "portaudio.h"
    #include <iostream>
    #include <opus.h>
    #include <iostream>

namespace Client
{


#define SAMPLE_RATE	(24000) 
#define FRAMES_PER_BUFFER (480) 
#define PA_SAMPLE_TYPE	paFloat32 



class Encoding
{
	public:
		Encoding()
        {
	        int error;

	        _frames_per_buf = FRAMES_PER_BUFFER;
	        _encoder = opus_encoder_create(SAMPLE_RATE, 2, OPUS_APPLICATION_VOIP, &error);
	        _decoder = opus_decoder_create(SAMPLE_RATE, 2, &error);
	        opus_encoder_ctl(_encoder, OPUS_GET_BANDWIDTH(&_frames_per_buf));
        }

		void encodeAudio(const float* input, int* _len, unsigned char** audio_data)
        {
        	*audio_data = (unsigned char*)malloc(sizeof(char) * _frames_per_buf);
        	// Verify malloc

        	*_len = opus_encode_float(_encoder, input, FRAMES_PER_BUFFER, *audio_data, _frames_per_buf);
        }

		void decodeAudio(unsigned char* readaudiodata, float* pcm, int readlen)
        {
	        if (opus_decode_float(_decoder, readaudiodata, readlen, pcm, FRAMES_PER_BUFFER, 0) < 0) {
	        	std::cout << "Error : Decoding" << std::endl;
	        }
        }
        
		~Encoding()
        {
            opus_encoder_destroy(_encoder);
            opus_decoder_destroy(_decoder);
        }
	private:
		opus_int32	_frames_per_buf;
		OpusEncoder* _encoder;
		OpusDecoder* _decoder;
}
    
class Audio {
    public:
        Audio()
        {
            _instream = nullptr;
            _outstream = nullptr;

            // launch Audio
            _error = Pa_Initialize();
            if (_error != paNoError) {
                std::cerr << "Error : Initialize Audio" << std::endl;
                exit(84);
            }



            // init Input
            _inparam.device = Pa_GetDefaultInputDevice();
            _inparam.channelCount = 2;
            _inparam.sampleFormat = paFloat32;
            _inparam.suggestedLatency = Pa_GetDeviceInfo(_inparam.device)->defaultLowInputLatency;
            _inparam.hostApiSpecificStreamInfo = NULL;


            // Init Output
            _outparam.device = Pa_GetDefaultOutputDevice();
            _outparam.channelCount = 2;
            _outparam.sampleFormat = paFloat32;
            _outparam.suggestedLatency = Pa_GetDeviceInfo(_outparam.device)->defaultLowOutputLatency;
            _outparam.hostApiSpecificStreamInfo = NULL;


            // Init Stream
            _error = Pa_OpenStream(&_instream, &_inparam, NULL, 24000, 480, paClipOff, recordCallback, this);
            if (_error != paNoError) {
                std::cerr << "Error : Opening Audio Stream" << std::endl;
                exit(84);
            }
            _error = Pa_OpenStream(&_outstream, NULL, &_outparam, 24000, 480, paClipOff, playCallback, this);
            if (_error != paNoError)
            {
                std::cerr << "Error : Opening Audio Stream" << std::endl;
                exit(84);
            }

            // start Stream
            _error = Pa_StartStream(_instream);
            if (_error != paNoError)
            {
                std::cerr << "Error : Start Audio Stream" << std::endl;
                exit(84);
            }
            _error = Pa_StartStream(_outstream);
            if (_error != paNoError)
            {
                std::cerr << "Error : Start Audio Stream" << std::endl;
                exit(84);
            }
        }

        ~Audio()
        {
            if (_instream)
                Pa_CloseStream(_instream);
            if (_outstream)
                Pa_CloseStream(_outstream);
            Pa_Terminate();
        }

            // GETTERS
        Encoding getEncoding() {
            return _opusService;
        }

        unsigned char* getAudioData() {
            return _audiodata;
        }
        int getLen() {
            return _len;
        }
        unsigned char* getReadAudioData() {
            return _readaudiodata;
        }
        int getReadLen() {
            return _readlen;
        }

        // SETTERS
        void setAudioData(unsigned char* audio_data) {
            _audiodata = audio_data;
        }

        void setLen(int len) {
            _len = len;
        }
        void setReadAudioData(unsigned char* audio_data) {
            _readaudiodata = audio_data;
        }

        void setReadLen(int len) {
            _readlen = len;
        }

    protected:
    private:
        PaStream* _instream;
        PaStream* _outstream;
        PaError _error;
        PaStreamParameters _inparam;
        PaStreamParameters _outparam;
        int _len = 0;
        int _readlen = 0;
        unsigned char* _audiodata;
        unsigned char* _readaudiodata;
};

} // namespace Client
#endif /* !AUDIO_HPP_ */




int recordCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    Client::Audio* _record = (Client::Audio*)userData;
    const float* input = (const float*)inputBuffer;
    unsigned char* audio_data = NULL;
    int _len = 0;

    // NO WARNING
    (void)timeInfo;
    (void)statusFlags;
    (void)outputBuffer;

    _record->getEncoding().encodeAudio(input, &_len, &audio_data);
    _record->setAudioData(audio_data);
    _record->setLen(_len);
    return paContinue;
}

int playCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    Client::Audio* _play = (Client::Audio*)userData;
    float* out = (float*)outputBuffer;

    // NO WARNING
    (void)timeInfo;
    (void)statusFlags;
    (void)inputBuffer;

    _play->getEncoding().decodeAudio(_play->getAudioData(), out, _play->getLen());
    return paContinue;
}
