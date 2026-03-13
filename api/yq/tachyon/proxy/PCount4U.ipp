////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PCount4U.hpp>
#include <yq/tachyon/command/count/AddCount4UCommand.hpp>
#include <yq/tachyon/command/count/AddCountWUCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/AddCountYUCommand.hpp>
#include <yq/tachyon/command/count/AddCountZUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount4UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountWUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZUCommand.hpp>
#include <yq/tachyon/command/count/SetCount4UCommand.hpp>
#include <yq/tachyon/command/count/SetCountWUCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCountYUCommand.hpp>
#include <yq/tachyon/command/count/SetCountZUCommand.hpp>

namespace yq::tachyon {
    PCount⁴U::PCount⁴U(const ICount⁴U& i) : m_count(i.count())
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

    PCount⁴U::~PCount⁴U()
    {
    }

    bool        PCount⁴U::count(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PCount⁴U::count(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PCount⁴U::count(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PCount⁴U::count(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PCount⁴U::count(set_k, const Vector4U& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCount⁴UCommand({.target=object()}, v));
        }
    }

    void        PCount⁴U::count(set_k, w_k, unsigned w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountʷUCommand({.target=object()}, w));
        }
    }
    
    void        PCount⁴U::count(set_k, x_k, unsigned x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountˣUCommand({.target=object()}, x));
        }
    }
    
    void        PCount⁴U::count(set_k, y_k, unsigned y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountʸUCommand({.target=object()}, y));
        }
    }
    
    void        PCount⁴U::count(set_k, z_k, unsigned z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountᶻUCommand({.target=object()}, z));
        }
    }

    void        PCount⁴U::count(add_k, const Vector4U& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCount⁴UCommand({.target=object()}, Δ));
        }
    }

    void        PCount⁴U::count(add_k, w_k, unsigned Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountʷUCommand({.target=object()}, Δw));
        }
    }

    void        PCount⁴U::count(add_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountˣUCommand({.target=object()}, Δx));
        }
    }

    void        PCount⁴U::count(add_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountʸUCommand({.target=object()}, Δy));
        }
    }

    void        PCount⁴U::count(add_k, z_k, unsigned Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountᶻUCommand({.target=object()}, Δz));
        }
    }

    void        PCount⁴U::count(multiply_k, unsigned Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountUCommand({.target=object()}, Δ));
        }
    }

    void        PCount⁴U::count(multiply_k, const Vector4U& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCount⁴UCommand({.target=object()}, Δ));
        }
    }

    void        PCount⁴U::count(multiply_k, w_k, unsigned Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountʷUCommand({.target=object()}, Δw));
        }
    }

    void        PCount⁴U::count(multiply_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountˣUCommand({.target=object()}, Δx));
        }
    }

    void        PCount⁴U::count(multiply_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountʸUCommand({.target=object()}, Δy));
        }
    }

    void        PCount⁴U::count(multiply_k, z_k, unsigned Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountᶻUCommand({.target=object()}, Δz));
        }
    }
}
