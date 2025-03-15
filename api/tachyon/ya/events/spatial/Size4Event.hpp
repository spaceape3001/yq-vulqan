////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Source resized in 4-Dimensions
    class Size⁴Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size⁴Event, SpatialEvent)
    public:
        Size⁴Event(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size⁴Event(const Header&);
        Size⁴Event(const Size⁴Event&, const Header&);
        ~Size⁴Event();

    private:
        Size4D  m_size = ZERO;
        
        Size⁴Event(const Size⁴Event&) = delete;
        Size⁴Event(Size⁴Event&&) = delete;
        Size⁴Event& operator=(const Size⁴Event&) = delete;
        Size⁴Event& operator=(Size⁴Event&&) = delete;
    };
}
