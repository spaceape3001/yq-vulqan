////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class MinSize¹CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize¹CMEvent, SpatialEvent)
    public:
        MinSize¹CMEvent(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize¹CMEvent(const Header&);
        MinSize¹CMEvent(const MinSize¹CMEvent&, const Header&);
        ~MinSize¹CMEvent();

    private:
        Size1CM  m_size = ZERO;
        
        MinSize¹CMEvent(const MinSize¹CMEvent&) = delete;
        MinSize¹CMEvent(MinSize¹CMEvent&&) = delete;
        MinSize¹CMEvent& operator=(const MinSize¹CMEvent&) = delete;
        MinSize¹CMEvent& operator=(MinSize¹CMEvent&&) = delete;
    };
}
