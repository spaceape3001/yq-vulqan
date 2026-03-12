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
    class MaxSize³MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize³MEvent, SpatialEvent)
    public:
        MaxSize³MEvent(const Header&, const Size3M&);
    
        const Size3M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize³MEvent(const Header&);
        MaxSize³MEvent(const MaxSize³MEvent&, const Header&);
        ~MaxSize³MEvent();

    private:
        Size3M  m_size = ZERO;
        
        MaxSize³MEvent(const MaxSize³MEvent&) = delete;
        MaxSize³MEvent(MaxSize³MEvent&&) = delete;
        MaxSize³MEvent& operator=(const MaxSize³MEvent&) = delete;
        MaxSize³MEvent& operator=(MaxSize³MEvent&&) = delete;
    };
}
