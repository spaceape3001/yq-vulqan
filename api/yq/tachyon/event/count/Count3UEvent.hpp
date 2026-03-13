////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Source moved in 3-Dimensions
    class Count³UEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Count³UEvent, SpatialEvent)
    public:
        Count³UEvent(const Header&, const Vector3U&);
    
        const Vector3U&   count() const  { return m_count; }
        
        static void init_meta();
        
        Vector1U  x() const { return m_count.x; }
        Vector1U  y() const { return m_count.y; }
        Vector1U  z() const { return m_count.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Count³UEvent(const Header&);
        Count³UEvent(const Count³UEvent&, const Header&);
        ~Count³UEvent();

    private:
        Vector3U  m_count = ZERO;
        
        Count³UEvent(const Count³UEvent&) = delete;
        Count³UEvent(Count³UEvent&&) = delete;
        Count³UEvent& operator=(const Count³UEvent&) = delete;
        Count³UEvent& operator=(Count³UEvent&&) = delete;
    };
}
