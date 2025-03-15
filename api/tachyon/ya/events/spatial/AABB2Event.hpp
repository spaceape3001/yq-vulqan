////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/shape/AxBox2.hpp>

namespace yq::tachyon {

    //! Source moved in 2-Dimensions
    class AABB²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(AABB²Event, SpatialEvent)
    public:
        AABB²Event(const Header&, const AxBox2D&);
    
        const AxBox2D&   aabb() const  { return m_aabb; }
        
        static void init_info();
        
        double  lx() const { return m_aabb.lo.x; }
        double  ly() const { return m_aabb.lo.y; }
        double  hx() const { return m_aabb.hi.x; }
        double  hy() const { return m_aabb.hi.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AABB²Event(const Header&);
        AABB²Event(const AABB²Event&, const Header&);
        ~AABB²Event();

    private:
        AxBox2D  m_aabb = ZERO;
        
        AABB²Event(const AABB²Event&) = delete;
        AABB²Event(AABB²Event&&) = delete;
        AABB²Event& operator=(const AABB²Event&) = delete;
        AABB²Event& operator=(AABB²Event&&) = delete;
    };
}
