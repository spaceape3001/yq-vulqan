////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/shape/AxBox4.hpp>

namespace yq::tachyon {

    //! Source moved in 4-Dimensions
    class AABB⁴Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(AABB⁴Event, SpatialEvent)
    public:
        AABB⁴Event(const Header&, const AxBox4D&);
    
        const AxBox4D&   aabb() const  { return m_aabb; }
        
        static void init_meta();
        
        double  lx() const { return m_aabb.lo.x; }
        double  ly() const { return m_aabb.lo.y; }
        double  lz() const { return m_aabb.lo.z; }
        double  lw() const { return m_aabb.lo.w; }

        double  hx() const { return m_aabb.hi.x; }
        double  hy() const { return m_aabb.hi.y; }
        double  hz() const { return m_aabb.hi.z; }
        double  hw() const { return m_aabb.hi.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AABB⁴Event(const Header&);
        AABB⁴Event(const AABB⁴Event&, const Header&);
        ~AABB⁴Event();

    private:
        AxBox4D  m_aabb = ZERO;
        
        AABB⁴Event(const AABB⁴Event&) = delete;
        AABB⁴Event(AABB⁴Event&&) = delete;
        AABB⁴Event& operator=(const AABB⁴Event&) = delete;
        AABB⁴Event& operator=(AABB⁴Event&&) = delete;
    };
}
