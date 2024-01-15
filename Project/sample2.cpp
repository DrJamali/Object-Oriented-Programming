#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

void CALLBACK WaveOutProc(HWAVEOUT hwo, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam1, DWORD_PTR dwParam2)
{
    // Callback function to handle playback events
    if (uMsg == WOM_OPEN)
    {
        std::cout << "Waveform-audio output device is open." << std::endl;
    }
    else if (uMsg == WOM_CLOSE)
    {
        std::cout << "Waveform-audio output device is closed." << std::endl;
    }
    else if (uMsg == WOM_DONE)
    {
        std::cout << "Playback complete." << std::endl;
    }
}

int main()
{
    // Specify the path to your WAV file
    const char *wavFilePath = "path/to/your/song.wav";

    // Set up WAVEFORMATEX structure for PCM 44.1 kHz, 16-bit, stereo
    WAVEFORMATEX wfx;
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = 2;
    wfx.nSamplesPerSec = 44100;
    wfx.nAvgBytesPerSec = 44100 * 2 * 2; // 44.1 kHz, 16-bit, stereo
    wfx.nBlockAlign = 2 * 2;
    wfx.wBitsPerSample = 16;
    wfx.cbSize = 0;

    // Open the waveform-audio output device
    HWAVEOUT hWaveOut;
    MMRESULT result = waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, (DWORD_PTR)WaveOutProc, 0, CALLBACK_FUNCTION);

    if (result == MMSYSERR_NOERROR)
    {
        std::cout << "Waveform-audio output device opened successfully." << std::endl;

        // Prepare and write audio data
        // (You need to implement this part based on your WAV file and audio data)

        // Sleep to allow playback to complete (you can implement proper synchronization)
        Sleep(50000); // Sleep for 5000 milliseconds (5 seconds)

        // Close the waveform-audio output device
        waveOutClose(hWaveOut);
    }
    else
    {
        std::cerr << "Failed to open waveform-audio output device;<<" << std::endl;
    }
}