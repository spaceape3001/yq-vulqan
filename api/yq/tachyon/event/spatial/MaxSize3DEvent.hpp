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
    class MaxSize³DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize³DEvent, SpatialEvent)
    public:
        MaxSize³DEvent(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize³DEvent(const Header&);
        MaxSize³DEvent(const MaxSize³DEvent&, const Header&);
        ~MaxSize³DEvent();

    private:
        Size3D  m_size = ZERO;
        
        MaxSize³DEvent(const MaxSize³DEvent&) = delete;
        MaxSize³DEvent(MaxSize³DEvent&&) = delete;
        MaxSize³DEvent& operator=(const MaxSize³DEvent&) = delete;
        MaxSize³DEvent& operator=(MaxSize³DEvent&&) = delete;
    };
}
