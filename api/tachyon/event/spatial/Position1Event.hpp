////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Source moved in 1-Dimension
    class Position¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Position¹Event, SpatialEvent)
    public:
        Position¹Event(const Header&, const Vector1D&);
    
        const Vector1D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Position¹Event(const Header&);
        Position¹Event(const Position¹Event&, const Header&);
        ~Position¹Event();

    private:
        Vector1D   m_position = ZERO;
        
        Position¹Event(const Position¹Event&) = delete;
        Position¹Event(Position¹Event&&) = delete;
        Position¹Event& operator=(const Position¹Event&) = delete;
        Position¹Event& operator=(Position¹Event&&) = delete;
    };
}
