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
    class RangeᶻEvent : public RangeEvent {
        YQ_OBJECT_DECLARE(RangeᶻEvent, RangeEvent)
    public:
        RangeᶻEvent(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  z_range() const { return m_zRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RangeᶻEvent(const Header&);
        RangeᶻEvent(const RangeᶻEvent&, const Header&);
        ~RangeᶻEvent();

    private:
        RangeD   m_zRange = {};
        
        RangeᶻEvent(const RangeᶻEvent&) = delete;
        RangeᶻEvent(RangeᶻEvent&&) = delete;
        RangeᶻEvent& operator=(const RangeᶻEvent&) = delete;
        RangeᶻEvent& operator=(RangeᶻEvent&&) = delete;
    };
}
