////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PSize2.hpp>
#include <yq/tachyon/command/size/AddSize2Command.hpp>
#include <yq/tachyon/command/size/AddSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize2Command.hpp>
#include <yq/tachyon/command/size/MultiplySizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYCommand.hpp>
#include <yq/tachyon/command/size/SetSize2Command.hpp>
#include <yq/tachyon/command/size/SetSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYCommand.hpp>

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
            mail(new SetSize²Command({.target=object()}, v));
        }
    }

    void        PSize²::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣCommand({.target=object()}, x));
        }
    }
    
    void        PSize²::size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʸCommand({.target=object()}, y));
        }
    }
    
    void        PSize²::size(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize²Command({.target=object()}, Δ));
        }
    }

    void        PSize²::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PSize²::size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PSize²::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize({.target=object()}, Δ));
        }
    }

    void        PSize²::size(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize²Command({.target=object()}, Δ));
        }
    }

    void        PSize²::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PSize²::size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʸCommand({.target=object()}, Δy));
        }
    }
}
