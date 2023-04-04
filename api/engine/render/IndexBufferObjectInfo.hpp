////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <meta/Meta.hpp>
#include "BufferObjectInfo.hpp"
#include <engine/preamble.hpp>
#include <tachyon/enum/IndexType.hpp>

namespace yq {
    namespace engine {
        class IndexBufferObjectInfo : public BufferObjectInfo {
        public:
            class Writer;
            
            tachyon::IndexType       index_type() const { return m_type; }
            void            set_index_type(tachyon::IndexType);
            
        protected:
            IndexBufferObjectInfo(std::string_view, Pipeline*, const std::source_location&);
            
            tachyon::IndexType       m_type = tachyon::IndexType::none;
        };
    }
}
