////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Source moved in 2-Dimensions
    class Position²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position²Event, SpatialEvent)
    public:
        Position²Event(const Header&, const Vector2D&);
    
        const Vector2D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position²Event(const Header&);
        Position²Event(const Position²Event&, const Header&);
        ~Position²Event();

    private:
        Vector2D  m_position = ZERO;
        
        Position²Event(const Position²Event&) = delete;
        Position²Event(Position²Event&&) = delete;
        Position²Event& operator=(const Position²Event&) = delete;
        Position²Event& operator=(Position²Event&&) = delete;
    };
}
