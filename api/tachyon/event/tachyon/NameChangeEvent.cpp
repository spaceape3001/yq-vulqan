////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/tachyon/NameChangeEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NameChangeEvent)

namespace yq::tachyon {

    NameChangeEvent::NameChangeEvent(const Header&h, std::string&& sOld, std::string_view sNew) : 
        TachyonEvent(h), m_old(std::move(sOld)), m_new(sNew)
    {
    }

    NameChangeEvent::NameChangeEvent(const NameChangeEvent& cp, const Header& h) : 
        TachyonEvent(cp, h), m_old(cp.m_old), m_new(cp.m_new)
    {
    }
    
    NameChangeEvent::~NameChangeEvent()
    {
    }

    PostCPtr    NameChangeEvent::clone(rebind_k, const Header&h) const 
    {
        return new NameChangeEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void NameChangeEvent::init_info()
    {
        auto w = writer<NameChangeEvent>();
        w.description("NameChange Event");
    }
}
