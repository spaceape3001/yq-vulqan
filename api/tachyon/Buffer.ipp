////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Buffer.hpp>
#include <tachyon/BufferArray.hpp>
#include <tachyon/BufferCopy.hpp>
#include <tachyon/BufferSpan.hpp>

namespace yq {
    namespace tachyon {
        Buffer::Buffer(BufferUsageFlags buf) : m_usage(buf)
        {
        }
        
        Buffer::~Buffer()
        {
        }
    }
}
