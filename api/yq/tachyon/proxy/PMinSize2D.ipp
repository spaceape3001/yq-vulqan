////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PMinSize2D.hpp"

#include <yq/tachyon/command/size/AddMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYDCommand.hpp>

namespace yq::tachyon {
    PMinSize²D::PMinSize²D(const IMinSize²D& i) : m_min_size(i.min_size())
    {
        if(i.min_size(DISABLED))
            m_flags |= F::Disabled;
        if(i.min_size(SETTABLE))
            m_flags |= F::Settable;
        if(i.min_size(ADDABLE))
            m_flags |= F::Addable;
        if(i.min_size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PMinSize²D::~PMinSize²D()
    {
    }

    bool        PMinSize²D::min_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMinSize²D::min_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMinSize²D::min_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMinSize²D::min_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMinSize²D::min_size(set_k, const Size2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSize²DCommand({.target=object()}, v));
        }
    }

    void        PMinSize²D::min_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PMinSize²D::min_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeʸDCommand({.target=object()}, y));
        }
    }
    
    void        PMinSize²D::min_size(add_k, const Size2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSize²DCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize²D::min_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize²D::min_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PMinSize²D::min_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeDCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize²D::min_size(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize²DCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize²D::min_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize²D::min_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeʸDCommand({.target=object()}, Δy));
        }
    }
}
