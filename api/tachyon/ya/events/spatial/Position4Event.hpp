////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Source moved in 4-Dimensions
    class Position⁴Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position⁴Event, SpatialEvent)
    public:
        Position⁴Event(const Header&, const Vector4D&);
    
        const Vector4D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        double  w() const { return m_position.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position⁴Event(const Header&);
        Position⁴Event(const Position⁴Event&, const Header&);
        ~Position⁴Event();

    private:
        Vector4D  m_position = ZERO;
        
        Position⁴Event(const Position⁴Event&) = delete;
        Position⁴Event(Position⁴Event&&) = delete;
        Position⁴Event& operator=(const Position⁴Event&) = delete;
        Position⁴Event& operator=(Position⁴Event&&) = delete;
    };
}
