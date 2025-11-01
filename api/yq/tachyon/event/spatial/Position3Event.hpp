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
    class Position³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position³Event, SpatialEvent)
    public:
        Position³Event(const Header&, const Vector3D&);
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position³Event(const Header&);
        Position³Event(const Position³Event&, const Header&);
        ~Position³Event();

    private:
        Vector3D  m_position = ZERO;
        
        Position³Event(const Position³Event&) = delete;
        Position³Event(Position³Event&&) = delete;
        Position³Event& operator=(const Position³Event&) = delete;
        Position³Event& operator=(Position³Event&&) = delete;
    };
}
