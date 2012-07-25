#define BOOST_THREAD_USE_LIB

#include <openmedia/DTVideo2Mp3.h>
#include <iostream>

#ifdef _MSC_VER
#   pragma comment(lib, "dtcommonsdk-static.lib")
#   pragma comment(lib, "dtmediasdk-static.lib")

#   pragma comment(lib, "avcodec.lib")
#   pragma comment(lib, "avformat.lib")
#   pragma comment(lib, "avutil.lib")
#   pragma comment(lib, "swresample.lib")
#   pragma comment(lib, "swscale.lib")
#   pragma comment(lib, "libmp3lame.a") 

#endif

bool CallbackFun(openmedia::audio::video2mp3::State state, double progress)
{
    std::cout << state << " " << progress << "\n";
    return true;
}

#if defined(_MSC_VER) && defined(_UNICODE)
int wmain(int argc, wchar_t * argv[])
#else
int main(int argc, char* argv[])
#endif
{
    if (argc < 3)
    {
        std::cerr << "usage: video2mp3.exe [INPUT] [MP3]";
        return 1;
    }
    
    std::wstring title = L"Title";
    openmedia::audio::video2mp3::convert(argv[1], argv[2], title, &CallbackFun);
	return 0;
}

