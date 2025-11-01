////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/AxBox3.hpp>

namespace yq::tachyon {

    //! Source moved in 3-Dimensions
    class AABB³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(AABB³Event, SpatialEvent)
    public:
        AABB³Event(const Header&, const AxBox3D&);
    
        const AxBox3D&   aabb() const  { return m_aabb; }
        
        static void init_meta();
        
        double  lx() const { return m_aabb.lo.x; }
        double  ly() const { return m_aabb.lo.y; }
        double  lz() const { return m_aabb.lo.z; }

        double  hx() const { return m_aabb.hi.x; }
        double  hy() const { return m_aabb.hi.y; }
        double  hz() const { return m_aabb.hi.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AABB³Event(const Header&);
        AABB³Event(const AABB³Event&, const Header&);
        ~AABB³Event();

    private:
        AxBox3D  m_aabb = ZERO;
        
        AABB³Event(const AABB³Event&) = delete;
        AABB³Event(AABB³Event&&) = delete;
        AABB³Event& operator=(const AABB³Event&) = delete;
        AABB³Event& operator=(AABB³Event&&) = delete;
    };
}
