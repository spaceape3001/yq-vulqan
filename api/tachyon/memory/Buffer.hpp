////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/UniqueID.hpp>
#include <yq/core/Memory.hpp>
#include <yq/core/Ref.hpp>
#include <tachyon/memory/BufferUsage.hpp>
#include <span>

namespace yq::tachyon {
    
    /*! \brief Basic buffer (object)
    
        This is a basic data buffer
    
        \note Once released, a buffer is to remain read-only.  
            Any/all changes should request a NEW unique ID.
    */
    class Buffer : public UniqueID, public RefCount {
    public:
    
        //! Buffer memeory
        const Memory            memory;
        
        //! Buffer usage flags
        const BufferUsageFlags  usage;
        
        //! Constructor for a buffer
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
