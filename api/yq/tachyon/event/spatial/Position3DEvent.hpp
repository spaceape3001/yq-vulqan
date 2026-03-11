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
    class Position³DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position³DEvent, SpatialEvent)
    public:
        Position³DEvent(const Header&, const Vector3D&);
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position³DEvent(const Header&);
        Position³DEvent(const Position³DEvent&, const Header&);
        ~Position³DEvent();

    private:
        Vector3D  m_position = ZERO;
        
        Position³DEvent(const Position³DEvent&) = delete;
        Position³DEvent(Position³DEvent&&) = delete;
        Position³DEvent& operator=(const Position³DEvent&) = delete;
        Position³DEvent& operator=(Position³DEvent&&) = delete;
    };
}
