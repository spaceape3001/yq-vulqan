////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PCount1.hpp>
#include <yq/tachyon/command/count/AddCount1Command.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount1Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCount1Command.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>

namespace yq::tachyon {
    PCount¹::PCount¹(const ICount¹& i)
    {
        if(i.count(DISABLED))
            m_flags |= F::Disabled;
        if(i.count(SETTABLE))
            m_flags |= F::Settable;
        if(i.count(ADDABLE))
            m_flags |= F::Addable;
        if(i.count(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    bool        PCount¹::count(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PCount¹::count(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PCount¹::count(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PCount¹::count(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    void        PCount¹::count(set_k, const Vector1U& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCount¹Command({.target=object()}, v));
        }
    }

    void        PCount¹::count(set_k, x_k, unsigned x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountˣCommand({.target=object()}, x));
        }
    }
    
    void        PCount¹::count(add_k, const Vector1U& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddCount¹Command({.target=object()}, Δ));
        }
    }

    void        PCount¹::count(add_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddCountˣCommand({.target=object()}, Δx));
        }
    }

    void        PCount¹::count(multiply_k, unsigned Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountCommand({.target=object()}, Δ));
        }
    }

    void        PCount¹::count(multiply_k, const Vector1U& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCount¹Command({.target=object()}, Δ));
        }
    }

    void        PCount¹::count(multiply_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountˣCommand({.target=object()}, Δx));
        }
    }
}
