////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EditorEvent.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/rendered.hpp>

using namespace yq;
using namespace yq::tachyon;

class RenderedSelectEvent : public EditorEvent {
    YQ_OBJECT_DECLARE(RenderedSelectEvent, EditorEvent)
public:
    RenderedSelectEvent(const Header&, RenderedID);
    RenderedSelectEvent(const RenderedSelectEvent&, const Header&);
    ~RenderedSelectEvent();
    
    PostCPtr    clone(rebind_k, const Header&) const override;

    RenderedID        rendered() const { return m_rendered; }
    static void init_info();
private:
    RenderedID        m_rendered;
};
