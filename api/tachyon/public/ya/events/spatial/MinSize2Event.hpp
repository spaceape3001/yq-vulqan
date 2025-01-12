////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Source resized in 2-Dimensions
    class MinSize²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize²Event, SpatialEvent)
    public:
        MinSize²Event(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize²Event(const MinSize²Event&, const Header&);
        MinSize²Event(const Header&);
        ~MinSize²Event();

    private:
        Size2D  m_size = ZERO;
        
        MinSize²Event(const MinSize²Event&) = delete;
        MinSize²Event(MinSize²Event&&) = delete;
        MinSize²Event& operator=(const MinSize²Event&) = delete;
        MinSize²Event& operator=(MinSize²Event&&) = delete;
    };
}
