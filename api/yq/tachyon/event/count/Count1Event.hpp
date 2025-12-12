////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Source moved in 1-Dimension
    class Count¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Count¹Event, SpatialEvent)
    public:
        Count¹Event(const Header&, const Vector1U&);
    
        const Vector1U&   count() const  { return m_count; }
        
        static void init_meta();
        
        Vector1U  x() const { return m_count.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Count¹Event(const Header&);
        Count¹Event(const Count¹Event&, const Header&);
        ~Count¹Event();

    private:
        Vector1U   m_count = ZERO;
        
        Count¹Event(const Count¹Event&) = delete;
        Count¹Event(Count¹Event&&) = delete;
        Count¹Event& operator=(const Count¹Event&) = delete;
        Count¹Event& operator=(Count¹Event&&) = delete;
    };
}
