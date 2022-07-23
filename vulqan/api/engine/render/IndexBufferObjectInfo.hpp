////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/meta/Meta.hpp>
#include "BufferObjectInfo.hpp"
#include <engine/preamble.hpp>

namespace yq {
    namespace engine {
        class IndexBufferObjectInfo : public BufferObjectInfo {
        public:
            class Writer;
            
            IndexType       index_type() const { return m_type; }
            void            set_index_type(IndexType);
            
        protected:
            IndexBufferObjectInfo(std::string_view, Pipeline*, const std::source_location&);
            
            IndexType       m_type = IndexType::none;
        };
    }
}
