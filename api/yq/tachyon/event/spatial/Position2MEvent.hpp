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
    class Position2MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position2MEvent, SpatialEvent)
    public:
        Position2MEvent(const Header&, const Meter2D&);
    
        const Meter2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position2MEvent(const Header&);
        Position2MEvent(const Position2MEvent&, const Header&);
        ~Position2MEvent();

    private:
        Meter2D  m_position = ZERO;
        
        Position2MEvent(const Position2MEvent&) = delete;
        Position2MEvent(Position2MEvent&&) = delete;
        Position2MEvent& operator=(const Position2MEvent&) = delete;
        Position2MEvent& operator=(Position2MEvent&&) = delete;
    };
}
