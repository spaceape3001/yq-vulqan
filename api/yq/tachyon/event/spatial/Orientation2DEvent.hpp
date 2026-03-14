////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Spinor2.hpp>

namespace yq::tachyon {

    //! Source rotated in 2-Dimensions
    class Orientation²DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Orientation²DEvent, SpatialEvent)
    public:
        Orientation²DEvent(const Header&, const Spinor2D&);
    
        const Spinor2D&   orientation() const  { return m_orientation; }
        
        static void init_meta();
        
        double  a() const { return m_orientation.a; }
        double  xy() const { return m_orientation.xy; }
        
        Radian  heading() const;

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Orientation²DEvent(const Orientation²DEvent&, const Header&);
        Orientation²DEvent(const Header&);
        ~Orientation²DEvent();

    private:
        Spinor2D  m_orientation = IDENTITY;
        
        Orientation²DEvent(const Orientation²DEvent&) = delete;
        Orientation²DEvent(Orientation²DEvent&&) = delete;
        Orientation²DEvent& operator=(const Orientation²DEvent&) = delete;
        Orientation²DEvent& operator=(Orientation²DEvent&&) = delete;
    };
}
