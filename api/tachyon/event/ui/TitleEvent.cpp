////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ui/TitleEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TitleEvent)

namespace yq::tachyon {

    TitleEvent::TitleEvent(const Header&h, std::string_view szNewTitle) : UIEvent(h), m_title(szNewTitle)
    {
    }

    TitleEvent::TitleEvent(const TitleEvent& cp, const Header& h) : UIEvent(cp, h), m_title(cp.m_title)
    {
    }
    
    TitleEvent::~TitleEvent()
    {
    }

    PostCPtr    TitleEvent::clone(rebind_k, const Header&h) const 
    {
        return new TitleEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TitleEvent::init_info()
    {
        auto w = writer<TitleEvent>();
        w.description("Title Event");
        w.property("title", &TitleEvent::m_title).tag(kTag_Log).tag(kTag_Save);
    }
}
