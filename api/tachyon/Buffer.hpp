////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/UniqueID.hpp>
#include <basic/Ref.hpp>
#include <tachyon/enum/BufferUsage.hpp>
#include <span>

namespace yq {
    namespace tachyon {
        
        /*! \brief Basic buffer (object)
        
            This is a basic data buffer
        
            \note Once released, a buffer is to remain read-only.  
                Any/all changes should request a NEW unique ID.
        */
        class Buffer : public UniqueID, public RefCount {
        public:
        
            const void*         data() const { return m_pointer; }
            size_t              bytes() const { return m_size; }
            BufferUsageFlags    usage() const { return m_usage; }
            
        protected:
            Buffer(BufferUsageFlags);
            virtual ~Buffer();
        
            const void*             m_pointer;
            size_t                  m_size;
            BufferUsageFlags        m_usage;

        private:
            Buffer(const Buffer&) = delete;
            Buffer(Buffer&&) = delete;
            Buffer& operator=(Buffer&&) = delete;
            Buffer& operator=(const Buffer&) = delete;
        };

    }
}
