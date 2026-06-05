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
    class MaxSize²MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize²MEvent, SpatialEvent)
    public:
        MaxSize²MEvent(const Header&, const Size2M&);
    
        const Size2M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize²MEvent(const MaxSize²MEvent&, const Header&);
        MaxSize²MEvent(const Header&);
        ~MaxSize²MEvent();

    private:
        Size2M  m_size = ZERO;
        
        MaxSize²MEvent(const MaxSize²MEvent&) = delete;
        MaxSize²MEvent(MaxSize²MEvent&&) = delete;
        MaxSize²MEvent& operator=(const MaxSize²MEvent&) = delete;
        MaxSize²MEvent& operator=(MaxSize²MEvent&&) = delete;
    };
}
