////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/shape/AxBox1.hpp>

namespace yq::tachyon {

    //! Source moved in 1-Dimension
    class AABB¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(AABB¹Event, SpatialEvent)
    public:
        AABB¹Event(const Header&, const AxBox1D&);
    
        const AxBox1D&   aabb() const  { return m_aabb; }
        
        static void init_meta();
        
        double  lx() const { return m_aabb.lo.x; }
        double  hx() const { return m_aabb.hi.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AABB¹Event(const Header&);
        AABB¹Event(const AABB¹Event&, const Header&);
        ~AABB¹Event();

    private:
        AxBox1D   m_aabb = ZERO;
        
        AABB¹Event(const AABB¹Event&) = delete;
        AABB¹Event(AABB¹Event&&) = delete;
        AABB¹Event& operator=(const AABB¹Event&) = delete;
        AABB¹Event& operator=(AABB¹Event&&) = delete;
    };
}
