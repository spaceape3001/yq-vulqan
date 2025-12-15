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
    class RangeˣEvent : public RangeEvent {
        YQ_OBJECT_DECLARE(RangeˣEvent, RangeEvent)
    public:
        RangeˣEvent(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  x_range() const { return m_xRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RangeˣEvent(const Header&);
        RangeˣEvent(const RangeˣEvent&, const Header&);
        ~RangeˣEvent();

    private:
        RangeD   m_xRange = {};
        
        RangeˣEvent(const RangeˣEvent&) = delete;
        RangeˣEvent(RangeˣEvent&&) = delete;
        RangeˣEvent& operator=(const RangeˣEvent&) = delete;
        RangeˣEvent& operator=(RangeˣEvent&&) = delete;
    };
}
