/*Compiles with gcc -Wall -O2 -o wavwrite wavwrite.c*/

#include "wav_writer.h"



/*Return 0 on success and -1 on failure*/
int write_PCM16_stereo_header(FILE* file_p,
    int32_t SampleRate,
    int32_t FrameCount)
{
    int ret;

    wavfile_header_t wav_header;
    int32_t subchunk2_size;
    int32_t chunk_size;

    size_t write_count;

    subchunk2_size = FrameCount * NUM_CHANNELS * BITS_PER_SAMPLE / 8;
    chunk_size = 4 + (8 + SUBCHUNK1SIZE) + (8 + subchunk2_size);

    wav_header.ChunkID[0] = 'R';
    wav_header.ChunkID[1] = 'I';
    wav_header.ChunkID[2] = 'F';
    wav_header.ChunkID[3] = 'F';

    wav_header.ChunkSize = chunk_size;

    wav_header.Format[0] = 'W';
    wav_header.Format[1] = 'A';
    wav_header.Format[2] = 'V';
    wav_header.Format[3] = 'E';

    wav_header.Subchunk1ID[0] = 'f';
    wav_header.Subchunk1ID[1] = 'm';
    wav_header.Subchunk1ID[2] = 't';
    wav_header.Subchunk1ID[3] = ' ';

    wav_header.Subchunk1Size = SUBCHUNK1SIZE;
    wav_header.AudioFormat = AUDIO_FORMAT;
    wav_header.NumChannels = NUM_CHANNELS;
    wav_header.SampleRate = SampleRate;
    wav_header.ByteRate = BYTE_RATE;
    wav_header.BlockAlign = BLOCK_ALIGN;
    wav_header.BitsPerSample = BITS_PER_SAMPLE;

    wav_header.Subchunk2ID[0] = 'd';
    wav_header.Subchunk2ID[1] = 'a';
    wav_header.Subchunk2ID[2] = 't';
    wav_header.Subchunk2ID[3] = 'a';
    wav_header.Subchunk2Size = subchunk2_size;

    write_count = fwrite(&wav_header,
        sizeof(wavfile_header_t), 1,
        file_p);

    ret = (1 != write_count) ? -1 : 0;

    return ret;
}


PCM16_stereo_t* allocate_PCM16_stereo_buffer(int32_t FrameCount)
{
    return (PCM16_stereo_t*)malloc(sizeof(PCM16_stereo_t) * FrameCount);
}


/*Return the number of audio frames sucessfully written*/
size_t  write_PCM16wav_data(FILE* file_p,
    int32_t         FrameCount,
    PCM16_stereo_t* buffer_p)
{
    size_t ret;

    ret = fwrite(buffer_p,
        sizeof(PCM16_stereo_t), FrameCount,
        file_p);

    return ret;
}

/*Generate two saw-tooth signals at two frequencies and amplitudes*/
int generate_dual_sawtooth(double frequency1,
    double amplitude1,
    double frequency2,
    double amplitude2,
    int32_t SampleRate,
    int32_t FrameCount,
    PCM16_stereo_t* buffer_p)
{
    int ret = 0;
    double SampleRate_d = (double)SampleRate;
    double SamplePeriod = 1.0 / SampleRate_d;

    double Period1, Period2;
    double phase1, phase2;
    double Slope1, Slope2;

    int32_t k;

    /*Check for the violation of the Nyquist limit*/
    if ((frequency1 * 2 >= SampleRate_d) || (frequency2 * 2 >= SampleRate_d))
    {
        ret = -1;
        goto error0;
    }

    /*Compute the period*/
    Period1 = 1.0 / frequency1;
    Period2 = 1.0 / frequency2;

    /*Compute the slope*/
    Slope1 = amplitude1 / Period1;
    Slope2 = amplitude2 / Period2;

    for (k = 0, phase1 = 0.0, phase2 = 0.0;
        k < FrameCount;
        k++)
    {
        phase1 += SamplePeriod;
        phase1 = (phase1 > Period1) ? (phase1 - Period1) : phase1;

        phase2 += SamplePeriod;
        phase2 = (phase2 > Period2) ? (phase2 - Period2) : phase2;

        buffer_p[k].left = (int16_t)(phase1 * Slope1);
        buffer_p[k].right = (int16_t)(phase2 * Slope2);
    }

error0:
    return ret;
}