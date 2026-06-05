////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Source resized in 2-Dimensions
    class Size²MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size²MEvent, SpatialEvent)
    public:
        Size²MEvent(const Header&, const Size2M&);
    
        const Size2M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size²MEvent(const Size²MEvent&, const Header&);
        Size²MEvent(const Header&);
        ~Size²MEvent();

    private:
        Size2M  m_size = ZERO;
        
        Size²MEvent(const Size²MEvent&) = delete;
        Size²MEvent(Size²MEvent&&) = delete;
        Size²MEvent& operator=(const Size²MEvent&) = delete;
        Size²MEvent& operator=(Size²MEvent&&) = delete;
    };
}
