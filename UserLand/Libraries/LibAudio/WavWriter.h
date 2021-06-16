/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

// includes
#include <AK/StringView.h>
#include <LibCore/File.h>


namespace Audio {

class WavWriter {
public:
    WavWriter(const StringView& path, int sample_rate = 44100, int num_channels = 2, int bits_per_sample = 16);
    WavWriter(int sample_rate = 44100, int num_channels = 2, int bits_per_sample = 16);
    ~WavWriter();

    bool has_error() const { return !m_error_string.is_null(); }
    const char* error_string() const { return m_error_string.characters(); }

    void write_samples(const u8* samples, size_t size);
    void finalize(); // You can finalize manually or let the destructor do it.

    u32 sample_rate() const { return m_sample_rate; }
    u16 num_channels() const { return m_num_channels; }
    u16 bits_per_sample() const { return m_bits_per_sample; }
    RefPtr<Core::File> file() const { return m_file; }

    void set_file(const StringView& path);
    void set_num_channels(int num_channels) { m_num_channels = num_channels; }
    void set_sample_rate(int sample_rate) { m_sample_rate = sample_rate; }
    void set_bits_per_sample(int bits_per_sample) { m_bits_per_sample = bits_per_sample; }

    void clear_error() { m_error_string = String(); }
};
}