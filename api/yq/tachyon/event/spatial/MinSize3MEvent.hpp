////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Source resized in 3-Dimensions
    class MinSize³MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize³MEvent, SpatialEvent)
    public:
        MinSize³MEvent(const Header&, const Size3M&);
    
        const Size3M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize³MEvent(const Header&);
        MinSize³MEvent(const MinSize³MEvent&, const Header&);
        ~MinSize³MEvent();

    private:
        Size3M  m_size = ZERO;
        
        MinSize³MEvent(const MinSize³MEvent&) = delete;
        MinSize³MEvent(MinSize³MEvent&&) = delete;
        MinSize³MEvent& operator=(const MinSize³MEvent&) = delete;
        MinSize³MEvent& operator=(MinSize³MEvent&&) = delete;
    };
}
