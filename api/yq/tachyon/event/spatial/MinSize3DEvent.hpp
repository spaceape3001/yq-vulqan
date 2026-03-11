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
    class MinSize³DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize³DEvent, SpatialEvent)
    public:
        MinSize³DEvent(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize³DEvent(const Header&);
        MinSize³DEvent(const MinSize³DEvent&, const Header&);
        ~MinSize³DEvent();

    private:
        Size3D  m_size = ZERO;
        
        MinSize³DEvent(const MinSize³DEvent&) = delete;
        MinSize³DEvent(MinSize³DEvent&&) = delete;
        MinSize³DEvent& operator=(const MinSize³DEvent&) = delete;
        MinSize³DEvent& operator=(MinSize³DEvent&&) = delete;
    };
}
