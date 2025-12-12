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
    class Count³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Count³Event, SpatialEvent)
    public:
        Count³Event(const Header&, const Vector3U&);
    
        const Vector3U&   count() const  { return m_count; }
        
        static void init_meta();
        
        Vector1U  x() const { return m_count.x; }
        Vector1U  y() const { return m_count.y; }
        Vector1U  z() const { return m_count.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Count³Event(const Header&);
        Count³Event(const Count³Event&, const Header&);
        ~Count³Event();

    private:
        Vector3U  m_count = ZERO;
        
        Count³Event(const Count³Event&) = delete;
        Count³Event(Count³Event&&) = delete;
        Count³Event& operator=(const Count³Event&) = delete;
        Count³Event& operator=(Count³Event&&) = delete;
    };
}
