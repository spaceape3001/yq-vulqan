////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Spinor2.hpp>

namespace yq::tachyon {

    //! Source rotated in 2-Dimensions
    class Orientation²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Orientation²Event, SpatialEvent)
    public:
        Orientation²Event(const Header&, const Spinor2D&);
    
        const Spinor2D&   orientation() const  { return m_orientation; }
        
        static void init_info();
        
        double  a() const { return m_orientation.a; }
        double  xy() const { return m_orientation.xy; }
        
        Radian  heading() const;

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Orientation²Event(const Orientation²Event&, const Header&);
        Orientation²Event(const Header&);
        ~Orientation²Event();

    private:
        Spinor2D  m_orientation = IDENTITY;
        
        Orientation²Event(const Orientation²Event&) = delete;
        Orientation²Event(Orientation²Event&&) = delete;
        Orientation²Event& operator=(const Orientation²Event&) = delete;
        Orientation²Event& operator=(Orientation²Event&&) = delete;
    };
}
