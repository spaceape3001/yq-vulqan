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
    class RangeʷDEvent : public RangeEvent {
        YQ_OBJECT_DECLARE(RangeʷDEvent, RangeEvent)
    public:
        RangeʷDEvent(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  w_range() const { return m_wRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RangeʷDEvent(const Header&);
        RangeʷDEvent(const RangeʷDEvent&, const Header&);
        ~RangeʷDEvent();

    private:
        RangeD   m_wRange = {};
        
        RangeʷDEvent(const RangeʷDEvent&) = delete;
        RangeʷDEvent(RangeʷDEvent&&) = delete;
        RangeʷDEvent& operator=(const RangeʷDEvent&) = delete;
        RangeʷDEvent& operator=(RangeʷDEvent&&) = delete;
    };
}
