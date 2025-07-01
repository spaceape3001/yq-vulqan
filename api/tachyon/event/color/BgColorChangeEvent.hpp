////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/ColorEvent.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class BgColorChangeEvent : public ColorEvent {
        YQ_OBJECT_DECLARE(BgColorChangeEvent, ColorEvent)
    public:
        BgColorChangeEvent(const Header&, const RGBA4F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const RGBA4F& bgcolor() const { return m_bgcolor; }
        void            set_bgcolor(const RGBA4F&);

    protected:
        BgColorChangeEvent(const BgColorChangeEvent&, const Header&);
        virtual ~BgColorChangeEvent();
        
    private:

        RGBA4F  m_bgcolor;

        BgColorChangeEvent(const BgColorChangeEvent&) = delete;
        BgColorChangeEvent(BgColorChangeEvent&&) = delete;
        BgColorChangeEvent& operator=(const BgColorChangeEvent&) = delete;
        BgColorChangeEvent& operator=(BgColorChangeEvent&&) = delete;
    };
}
