////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/color_profile.hpp>

namespace yq::tachyon {
    class SetColorProfileEvent : public Event {
        YQ_OBJECT_DECLARE(SetColorProfileEvent, Event)
    public:
        SetColorProfileEvent(const Header&, const ColorProfileCPtr&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Url&          url() const { return m_url; }
        const ColorProfileCPtr&     color_profile() const { return m_colorProfile; }

    protected:
        SetColorProfileEvent(const SetColorProfileEvent&, const Header&);
        virtual ~SetColorProfileEvent();
        
    private:
    
        ColorProfileCPtr     m_colorProfile;
        Url          m_url;

        SetColorProfileEvent(const SetColorProfileEvent&) = delete;
        SetColorProfileEvent(SetColorProfileEvent&&) = delete;
        SetColorProfileEvent& operator=(const SetColorProfileEvent&) = delete;
        SetColorProfileEvent& operator=(SetColorProfileEvent&&) = delete;
    };
}
