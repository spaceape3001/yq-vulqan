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
    class Orientation³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Orientation³Event, SpatialEvent)
    public:
        Orientation³Event(const Header&, const Quaternion3D&);
    
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
        Orientation³Event(const Orientation³Event&, const Header&);
        Orientation³Event(const Header&);
        ~Orientation³Event();

    private:
        Quaternion3D  m_orientation = IDENTITY;
        
        Orientation³Event(const Orientation³Event&) = delete;
        Orientation³Event(Orientation³Event&&) = delete;
        Orientation³Event& operator=(const Orientation³Event&) = delete;
        Orientation³Event& operator=(Orientation³Event&&) = delete;
    };
}
