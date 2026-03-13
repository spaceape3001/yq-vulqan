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
    class Position¹CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position¹CEvent, SpatialEvent)
    public:
        Position¹CEvent(const Header&, const Centimeter1D&);
    
        const Centimeter1D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position¹CEvent(const Header&);
        Position¹CEvent(const Position¹CEvent&, const Header&);
        ~Position¹CEvent();

    private:
        Centimeter1D   m_position = ZERO;
        
        Position¹CEvent(const Position¹CEvent&) = delete;
        Position¹CEvent(Position¹CEvent&&) = delete;
        Position¹CEvent& operator=(const Position¹CEvent&) = delete;
        Position¹CEvent& operator=(Position¹CEvent&&) = delete;
    };
}
