////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PCount3U.hpp>
#include <yq/tachyon/command/count/AddCount3UCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/AddCountYUCommand.hpp>
#include <yq/tachyon/command/count/AddCountZUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount3UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZUCommand.hpp>
#include <yq/tachyon/command/count/SetCount3UCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCountYUCommand.hpp>
#include <yq/tachyon/command/count/SetCountZUCommand.hpp>

namespace yq::tachyon {
    PCount³U::PCount³U(const ICount³U& i) : m_count(i.count())
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

    PCount³U::~PCount³U()
    {
    }

    bool        PCount³U::count(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PCount³U::count(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PCount³U::count(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PCount³U::count(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PCount³U::count(set_k, const Vector3U& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCount³UCommand({.target=object()}, v));
        }
    }

    void        PCount³U::count(set_k, x_k, unsigned x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountˣUCommand({.target=object()}, x));
        }
    }
    
    void        PCount³U::count(set_k, y_k, unsigned y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountʸUCommand({.target=object()}, y));
        }
    }
    
    void        PCount³U::count(set_k, z_k, unsigned z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountᶻUCommand({.target=object()}, z));
        }
    }

    void        PCount³U::count(add_k, const Vector3U& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCount³UCommand({.target=object()}, Δ));
        }
    }

    void        PCount³U::count(add_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountˣUCommand({.target=object()}, Δx));
        }
    }

    void        PCount³U::count(add_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountʸUCommand({.target=object()}, Δy));
        }
    }

    void        PCount³U::count(add_k, z_k, unsigned Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountᶻUCommand({.target=object()}, Δz));
        }
    }

    void        PCount³U::count(multiply_k, unsigned Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountUCommand({.target=object()}, Δ));
        }
    }

    void        PCount³U::count(multiply_k, const Vector3U& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCount³UCommand({.target=object()}, Δ));
        }
    }

    void        PCount³U::count(multiply_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountˣUCommand({.target=object()}, Δx));
        }
    }

    void        PCount³U::count(multiply_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountʸUCommand({.target=object()}, Δy));
        }
    }

    void        PCount³U::count(multiply_k, z_k, unsigned Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountᶻUCommand({.target=object()}, Δz));
        }
    }
}
