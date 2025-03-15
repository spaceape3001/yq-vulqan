////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/shape/AxBox1.hpp>

namespace yq::tachyon {

    //! Source moved in 1-Dimension
    class AABB¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(AABB¹Event, SpatialEvent)
    public:
        AABB¹Event(const Header&, const AxBox1D&);
    
        const AxBox1D&   aabb() const  { return m_bounds; }
        
        static void init_info();
        
        double  lx() const { return m_bounds.lo.x; }
        double  hx() const { return m_bounds.hi.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AABB¹Event(const Header&);
        AABB¹Event(const AABB¹Event&, const Header&);
        ~AABB¹Event();

    private:
        AxBox1D   m_bounds = ZERO;
        
        AABB¹Event(const AABB¹Event&) = delete;
        AABB¹Event(AABB¹Event&&) = delete;
        AABB¹Event& operator=(const AABB¹Event&) = delete;
        AABB¹Event& operator=(AABB¹Event&&) = delete;
    };
}
