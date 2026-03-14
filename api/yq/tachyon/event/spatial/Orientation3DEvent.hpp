////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {

    //! Source rotated in 3-Dimensions
    class Orientation³DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Orientation³DEvent, SpatialEvent)
    public:
        Orientation³DEvent(const Header&, const Quaternion3D&);
    
        const Quaternion3D&   orientation() const  { return m_orientation; }
        
        static void init_meta();
        
        double  w() const { return m_orientation.w; }
        double  x() const { return m_orientation.x; }
        double  y() const { return m_orientation.y; }
        double  z() const { return m_orientation.z; }
        
        Radian  heading() const;
        Radian  pitch() const;
        Radian  roll() const;

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Orientation³DEvent(const Orientation³DEvent&, const Header&);
        Orientation³DEvent(const Header&);
        ~Orientation³DEvent();

    private:
        Quaternion3D  m_orientation = IDENTITY;
        
        Orientation³DEvent(const Orientation³DEvent&) = delete;
        Orientation³DEvent(Orientation³DEvent&&) = delete;
        Orientation³DEvent& operator=(const Orientation³DEvent&) = delete;
        Orientation³DEvent& operator=(Orientation³DEvent&&) = delete;
    };
}
