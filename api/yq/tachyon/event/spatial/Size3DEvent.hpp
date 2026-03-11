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
    class Size³DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size³DEvent, SpatialEvent)
    public:
        Size³DEvent(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size³DEvent(const Header&);
        Size³DEvent(const Size³DEvent&, const Header&);
        ~Size³DEvent();

    private:
        Size3D  m_size = ZERO;
        
        Size³DEvent(const Size³DEvent&) = delete;
        Size³DEvent(Size³DEvent&&) = delete;
        Size³DEvent& operator=(const Size³DEvent&) = delete;
        Size³DEvent& operator=(Size³DEvent&&) = delete;
    };
}
