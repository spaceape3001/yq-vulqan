////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Source resized in 4-Dimensions
    class MaxSize⁴MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize⁴MEvent, SpatialEvent)
    public:
        MaxSize⁴MEvent(const Header&, const Size4M&);
    
        const Size4M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }
        Meter  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize⁴MEvent(const Header&);
        MaxSize⁴MEvent(const MaxSize⁴MEvent&, const Header&);
        ~MaxSize⁴MEvent();

    private:
        Size4M  m_size = ZERO;
        
        MaxSize⁴MEvent(const MaxSize⁴MEvent&) = delete;
        MaxSize⁴MEvent(MaxSize⁴MEvent&&) = delete;
        MaxSize⁴MEvent& operator=(const MaxSize⁴MEvent&) = delete;
        MaxSize⁴MEvent& operator=(MaxSize⁴MEvent&&) = delete;
    };
}
