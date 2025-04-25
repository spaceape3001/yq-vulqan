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
    class MaxSize⁴Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize⁴Event, SpatialEvent)
    public:
        MaxSize⁴Event(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize⁴Event(const Header&);
        MaxSize⁴Event(const MaxSize⁴Event&, const Header&);
        ~MaxSize⁴Event();

    private:
        Size4D  m_size = ZERO;
        
        MaxSize⁴Event(const MaxSize⁴Event&) = delete;
        MaxSize⁴Event(MaxSize⁴Event&&) = delete;
        MaxSize⁴Event& operator=(const MaxSize⁴Event&) = delete;
        MaxSize⁴Event& operator=(MaxSize⁴Event&&) = delete;
    };
}
