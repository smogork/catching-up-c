#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

/*
The header of a wav file Based on:
https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
*/
typedef struct wavfile_header_s
{
    char    ChunkID[4];     /*  4   */
    int32_t ChunkSize;      /*  4   */
    char    Format[4];      /*  4   */

    char    Subchunk1ID[4]; /*  4   */
    int32_t Subchunk1Size;  /*  4   */
    int16_t AudioFormat;    /*  2   */
    int16_t NumChannels;    /*  2   */
    int32_t SampleRate;     /*  4   */
    int32_t ByteRate;       /*  4   */
    int16_t BlockAlign;     /*  2   */
    int16_t BitsPerSample;  /*  2   */

    char    Subchunk2ID[4];
    int32_t Subchunk2Size;
} wavfile_header_t;

/*Standard values for CD-quality audio*/
#define SUBCHUNK1SIZE   (16)
#define AUDIO_FORMAT    (1) /*For PCM*/
#define NUM_CHANNELS    (2)
#define SAMPLE_RATE     (44100)

#define BITS_PER_SAMPLE (16)

#define BYTE_RATE       (SAMPLE_RATE * NUM_CHANNELS * BITS_PER_SAMPLE / 8)
#define BLOCK_ALIGN     (NUM_CHANNELS * BITS_PER_SAMPLE / 8)


/*Data structure to hold a single frame with two channels*/
typedef struct PCM16_stereo_s
{
    int16_t left;
    int16_t right;
} PCM16_stereo_t;

int write_PCM16_stereo_header(FILE* file_p,
    int32_t SampleRate,
    int32_t FrameCount);

PCM16_stereo_t* allocate_PCM16_stereo_buffer(int32_t FrameCount);

/*Return the number of audio frames sucessfully written*/
size_t  write_PCM16wav_data(FILE* file_p,
    int32_t         FrameCount,
    PCM16_stereo_t* buffer_p);
