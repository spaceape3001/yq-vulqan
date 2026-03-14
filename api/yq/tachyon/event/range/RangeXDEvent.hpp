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
    class RangeˣDEvent : public RangeEvent {
        YQ_OBJECT_DECLARE(RangeˣDEvent, RangeEvent)
    public:
        RangeˣDEvent(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  x_range() const { return m_xRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RangeˣDEvent(const Header&);
        RangeˣDEvent(const RangeˣDEvent&, const Header&);
        ~RangeˣDEvent();

    private:
        RangeD   m_xRange = {};
        
        RangeˣDEvent(const RangeˣDEvent&) = delete;
        RangeˣDEvent(RangeˣDEvent&&) = delete;
        RangeˣDEvent& operator=(const RangeˣDEvent&) = delete;
        RangeˣDEvent& operator=(RangeˣDEvent&&) = delete;
    };
}
