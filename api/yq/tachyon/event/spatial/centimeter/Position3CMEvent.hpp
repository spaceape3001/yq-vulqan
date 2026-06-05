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
    class Position³CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position³CMEvent, SpatialEvent)
    public:
        Position³CMEvent(const Header&, const Centimeter3D&);
    
        const Centimeter3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }
        Centimeter  z() const { return m_position.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position³CMEvent(const Header&);
        Position³CMEvent(const Position³CMEvent&, const Header&);
        ~Position³CMEvent();

    private:
        Centimeter3D  m_position = ZERO;
        
        Position³CMEvent(const Position³CMEvent&) = delete;
        Position³CMEvent(Position³CMEvent&&) = delete;
        Position³CMEvent& operator=(const Position³CMEvent&) = delete;
        Position³CMEvent& operator=(Position³CMEvent&&) = delete;
    };
}
