////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class Size¹MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size¹MEvent, SpatialEvent)
    public:
        Size¹MEvent(const Header&, const Size1M&);
    
        const Size1M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size¹MEvent(const Header&);
        Size¹MEvent(const Size¹MEvent&, const Header&);
        ~Size¹MEvent();

    private:
        Size1M  m_size = ZERO;
        
        Size¹MEvent(const Size¹MEvent&) = delete;
        Size¹MEvent(Size¹MEvent&&) = delete;
        Size¹MEvent& operator=(const Size¹MEvent&) = delete;
        Size¹MEvent& operator=(Size¹MEvent&&) = delete;
    };
}
