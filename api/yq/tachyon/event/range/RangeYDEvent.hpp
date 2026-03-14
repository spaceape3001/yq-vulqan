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
    class RangeʸDEvent : public RangeEvent {
        YQ_OBJECT_DECLARE(RangeʸDEvent, RangeEvent)
    public:
        RangeʸDEvent(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  y_range() const { return m_yRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RangeʸDEvent(const Header&);
        RangeʸDEvent(const RangeʸDEvent&, const Header&);
        ~RangeʸDEvent();

    private:
        RangeD   m_yRange = {};
        
        RangeʸDEvent(const RangeʸDEvent&) = delete;
        RangeʸDEvent(RangeʸDEvent&&) = delete;
        RangeʸDEvent& operator=(const RangeʸDEvent&) = delete;
        RangeʸDEvent& operator=(RangeʸDEvent&&) = delete;
    };
}
