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
    class Position⁴CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position⁴CEvent, SpatialEvent)
    public:
        Position⁴CEvent(const Header&, const Centimeter4D&);
    
        const Centimeter4D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }
        Centimeter  z() const { return m_position.z; }
        Centimeter  w() const { return m_position.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position⁴CEvent(const Header&);
        Position⁴CEvent(const Position⁴CEvent&, const Header&);
        ~Position⁴CEvent();

    private:
        Centimeter4D  m_position = ZERO;
        
        Position⁴CEvent(const Position⁴CEvent&) = delete;
        Position⁴CEvent(Position⁴CEvent&&) = delete;
        Position⁴CEvent& operator=(const Position⁴CEvent&) = delete;
        Position⁴CEvent& operator=(Position⁴CEvent&&) = delete;
    };
}
