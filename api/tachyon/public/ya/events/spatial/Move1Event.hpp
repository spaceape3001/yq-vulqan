////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Source moved in 1-Dimension
    class Move¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Move¹Event, SpatialEvent)
    public:
        Move¹Event(const Header&, const Vector1D&);
    
        const Vector1D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Move¹Event(const Move¹Event&, const Header&);
        ~Move¹Event();

    private:
        Vector1D const  m_position;
        
        Move¹Event(const Move¹Event&) = delete;
        Move¹Event(Move¹Event&&) = delete;
        Move¹Event& operator=(const Move¹Event&) = delete;
        Move¹Event& operator=(Move¹Event&&) = delete;
    };
}
