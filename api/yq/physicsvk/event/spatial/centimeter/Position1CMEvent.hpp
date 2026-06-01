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
    class Position¹CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position¹CMEvent, SpatialEvent)
    public:
        Position¹CMEvent(const Header&, const Centimeter1D&);
    
        const Centimeter1D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position¹CMEvent(const Header&);
        Position¹CMEvent(const Position¹CMEvent&, const Header&);
        ~Position¹CMEvent();

    private:
        Centimeter1D   m_position = ZERO;
        
        Position¹CMEvent(const Position¹CMEvent&) = delete;
        Position¹CMEvent(Position¹CMEvent&&) = delete;
        Position¹CMEvent& operator=(const Position¹CMEvent&) = delete;
        Position¹CMEvent& operator=(Position¹CMEvent&&) = delete;
    };
}
