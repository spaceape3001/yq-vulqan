////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/UniqueID.hpp>
#include <basic/Ref.hpp>
#include <tachyon/Memory.hpp>
#include <tachyon/enum/BufferUsage.hpp>
#include <span>

namespace yq::tachyon {
    
    /*! \brief Basic buffer (object)
    
        This is a basic data buffer
    
        \note Once released, a buffer is to remain read-only.  
            Any/all changes should request a NEW unique ID.
    */
    class BufferObject : public UniqueID, public RefCount {
    public:
    
        const Memory            memory;
        const BufferUsageFlags  usage;
        
        BufferObject(BufferUsageFlags, Memory&&);

    private:
        ~BufferObject();

        //  No copying/moving
        BufferObject(const BufferObject&) = delete;
        BufferObject(BufferObject&&) = delete;
        BufferObject& operator=(BufferObject&&) = delete;
        BufferObject& operator=(const BufferObject&) = delete;
    };

}
