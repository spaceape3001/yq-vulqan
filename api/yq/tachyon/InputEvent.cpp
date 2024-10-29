////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InputEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::InputEvent)

namespace yq::tachyon {
    
    InputEventInfo::InputEventInfo(std::string_view zName, const post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
        set(Flag::INPUT);
    }

    ////////////////////////////////////////////////////////////////////////////

    InputEvent::InputEvent(const Param& p) : post::Event(p), m_viewer(p.viewer)
    {
    }
    
    InputEvent::~InputEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_input_event()
    {
        {
            auto w = writer<InputEvent>();
            w.description("Input event base class");
        }
    }
    
    YQ_INVOKE(reg_input_event();)
}
