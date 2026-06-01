////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Source moved in 4-Dimensions
    class Position⁴CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position⁴CMEvent, SpatialEvent)
    public:
        Position⁴CMEvent(const Header&, const Centimeter4D&);
    
        const Centimeter4D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }
        Centimeter  z() const { return m_position.z; }
        Centimeter  w() const { return m_position.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position⁴CMEvent(const Header&);
        Position⁴CMEvent(const Position⁴CMEvent&, const Header&);
        ~Position⁴CMEvent();

    private:
        Centimeter4D  m_position = ZERO;
        
        Position⁴CMEvent(const Position⁴CMEvent&) = delete;
        Position⁴CMEvent(Position⁴CMEvent&&) = delete;
        Position⁴CMEvent& operator=(const Position⁴CMEvent&) = delete;
        Position⁴CMEvent& operator=(Position⁴CMEvent&&) = delete;
    };
}
