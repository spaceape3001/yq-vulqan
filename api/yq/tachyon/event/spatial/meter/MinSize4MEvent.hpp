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
    class MinSize⁴MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize⁴MEvent, SpatialEvent)
    public:
        MinSize⁴MEvent(const Header&, const Size4M&);
    
        const Size4M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }
        Meter  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize⁴MEvent(const Header&);
        MinSize⁴MEvent(const MinSize⁴MEvent&, const Header&);
        ~MinSize⁴MEvent();

    private:
        Size4M  m_size = ZERO;
        
        MinSize⁴MEvent(const MinSize⁴MEvent&) = delete;
        MinSize⁴MEvent(MinSize⁴MEvent&&) = delete;
        MinSize⁴MEvent& operator=(const MinSize⁴MEvent&) = delete;
        MinSize⁴MEvent& operator=(MinSize⁴MEvent&&) = delete;
    };
}
