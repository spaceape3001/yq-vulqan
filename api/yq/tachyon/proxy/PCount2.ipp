////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PCount2.hpp>
#include <yq/tachyon/command/count/AddCount2UCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/AddCountYUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount2UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYUCommand.hpp>
#include <yq/tachyon/command/count/SetCount2UCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCountYUCommand.hpp>

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

    PCount²::~PCount²() = default;

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
            mail(new SetCount²UCommand({.target=object()}, v));
        }
    }

    void        PCount²::count(set_k, x_k, unsigned x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountˣUCommand({.target=object()}, x));
        }
    }
    
    void        PCount²::count(set_k, y_k, unsigned y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountʸUCommand({.target=object()}, y));
        }
    }

    void        PCount²::count(add_k, const Vector2U& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCount²UCommand({.target=object()}, Δ));
        }
    }

    void        PCount²::count(add_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountˣUCommand({.target=object()}, Δx));
        }
    }

    void        PCount²::count(add_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountʸUCommand({.target=object()}, Δy));
        }
    }

    void        PCount²::count(multiply_k, unsigned Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountUCommand({.target=object()}, Δ));
        }
    }

    void        PCount²::count(multiply_k, const Vector2U& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCount²UCommand({.target=object()}, Δ));
        }
    }

    void        PCount²::count(multiply_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountˣUCommand({.target=object()}, Δx));
        }
    }

    void        PCount²::count(multiply_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountʸUCommand({.target=object()}, Δy));
        }
    }
}
