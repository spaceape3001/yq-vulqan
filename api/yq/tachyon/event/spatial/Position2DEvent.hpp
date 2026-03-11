////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Source moved in 2-Dimensions
    class Position²DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position²DEvent, SpatialEvent)
    public:
        Position²DEvent(const Header&, const Vector2D&);
    
        const Vector2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position²DEvent(const Header&);
        Position²DEvent(const Position²DEvent&, const Header&);
        ~Position²DEvent();

    private:
        Vector2D  m_position = ZERO;
        
        Position²DEvent(const Position²DEvent&) = delete;
        Position²DEvent(Position²DEvent&&) = delete;
        Position²DEvent& operator=(const Position²DEvent&) = delete;
        Position²DEvent& operator=(Position²DEvent&&) = delete;
    };
}
