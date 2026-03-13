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
    class MinSize²MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize²MEvent, SpatialEvent)
    public:
        MinSize²MEvent(const Header&, const Size2M&);
    
        const Size2M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize²MEvent(const MinSize²MEvent&, const Header&);
        MinSize²MEvent(const Header&);
        ~MinSize²MEvent();

    private:
        Size2M  m_size = ZERO;
        
        MinSize²MEvent(const MinSize²MEvent&) = delete;
        MinSize²MEvent(MinSize²MEvent&&) = delete;
        MinSize²MEvent& operator=(const MinSize²MEvent&) = delete;
        MinSize²MEvent& operator=(MinSize²MEvent&&) = delete;
    };
}
