////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PMaxSize1.hpp>
#include <yq/tachyon/command/size/AddMaxSize1Command.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize1Command.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize1Command.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXCommand.hpp>

namespace yq::tachyon {
    PMaxSize¹::PMaxSize¹(const IMaxSize¹& i) : m_max_size(i.max_size())
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

    PMaxSize¹::~PMaxSize¹()
    {
    }

    bool        PMaxSize¹::max_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMaxSize¹::max_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMaxSize¹::max_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMaxSize¹::max_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMaxSize¹::max_size(set_k, const Size1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSize¹Command({.target=object()}, v));
        }
    }

    void        PMaxSize¹::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣCommand({.target=object()}, x));
        }
    }
    
    void        PMaxSize¹::max_size(add_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize¹Command({.target=object()}, Δ));
        }
    }

    void        PMaxSize¹::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize¹::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize({.target=object()}, Δ));
        }
    }

    void        PMaxSize¹::max_size(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize¹Command({.target=object()}, Δ));
        }
    }

    void        PMaxSize¹::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣCommand({.target=object()}, Δx));
        }
    }
}
