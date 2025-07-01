////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/ColorEvent.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class ColorChangeEvent : public ColorEvent {
        YQ_OBJECT_DECLARE(ColorChangeEvent, ColorEvent)
    public:
        ColorChangeEvent(const Header&, const RGBA4F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const RGBA4F& color() const { return m_color; }
        void            set_color(const RGBA4F&);

    protected:
        ColorChangeEvent(const ColorChangeEvent&, const Header&);
        virtual ~ColorChangeEvent();
        
    private:

        RGBA4F  m_color;

        ColorChangeEvent(const ColorChangeEvent&) = delete;
        ColorChangeEvent(ColorChangeEvent&&) = delete;
        ColorChangeEvent& operator=(const ColorChangeEvent&) = delete;
        ColorChangeEvent& operator=(ColorChangeEvent&&) = delete;
    };
}
