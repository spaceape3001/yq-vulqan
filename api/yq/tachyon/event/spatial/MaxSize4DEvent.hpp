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
    class MaxSize⁴DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize⁴DEvent, SpatialEvent)
    public:
        MaxSize⁴DEvent(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize⁴DEvent(const Header&);
        MaxSize⁴DEvent(const MaxSize⁴DEvent&, const Header&);
        ~MaxSize⁴DEvent();

    private:
        Size4D  m_size = ZERO;
        
        MaxSize⁴DEvent(const MaxSize⁴DEvent&) = delete;
        MaxSize⁴DEvent(MaxSize⁴DEvent&&) = delete;
        MaxSize⁴DEvent& operator=(const MaxSize⁴DEvent&) = delete;
        MaxSize⁴DEvent& operator=(MaxSize⁴DEvent&&) = delete;
    };
}
