////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Source moved in 3-Dimensions
    class Move³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Move³Event, SpatialEvent)
    public:
        Move³Event(const Header&, const Vector3D&);
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Move³Event(const Move³Event&, const Header&);
        ~Move³Event();

    private:
        Vector3D const  m_position;
        
        Move³Event(const Move³Event&) = delete;
        Move³Event(Move³Event&&) = delete;
        Move³Event& operator=(const Move³Event&) = delete;
        Move³Event& operator=(Move³Event&&) = delete;
    };
}
