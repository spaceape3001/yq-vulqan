////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Source resized in 4-Dimensions
    class MinSize⁴Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize⁴Event, SpatialEvent)
    public:
        MinSize⁴Event(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize⁴Event(const Header&);
        MinSize⁴Event(const MinSize⁴Event&, const Header&);
        ~MinSize⁴Event();

    private:
        Size4D  m_size = ZERO;
        
        MinSize⁴Event(const MinSize⁴Event&) = delete;
        MinSize⁴Event(MinSize⁴Event&&) = delete;
        MinSize⁴Event& operator=(const MinSize⁴Event&) = delete;
        MinSize⁴Event& operator=(MinSize⁴Event&&) = delete;
    };
}
