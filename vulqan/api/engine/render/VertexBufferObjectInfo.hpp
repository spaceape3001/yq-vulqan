////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/meta/Meta.hpp>
#include "BufferObjectInfo.hpp"

namespace yq {
    namespace engine {
        class VertexBufferObjectInfo : public BufferObjectInfo {
        public:
            class Writer;
            
            uint32_t    binding() const { return m_binding; }
            
        protected:
            VertexBufferObjectInfo(std::string_view, Pipeline*, const std::source_location&);
            uint32_t    m_binding;
        };
    }
}
