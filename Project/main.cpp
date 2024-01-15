#include <iostream>
#include <Windows.h>

int main() {
    // Path to the sound file (replace with your file path)
    const char* soundFilePath = "Chaal-Chal-Tu-Apni-Main-Tujhe-Pahchan-Lunga(PaglaSongs).wav";

    // Play the sound file
    if (PlaySoundA(soundFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
        std::cout << "Sound is playing..." << std::endl;

        // You can add additional logic here if needed

        // Sleep to allow the sound to play for a while
        Sleep(5000); // Sleep for 5000 milliseconds (5 seconds)
    } else {
        std::cerr << "Failed to play the sound." << std::endl;
    }

    return 0;
}
