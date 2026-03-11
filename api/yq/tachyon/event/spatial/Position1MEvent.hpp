////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Source moved in 1-Dimension
    class Position¹MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position¹MEvent, SpatialEvent)
    public:
        Position¹MEvent(const Header&, const Meter1D&);
    
        const Meter1D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position¹MEvent(const Header&);
        Position¹MEvent(const Position¹MEvent&, const Header&);
        ~Position¹MEvent();

    private:
        Meter1D   m_position = ZERO;
        
        Position¹MEvent(const Position¹MEvent&) = delete;
        Position¹MEvent(Position¹MEvent&&) = delete;
        Position¹MEvent& operator=(const Position¹MEvent&) = delete;
        Position¹MEvent& operator=(Position¹MEvent&&) = delete;
    };
}
