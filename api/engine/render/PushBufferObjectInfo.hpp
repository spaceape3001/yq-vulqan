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
        class PushBufferObjectInfo : public BufferObjectInfo {
        public:
            class Writer;
            
            
            
        protected:
            PushBufferObjectInfo(std::string_view, Pipeline*, const std::source_location&);
        };
    }
}
