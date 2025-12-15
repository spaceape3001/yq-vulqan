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
    class RangeʷEvent : public RangeEvent {
        YQ_OBJECT_DECLARE(RangeʷEvent, RangeEvent)
    public:
        RangeʷEvent(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  w_range() const { return m_wRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RangeʷEvent(const Header&);
        RangeʷEvent(const RangeʷEvent&, const Header&);
        ~RangeʷEvent();

    private:
        RangeD   m_wRange = {};
        
        RangeʷEvent(const RangeʷEvent&) = delete;
        RangeʷEvent(RangeʷEvent&&) = delete;
        RangeʷEvent& operator=(const RangeʷEvent&) = delete;
        RangeʷEvent& operator=(RangeʷEvent&&) = delete;
    };
}
