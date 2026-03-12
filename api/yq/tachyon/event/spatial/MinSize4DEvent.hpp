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
    class MinSize⁴DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize⁴DEvent, SpatialEvent)
    public:
        MinSize⁴DEvent(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize⁴DEvent(const Header&);
        MinSize⁴DEvent(const MinSize⁴DEvent&, const Header&);
        ~MinSize⁴DEvent();

    private:
        Size4D  m_size = ZERO;
        
        MinSize⁴DEvent(const MinSize⁴DEvent&) = delete;
        MinSize⁴DEvent(MinSize⁴DEvent&&) = delete;
        MinSize⁴DEvent& operator=(const MinSize⁴DEvent&) = delete;
        MinSize⁴DEvent& operator=(MinSize⁴DEvent&&) = delete;
    };
}
