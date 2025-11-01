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
    class MaxSize²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize²Event, SpatialEvent)
    public:
        MaxSize²Event(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize²Event(const MaxSize²Event&, const Header&);
        MaxSize²Event(const Header&);
        ~MaxSize²Event();

    private:
        Size2D  m_size = ZERO;
        
        MaxSize²Event(const MaxSize²Event&) = delete;
        MaxSize²Event(MaxSize²Event&&) = delete;
        MaxSize²Event& operator=(const MaxSize²Event&) = delete;
        MaxSize²Event& operator=(MaxSize²Event&&) = delete;
    };
}
