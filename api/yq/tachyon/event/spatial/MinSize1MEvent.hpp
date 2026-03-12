////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class MinSize¹MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize¹MEvent, SpatialEvent)
    public:
        MinSize¹MEvent(const Header&, const Size1M&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize¹MEvent(const Header&);
        MinSize¹MEvent(const MinSize¹MEvent&, const Header&);
        ~MinSize¹MEvent();

    private:
        Size1M  m_size = ZERO;
        
        MinSize¹MEvent(const MinSize¹MEvent&) = delete;
        MinSize¹MEvent(MinSize¹MEvent&&) = delete;
        MinSize¹MEvent& operator=(const MinSize¹MEvent&) = delete;
        MinSize¹MEvent& operator=(MinSize¹MEvent&&) = delete;
    };
}
