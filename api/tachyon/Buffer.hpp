////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/basic/UniqueID.hpp>
#include <yq/basic/Ref.hpp>
#include <tachyon/Memory.hpp>
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
