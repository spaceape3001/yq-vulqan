////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <log4cpp/CategoryStream.hh>
#include <yq-toolbox/basic/Logging.hpp>
#include <yq-toolbox/text/format.hpp>
#include <yq-toolbox/trait/is_pointer.hpp>

namespace log4cpp {
    class CategoryStream;
}

namespace yq::tachyon {

    class ViPipeline;
    class ViPipelineLayout;
    class ViRendered;

    template <typename T>
    constexpr std::string_view hex(T v) 
    { 
        if constexpr ( std::is_pointer_v<T> ){
            return fmt_hex((uint64_t) v);
        } else {
            return fmt_hex(v);
        }
    }
}


