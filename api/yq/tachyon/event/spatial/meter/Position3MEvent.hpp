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
    class Position³MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position³MEvent, SpatialEvent)
    public:
        Position³MEvent(const Header&, const Meter3D&);
    
        const Meter3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        Meter  z() const { return m_position.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position³MEvent(const Header&);
        Position³MEvent(const Position³MEvent&, const Header&);
        ~Position³MEvent();

    private:
        Meter3D  m_position = ZERO;
        
        Position³MEvent(const Position³MEvent&) = delete;
        Position³MEvent(Position³MEvent&&) = delete;
        Position³MEvent& operator=(const Position³MEvent&) = delete;
        Position³MEvent& operator=(Position³MEvent&&) = delete;
    };
}
