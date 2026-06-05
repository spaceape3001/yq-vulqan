////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Source moved in 2-Dimensions
    class Position²CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position²CMEvent, SpatialEvent)
    public:
        Position²CMEvent(const Header&, const Centimeter2D&);
    
        const Centimeter2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position²CMEvent(const Header&);
        Position²CMEvent(const Position²CMEvent&, const Header&);
        ~Position²CMEvent();

    private:
        Centimeter2D  m_position = ZERO;
        
        Position²CMEvent(const Position²CMEvent&) = delete;
        Position²CMEvent(Position²CMEvent&&) = delete;
        Position²CMEvent& operator=(const Position²CMEvent&) = delete;
        Position²CMEvent& operator=(Position²CMEvent&&) = delete;
    };
}
