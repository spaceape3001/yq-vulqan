////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/viz/BufferObject.hpp>

namespace yq::tachyon {
    BufferObject::BufferObject(BufferUsageFlags buf, Memory&& mem) : memory(std::move(mem)), usage(buf)
    {
    }
    
    BufferObject::~BufferObject()
    {
    }
    
}
