////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class MaxSize¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize¹Event, SpatialEvent)
    public:
        MaxSize¹Event(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize¹Event(const Header&);
        MaxSize¹Event(const MaxSize¹Event&, const Header&);
        ~MaxSize¹Event();

    private:
        Size1D  m_size = ZERO;
        
        MaxSize¹Event(const MaxSize¹Event&) = delete;
        MaxSize¹Event(MaxSize¹Event&&) = delete;
        MaxSize¹Event& operator=(const MaxSize¹Event&) = delete;
        MaxSize¹Event& operator=(MaxSize¹Event&&) = delete;
    };
}
