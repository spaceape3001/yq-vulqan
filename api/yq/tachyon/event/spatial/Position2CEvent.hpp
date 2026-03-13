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
    class Position²CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position²CEvent, SpatialEvent)
    public:
        Position²CEvent(const Header&, const Centimeter2D&);
    
        const Centimeter2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position²CEvent(const Header&);
        Position²CEvent(const Position²CEvent&, const Header&);
        ~Position²CEvent();

    private:
        Centimeter2D  m_position = ZERO;
        
        Position²CEvent(const Position²CEvent&) = delete;
        Position²CEvent(Position²CEvent&&) = delete;
        Position²CEvent& operator=(const Position²CEvent&) = delete;
        Position²CEvent& operator=(Position²CEvent&&) = delete;
    };
}
