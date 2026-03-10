////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Source moved in 3-Dimensions
    class Position3Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position3Event, SpatialEvent)
    public:
        Position3Event(const Header&, const Vector3D&);
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position3Event(const Header&);
        Position3Event(const Position3Event&, const Header&);
        ~Position3Event();

    private:
        Vector3D  m_position = ZERO;
        
        Position3Event(const Position3Event&) = delete;
        Position3Event(Position3Event&&) = delete;
        Position3Event& operator=(const Position3Event&) = delete;
        Position3Event& operator=(Position3Event&&) = delete;
    };
}
