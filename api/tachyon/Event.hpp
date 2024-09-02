////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/basic/Object.hpp>
#include <tachyon/preamble.hpp>

namespace yq::tachyon {

    class EventInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        EventInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class Event : public Object {
    public:
    };

}
