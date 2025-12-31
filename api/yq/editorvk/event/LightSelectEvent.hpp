////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EditorEvent.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/light.hpp>

namespace yq::tachyon {

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
}
