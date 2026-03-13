////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PCount1.hpp>
#include <yq/tachyon/command/count/AddCount1UCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount1UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCount1UCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>

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
            mail(new SetCount¹UCommand({.target=object()}, v));
        }
    }

    void        PCount¹::count(set_k, x_k, unsigned x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountˣUCommand({.target=object()}, x));
        }
    }
    
    void        PCount¹::count(add_k, const Vector1U& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddCount¹UCommand({.target=object()}, Δ));
        }
    }

    void        PCount¹::count(add_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddCountˣUCommand({.target=object()}, Δx));
        }
    }

    void        PCount¹::count(multiply_k, unsigned Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountUCommand({.target=object()}, Δ));
        }
    }

    void        PCount¹::count(multiply_k, const Vector1U& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCount¹UCommand({.target=object()}, Δ));
        }
    }

    void        PCount¹::count(multiply_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountˣUCommand({.target=object()}, Δx));
        }
    }
}
