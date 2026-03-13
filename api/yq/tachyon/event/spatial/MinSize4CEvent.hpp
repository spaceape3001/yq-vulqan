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
    class MinSize⁴CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize⁴CEvent, SpatialEvent)
    public:
        MinSize⁴CEvent(const Header&, const Size4CM&);
    
        const Size4CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        Centimeter  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize⁴CEvent(const Header&);
        MinSize⁴CEvent(const MinSize⁴CEvent&, const Header&);
        ~MinSize⁴CEvent();

    private:
        Size4CM  m_size = ZERO;
        
        MinSize⁴CEvent(const MinSize⁴CEvent&) = delete;
        MinSize⁴CEvent(MinSize⁴CEvent&&) = delete;
        MinSize⁴CEvent& operator=(const MinSize⁴CEvent&) = delete;
        MinSize⁴CEvent& operator=(MinSize⁴CEvent&&) = delete;
    };
}
