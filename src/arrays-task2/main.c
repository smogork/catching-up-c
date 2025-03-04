#include <stdlib.h>
#include <math.h>

#include "unity.h"
#include "waveforms.h"
#include "wav_writer.h"


#define C4_LENGTH (int)round((double)SAMPLE_RATE / 261.626)
#define E4_LENGTH (int)round((double)SAMPLE_RATE / 329.628)
#define G4_LENGTH (int)round((double)SAMPLE_RATE / 391.995)
#define A4_LENGTH (int)round((double)SAMPLE_RATE / 440.0)

void setUp(void) {
   
}

void tearDown(void) {
    // clean stuff up here
}


void write_wave_file(const char* filename, int16_t const * waveform, int size) {
    int ret;
    FILE* file_p;

    double duration = (double)size / SAMPLE_RATE; /*seconds*/
    int32_t FrameCount = size;

    PCM16_stereo_t* buffer_p = NULL;

    size_t written;

    /*Open the wav file*/
    fopen_s(&file_p, filename, "wb");
    if (NULL == file_p)
    {
        perror("fopen failed in main");
        goto error0;
    }

    /*Allocate the data buffer*/
    buffer_p = allocate_PCM16_stereo_buffer(FrameCount);
    if (NULL == buffer_p)
    {
        perror("fopen failed in main");
        ret = -1;
        goto error1;
    }

    for (int i = 0; i < size; ++i)
    {
        buffer_p[i].left = waveform[i];
        buffer_p[i].right = waveform[i];
    }

    ret = write_PCM16_stereo_header(file_p,
        SAMPLE_RATE,
        FrameCount);
    if (ret < 0)
    {
        perror("write_PCM16_stereo_header failed in main");
        goto error2;
    }

    /*Write the data out to file*/
    written = write_PCM16wav_data(file_p,
        FrameCount,
        buffer_p);
    if (written < FrameCount)
    {
        perror("write_PCM16wav_data failed in main");
        goto error2;
    }

    /*Free and close everything*/
error2:
    free(buffer_p);
error1:
    fclose(file_p);
error0:
    return;
}


void test_sin_creation() {

}

void test_silence_creation(void) {

}

void test_cos_creation() {

}


void test_phase_shift_silence(void) {

}

void test_c_chord(void) {
    // C chord is C4, E4 and G4 waves combined together.

    
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sin_creation);
    RUN_TEST(test_cos_creation);
    RUN_TEST(test_silence_creation);
    RUN_TEST(test_phase_shift_silence);
    RUN_TEST(test_c_chord);
    return UNITY_END();
}