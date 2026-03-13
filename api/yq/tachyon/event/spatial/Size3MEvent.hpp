////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Source resized in 3-Dimensions
    class Size³MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size³MEvent, SpatialEvent)
    public:
        Size³MEvent(const Header&, const Size3M&);
    
        const Size3M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size³MEvent(const Header&);
        Size³MEvent(const Size³MEvent&, const Header&);
        ~Size³MEvent();

    private:
        Size3M  m_size = ZERO;
        
        Size³MEvent(const Size³MEvent&) = delete;
        Size³MEvent(Size³MEvent&&) = delete;
        Size³MEvent& operator=(const Size³MEvent&) = delete;
        Size³MEvent& operator=(Size³MEvent&&) = delete;
    };
}
