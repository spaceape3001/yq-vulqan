////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Source moved in 2-Dimensions
    class Move²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Move²Event, SpatialEvent)
    public:
        Move²Event(const Header&, const Vector2D&);
    
        const Vector2D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Move²Event(const Move²Event&, const Header&);
        ~Move²Event();

    private:
        Vector2D const  m_position;
        
        Move²Event(const Move²Event&) = delete;
        Move²Event(Move²Event&&) = delete;
        Move²Event& operator=(const Move²Event&) = delete;
        Move²Event& operator=(Move²Event&&) = delete;
    };
}
