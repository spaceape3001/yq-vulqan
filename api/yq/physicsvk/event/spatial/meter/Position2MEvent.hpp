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
    class Position²MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position²MEvent, SpatialEvent)
    public:
        Position²MEvent(const Header&, const Meter2D&);
    
        const Meter2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position²MEvent(const Header&);
        Position²MEvent(const Position²MEvent&, const Header&);
        ~Position²MEvent();

    private:
        Meter2D  m_position = ZERO;
        
        Position²MEvent(const Position²MEvent&) = delete;
        Position²MEvent(Position²MEvent&&) = delete;
        Position²MEvent& operator=(const Position²MEvent&) = delete;
        Position²MEvent& operator=(Position²MEvent&&) = delete;
    };
}
