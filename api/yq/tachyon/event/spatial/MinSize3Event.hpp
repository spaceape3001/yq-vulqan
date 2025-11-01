////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Source resized in 3-Dimensions
    class MinSize³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize³Event, SpatialEvent)
    public:
        MinSize³Event(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize³Event(const Header&);
        MinSize³Event(const MinSize³Event&, const Header&);
        ~MinSize³Event();

    private:
        Size3D  m_size = ZERO;
        
        MinSize³Event(const MinSize³Event&) = delete;
        MinSize³Event(MinSize³Event&&) = delete;
        MinSize³Event& operator=(const MinSize³Event&) = delete;
        MinSize³Event& operator=(MinSize³Event&&) = delete;
    };
}
