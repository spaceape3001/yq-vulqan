////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/UniqueID.hpp>
#include <basic/Ref.hpp>
#include <tachyon/core/Memory.hpp>
#include <tachyon/enum/BufferUsage.hpp>
#include <span>

namespace yq::tachyon {
    
    /*! \brief Basic buffer (object)
    
        This is a basic data buffer
    
        \note Once released, a buffer is to remain read-only.  
            Any/all changes should request a NEW unique ID.
    */
    class Buffer : public UniqueID, public RefCount {
    public:
    
        const Memory            memory;
        const BufferUsageFlags  usage;
        
        Buffer(BufferUsageFlags, Memory&&);

    private:
        ~Buffer();

        //  No copying/moving
        Buffer(const Buffer&) = delete;
        Buffer(Buffer&&) = delete;
        Buffer& operator=(Buffer&&) = delete;
        Buffer& operator=(const Buffer&) = delete;
    };

}
