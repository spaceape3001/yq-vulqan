////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PCount2.hpp>
#include <yq/tachyon/command/count/AddCount2Command.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/AddCountYCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount2Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYCommand.hpp>
#include <yq/tachyon/command/count/SetCount2Command.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCountYCommand.hpp>

namespace yq::tachyon {
    PCount²::PCount²(const ICount²& i) : m_count(i.count())
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

    bool        PCount²::count(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }

    bool        PCount²::count(settable_k) const 
    {
        return m_flags(F::Settable);
    }
    
    bool        PCount²::count(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PCount²::count(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PCount²::count(set_k, const Vector2U& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCount²Command({.target=object()}, v));
        }
    }

    void        PCount²::count(set_k, x_k, unsigned x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountˣCommand({.target=object()}, x));
        }
    }
    
    void        PCount²::count(set_k, y_k, unsigned y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountʸCommand({.target=object()}, y));
        }
    }

    void        PCount²::count(add_k, const Vector2U& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCount²Command({.target=object()}, Δ));
        }
    }

    void        PCount²::count(add_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountˣCommand({.target=object()}, Δx));
        }
    }

    void        PCount²::count(add_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountʸCommand({.target=object()}, Δy));
        }
    }

    void        PCount²::count(multiply_k, unsigned Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountCommand({.target=object()}, Δ));
        }
    }

    void        PCount²::count(multiply_k, const Vector2U& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCount²Command({.target=object()}, Δ));
        }
    }

    void        PCount²::count(multiply_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountˣCommand({.target=object()}, Δx));
        }
    }

    void        PCount²::count(multiply_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountʸCommand({.target=object()}, Δy));
        }
    }
}
