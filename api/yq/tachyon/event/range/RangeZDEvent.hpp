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
    class RangeᶻDEvent : public RangeEvent {
        YQ_OBJECT_DECLARE(RangeᶻDEvent, RangeEvent)
    public:
        RangeᶻDEvent(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  z_range() const { return m_zRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RangeᶻDEvent(const Header&);
        RangeᶻDEvent(const RangeᶻDEvent&, const Header&);
        ~RangeᶻDEvent();

    private:
        RangeD   m_zRange = {};
        
        RangeᶻDEvent(const RangeᶻDEvent&) = delete;
        RangeᶻDEvent(RangeᶻDEvent&&) = delete;
        RangeᶻDEvent& operator=(const RangeᶻDEvent&) = delete;
        RangeᶻDEvent& operator=(RangeᶻDEvent&&) = delete;
    };
}
