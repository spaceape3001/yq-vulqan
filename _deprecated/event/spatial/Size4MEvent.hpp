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
    class Size⁴MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size⁴MEvent, SpatialEvent)
    public:
        Size⁴MEvent(const Header&, const Size4M&);
    
        const Size4M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }
        Meter  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size⁴MEvent(const Header&);
        Size⁴MEvent(const Size⁴MEvent&, const Header&);
        ~Size⁴MEvent();

    private:
        Size4M  m_size = ZERO;
        
        Size⁴MEvent(const Size⁴MEvent&) = delete;
        Size⁴MEvent(Size⁴MEvent&&) = delete;
        Size⁴MEvent& operator=(const Size⁴MEvent&) = delete;
        Size⁴MEvent& operator=(Size⁴MEvent&&) = delete;
    };
}
