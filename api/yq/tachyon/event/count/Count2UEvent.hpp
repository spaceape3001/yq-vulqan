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
    class Count²UEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Count²UEvent, SpatialEvent)
    public:
        Count²UEvent(const Header&, const Vector2U&);
    
        const Vector2U&   count() const  { return m_count; }
        
        static void init_meta();
        
        Vector1U  x() const { return m_count.x; }
        Vector1U  y() const { return m_count.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Count²UEvent(const Header&);
        Count²UEvent(const Count²UEvent&, const Header&);
        ~Count²UEvent();

    private:
        Vector2U  m_count = ZERO;
        
        Count²UEvent(const Count²UEvent&) = delete;
        Count²UEvent(Count²UEvent&&) = delete;
        Count²UEvent& operator=(const Count²UEvent&) = delete;
        Count²UEvent& operator=(Count²UEvent&&) = delete;
    };
}
