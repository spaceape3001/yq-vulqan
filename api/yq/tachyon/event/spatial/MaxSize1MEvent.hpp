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
    class MaxSize¹MEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize¹MEvent, SpatialEvent)
    public:
        MaxSize¹MEvent(const Header&, const Size1M&);
    
        const Size1M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize¹MEvent(const Header&);
        MaxSize¹MEvent(const MaxSize¹MEvent&, const Header&);
        ~MaxSize¹MEvent();

    private:
        Size1M  m_size = ZERO;
        
        MaxSize¹MEvent(const MaxSize¹MEvent&) = delete;
        MaxSize¹MEvent(MaxSize¹MEvent&&) = delete;
        MaxSize¹MEvent& operator=(const MaxSize¹MEvent&) = delete;
        MaxSize¹MEvent& operator=(MaxSize¹MEvent&&) = delete;
    };
}
