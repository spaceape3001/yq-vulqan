////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Source moved in 3-Dimensions
    class Position³CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position³CEvent, SpatialEvent)
    public:
        Position³CEvent(const Header&, const Centimeter3D&);
    
        const Centimeter3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }
        Centimeter  z() const { return m_position.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position³CEvent(const Header&);
        Position³CEvent(const Position³CEvent&, const Header&);
        ~Position³CEvent();

    private:
        Centimeter3D  m_position = ZERO;
        
        Position³CEvent(const Position³CEvent&) = delete;
        Position³CEvent(Position³CEvent&&) = delete;
        Position³CEvent& operator=(const Position³CEvent&) = delete;
        Position³CEvent& operator=(Position³CEvent&&) = delete;
    };
}
