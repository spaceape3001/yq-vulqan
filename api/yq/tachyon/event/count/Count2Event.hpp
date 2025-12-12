////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Source moved in 2-Dimensions
    class Count²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Count²Event, SpatialEvent)
    public:
        Count²Event(const Header&, const Vector2U&);
    
        const Vector2U&   count() const  { return m_count; }
        
        static void init_meta();
        
        Vector1U  x() const { return m_count.x; }
        Vector1U  y() const { return m_count.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Count²Event(const Header&);
        Count²Event(const Count²Event&, const Header&);
        ~Count²Event();

    private:
        Vector2U  m_count = ZERO;
        
        Count²Event(const Count²Event&) = delete;
        Count²Event(Count²Event&&) = delete;
        Count²Event& operator=(const Count²Event&) = delete;
        Count²Event& operator=(Count²Event&&) = delete;
    };
}
