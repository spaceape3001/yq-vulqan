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
    class MaxSize⁴CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize⁴CMEvent, SpatialEvent)
    public:
        MaxSize⁴CMEvent(const Header&, const Size4CM&);
    
        const Size4CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        Centimeter  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize⁴CMEvent(const Header&);
        MaxSize⁴CMEvent(const MaxSize⁴CMEvent&, const Header&);
        ~MaxSize⁴CMEvent();

    private:
        Size4CM  m_size = ZERO;
        
        MaxSize⁴CMEvent(const MaxSize⁴CMEvent&) = delete;
        MaxSize⁴CMEvent(MaxSize⁴CMEvent&&) = delete;
        MaxSize⁴CMEvent& operator=(const MaxSize⁴CMEvent&) = delete;
        MaxSize⁴CMEvent& operator=(MaxSize⁴CMEvent&&) = delete;
    };
}
