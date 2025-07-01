////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EditorEvent.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/light.hpp>

using namespace yq;
using namespace yq::tachyon;

class LightSelectEvent : public EditorEvent {
    YQ_OBJECT_DECLARE(LightSelectEvent, EditorEvent)
public:
    LightSelectEvent(const Header&, LightID);
    LightSelectEvent(const LightSelectEvent&, const Header&);
    ~LightSelectEvent();
    
    PostCPtr    clone(rebind_k, const Header&) const override;

    LightID        light() const { return m_light; }
    static void init_meta();
private:
    LightID        m_light;
};
