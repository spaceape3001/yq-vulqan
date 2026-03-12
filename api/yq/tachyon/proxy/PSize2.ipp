////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PSize2.hpp>
#include <yq/tachyon/command/size/AddSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYDCommand.hpp>

namespace yq::tachyon {
    PSize²::PSize²(const ISize²& i) : m_size(i.size())
    {
        if(i.size(DISABLED))
            m_flags |= F::Disabled;
        if(i.size(SETTABLE))
            m_flags |= F::Settable;
        if(i.size(ADDABLE))
            m_flags |= F::Addable;
        if(i.size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PSize²::~PSize²()
    {
    }

    bool        PSize²::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize²::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize²::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize²::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize²::size(set_k, const Size2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize²DCommand({.target=object()}, v));
        }
    }

    void        PSize²::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PSize²::size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʸDCommand({.target=object()}, y));
        }
    }
    
    void        PSize²::size(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize²DCommand({.target=object()}, Δ));
        }
    }

    void        PSize²::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PSize²::size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PSize²::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeDCommand({.target=object()}, Δ));
        }
    }

    void        PSize²::size(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize²DCommand({.target=object()}, Δ));
        }
    }

    void        PSize²::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PSize²::size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʸDCommand({.target=object()}, Δy));
        }
    }
}
