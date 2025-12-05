////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/tachyon/event/LightEvent.hpp>

namespace yq::tachyon {
    class LightColorEvent : public LightEvent {
        YQ_OBJECT_DECLARE(LightColorEvent, LightEvent)
    public:
        LightColorEvent(const Header&, const RGB3F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const RGB3F& color() const { return m_color; }
        void    set_color(const RGB3F&);

    protected:
        LightColorEvent(const LightColorEvent&, const Header&);
        virtual ~LightColorEvent();
        
    private:
    
        RGB3F       m_color;

        LightColorEvent(const LightColorEvent&) = delete;
        LightColorEvent(LightColorEvent&&) = delete;
        LightColorEvent& operator=(const LightColorEvent&) = delete;
        LightColorEvent& operator=(LightColorEvent&&) = delete;
    };
}
