////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Source moved in 1-Dimension
    class Position¹DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position¹DEvent, SpatialEvent)
    public:
        Position¹DEvent(const Header&, const Vector1D&);
    
        const Vector1D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position¹DEvent(const Header&);
        Position¹DEvent(const Position¹DEvent&, const Header&);
        ~Position¹DEvent();

    private:
        Vector1D   m_position = ZERO;
        
        Position¹DEvent(const Position¹DEvent&) = delete;
        Position¹DEvent(Position¹DEvent&&) = delete;
        Position¹DEvent& operator=(const Position¹DEvent&) = delete;
        Position¹DEvent& operator=(Position¹DEvent&&) = delete;
    };
}
