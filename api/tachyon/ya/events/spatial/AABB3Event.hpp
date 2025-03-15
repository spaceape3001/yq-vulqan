////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/shape/AxBox3.hpp>

namespace yq::tachyon {

    //! Source moved in 3-Dimensions
    class AABB³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(AABB³Event, SpatialEvent)
    public:
        AABB³Event(const Header&, const AxBox3D&);
    
        const AxBox3D&   aabb() const  { return m_bounds; }
        
        static void init_info();
        
        double  lx() const { return m_bounds.lo.x; }
        double  ly() const { return m_bounds.lo.y; }
        double  lz() const { return m_bounds.lo.z; }

        double  hx() const { return m_bounds.hi.x; }
        double  hy() const { return m_bounds.hi.y; }
        double  hz() const { return m_bounds.hi.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AABB³Event(const Header&);
        AABB³Event(const AABB³Event&, const Header&);
        ~AABB³Event();

    private:
        AxBox3D  m_bounds = ZERO;
        
        AABB³Event(const AABB³Event&) = delete;
        AABB³Event(AABB³Event&&) = delete;
        AABB³Event& operator=(const AABB³Event&) = delete;
        AABB³Event& operator=(AABB³Event&&) = delete;
    };
}
