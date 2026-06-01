////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Source resized in 4-Dimensions
    class MinSize⁴CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize⁴CMEvent, SpatialEvent)
    public:
        MinSize⁴CMEvent(const Header&, const Size4CM&);
    
        const Size4CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        Centimeter  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize⁴CMEvent(const Header&);
        MinSize⁴CMEvent(const MinSize⁴CMEvent&, const Header&);
        ~MinSize⁴CMEvent();

    private:
        Size4CM  m_size = ZERO;
        
        MinSize⁴CMEvent(const MinSize⁴CMEvent&) = delete;
        MinSize⁴CMEvent(MinSize⁴CMEvent&&) = delete;
        MinSize⁴CMEvent& operator=(const MinSize⁴CMEvent&) = delete;
        MinSize⁴CMEvent& operator=(MinSize⁴CMEvent&&) = delete;
    };
}
