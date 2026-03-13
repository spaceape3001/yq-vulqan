////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PMaxSize2D.hpp"

#include <yq/tachyon/command/size/AddMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYDCommand.hpp>

namespace yq::tachyon {
    PMaxSize²D::PMaxSize²D(const IMaxSize²D& i) : m_max_size(i.max_size())
    {
        if(i.max_size(DISABLED))
            m_flags |= F::Disabled;
        if(i.max_size(SETTABLE))
            m_flags |= F::Settable;
        if(i.max_size(ADDABLE))
            m_flags |= F::Addable;
        if(i.max_size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PMaxSize²D::~PMaxSize²D()
    {
    }

    bool        PMaxSize²D::max_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMaxSize²D::max_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMaxSize²D::max_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMaxSize²D::max_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMaxSize²D::max_size(set_k, const Size2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSize²DCommand({.target=object()}, v));
        }
    }

    void        PMaxSize²D::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PMaxSize²D::max_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʸDCommand({.target=object()}, y));
        }
    }
    
    void        PMaxSize²D::max_size(add_k, const Size2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize²DCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize²D::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize²D::max_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PMaxSize²D::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeDCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize²D::max_size(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize²DCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize²D::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize²D::max_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʸDCommand({.target=object()}, Δy));
        }
    }
}
