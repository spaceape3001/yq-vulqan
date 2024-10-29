////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/InputEvent.hpp>

namespace yq::tachyon {
    class VulqanEventInfo : public InputEventInfo {
    public:
        VulqanEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class VulqanEvent : public InputEvent {
        YQ_OBJECT_INFO(VulqanEventInfo)
        YQ_OBJECT_DECLARE(VulqanEvent, InputEvent)
    public:
    
        VulqanEvent();
        virtual ~VulqanEvent();
    };
}
