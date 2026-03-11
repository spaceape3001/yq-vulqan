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
    class Position⁴MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position⁴MEvent, SpatialEvent)
    public:
        Position⁴MEvent(const Header&, const Meter4D&);
    
        const Meter4D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        Meter  z() const { return m_position.z; }
        Meter  w() const { return m_position.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position⁴MEvent(const Header&);
        Position⁴MEvent(const Position⁴MEvent&, const Header&);
        ~Position⁴MEvent();

    private:
        Meter4D  m_position = ZERO;
        
        Position⁴MEvent(const Position⁴MEvent&) = delete;
        Position⁴MEvent(Position⁴MEvent&&) = delete;
        Position⁴MEvent& operator=(const Position⁴MEvent&) = delete;
        Position⁴MEvent& operator=(Position⁴MEvent&&) = delete;
    };
}
