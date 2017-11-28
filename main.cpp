#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cassert>
#include <cerrno>
#include "Rectangle.h"
#include <cstring>
#include "global.h"
#include "frame.h"

using namespace std;

const double frames_per_second = 50; 
const int duration_in_seconds = 5;

Frame frame(720, 480);


int main(int argc, char * argv[]) {
	// Construct the ffmpeg command to run.
	const char * cmd = 
		"ffmpeg              "
		"-y                  "
		"-hide_banner        "
		"-f rawvideo         " // input to be raw video data
		"-pixel_format rgb24 "
		"-video_size 720x480 "
		"-r 60               " // frames per second
		"-i -                " // read data from the standard input stream
		"-pix_fmt yuv420p    " // to render with Quicktime
		"-vcodec mpeg4       "
		"-an                 " // no audio
		"-q:v 5              " // quality level; 1 <= q <= 32
		"output.mp4          ";

	// Run the ffmpeg command and get pipe to write into its standard input stream.
#ifdef _WIN32
	FILE * pipe = _popen(cmd, "wb");
#else
	FILE * pipe = popen(cmd, "w");
#endif
	if (pipe == 0) {
		cout << "error: " << strerror(errno) << endl;
		return 1;
	}

	// Write video frames into the pipe.
	int num_frames = duration_in_seconds * frames_per_second;
	Rectangle rect(120, 30, 0, 200, 100, 20, 20 );
	rect.speed(40, 40);
	for (int i = 0; i < num_frames; ++i) {
		double time_in_seconds = i / frames_per_second;
		frame.clear();
		rect.draw(time_in_seconds);
		frame.writeFrame(pipe);
	}

	fflush(pipe);
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif

	cout << "num_frames: " << num_frames << endl;
	cout << "Done." << endl;
	
	return 0;
}
