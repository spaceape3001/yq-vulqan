////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class MinSize¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize¹Event, SpatialEvent)
    public:
        MinSize¹Event(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize¹Event(const Header&);
        MinSize¹Event(const MinSize¹Event&, const Header&);
        ~MinSize¹Event();

    private:
        Size1D  m_size = ZERO;
        
        MinSize¹Event(const MinSize¹Event&) = delete;
        MinSize¹Event(MinSize¹Event&&) = delete;
        MinSize¹Event& operator=(const MinSize¹Event&) = delete;
        MinSize¹Event& operator=(MinSize¹Event&&) = delete;
    };
}
