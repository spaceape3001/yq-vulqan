////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Source resized in 2-Dimensions
    class MinSize²DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize²DEvent, SpatialEvent)
    public:
        MinSize²DEvent(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize²DEvent(const MinSize²DEvent&, const Header&);
        MinSize²DEvent(const Header&);
        ~MinSize²DEvent();

    private:
        Size2D  m_size = ZERO;
        
        MinSize²DEvent(const MinSize²DEvent&) = delete;
        MinSize²DEvent(MinSize²DEvent&&) = delete;
        MinSize²DEvent& operator=(const MinSize²DEvent&) = delete;
        MinSize²DEvent& operator=(MinSize²DEvent&&) = delete;
    };
}
