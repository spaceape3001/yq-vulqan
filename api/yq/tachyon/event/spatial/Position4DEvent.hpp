////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Source moved in 4-Dimensions
    class Position⁴DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position⁴DEvent, SpatialEvent)
    public:
        Position⁴DEvent(const Header&, const Vector4D&);
    
        const Vector4D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        double  w() const { return m_position.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position⁴DEvent(const Header&);
        Position⁴DEvent(const Position⁴DEvent&, const Header&);
        ~Position⁴DEvent();

    private:
        Vector4D  m_position = ZERO;
        
        Position⁴DEvent(const Position⁴DEvent&) = delete;
        Position⁴DEvent(Position⁴DEvent&&) = delete;
        Position⁴DEvent& operator=(const Position⁴DEvent&) = delete;
        Position⁴DEvent& operator=(Position⁴DEvent&&) = delete;
    };
}
