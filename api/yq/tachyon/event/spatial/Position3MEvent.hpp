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
    class Position3MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position3MEvent, SpatialEvent)
    public:
        Position3MEvent(const Header&, const Meter3D&);
    
        const Meter3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        Meter  z() const { return m_position.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position3MEvent(const Header&);
        Position3MEvent(const Position3MEvent&, const Header&);
        ~Position3MEvent();

    private:
        Meter3D  m_position = ZERO;
        
        Position3MEvent(const Position3MEvent&) = delete;
        Position3MEvent(Position3MEvent&&) = delete;
        Position3MEvent& operator=(const Position3MEvent&) = delete;
        Position3MEvent& operator=(Position3MEvent&&) = delete;
    };
}
