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
    class MinSize¹CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize¹CEvent, SpatialEvent)
    public:
        MinSize¹CEvent(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize¹CEvent(const Header&);
        MinSize¹CEvent(const MinSize¹CEvent&, const Header&);
        ~MinSize¹CEvent();

    private:
        Size1CM  m_size = ZERO;
        
        MinSize¹CEvent(const MinSize¹CEvent&) = delete;
        MinSize¹CEvent(MinSize¹CEvent&&) = delete;
        MinSize¹CEvent& operator=(const MinSize¹CEvent&) = delete;
        MinSize¹CEvent& operator=(MinSize¹CEvent&&) = delete;
    };
}
