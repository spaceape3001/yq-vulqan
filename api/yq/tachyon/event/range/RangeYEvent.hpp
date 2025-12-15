////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/RangeEvent.hpp>
#include <yq/math/Range.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class RangeʸEvent : public RangeEvent {
        YQ_OBJECT_DECLARE(RangeʸEvent, RangeEvent)
    public:
        RangeʸEvent(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  y_range() const { return m_yRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RangeʸEvent(const Header&);
        RangeʸEvent(const RangeʸEvent&, const Header&);
        ~RangeʸEvent();

    private:
        RangeD   m_yRange = {};
        
        RangeʸEvent(const RangeʸEvent&) = delete;
        RangeʸEvent(RangeʸEvent&&) = delete;
        RangeʸEvent& operator=(const RangeʸEvent&) = delete;
        RangeʸEvent& operator=(RangeʸEvent&&) = delete;
    };
}
