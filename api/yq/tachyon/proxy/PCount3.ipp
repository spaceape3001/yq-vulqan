////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PCount3.hpp>
#include <yq/tachyon/command/count/AddCount3Command.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/AddCountYCommand.hpp>
#include <yq/tachyon/command/count/AddCountZCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount3Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZCommand.hpp>
#include <yq/tachyon/command/count/SetCount3Command.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCountYCommand.hpp>
#include <yq/tachyon/command/count/SetCountZCommand.hpp>

namespace yq::tachyon {
    PCount³::PCount³(const ICount³& i) : m_count(i.count())
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

    PCount³::~PCount³()
    {
    }

    bool        PCount³::count(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PCount³::count(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PCount³::count(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PCount³::count(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PCount³::count(set_k, const Vector3U& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCount³Command({.target=object()}, v));
        }
    }

    void        PCount³::count(set_k, x_k, unsigned x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountˣCommand({.target=object()}, x));
        }
    }
    
    void        PCount³::count(set_k, y_k, unsigned y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountʸCommand({.target=object()}, y));
        }
    }
    
    void        PCount³::count(set_k, z_k, unsigned z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetCountᶻCommand({.target=object()}, z));
        }
    }

    void        PCount³::count(add_k, const Vector3U& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCount³Command({.target=object()}, Δ));
        }
    }

    void        PCount³::count(add_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountˣCommand({.target=object()}, Δx));
        }
    }

    void        PCount³::count(add_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountʸCommand({.target=object()}, Δy));
        }
    }

    void        PCount³::count(add_k, z_k, unsigned Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddCountᶻCommand({.target=object()}, Δz));
        }
    }

    void        PCount³::count(multiply_k, unsigned Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountCommand({.target=object()}, Δ));
        }
    }

    void        PCount³::count(multiply_k, const Vector3U& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCount³Command({.target=object()}, Δ));
        }
    }

    void        PCount³::count(multiply_k, x_k, unsigned Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountˣCommand({.target=object()}, Δx));
        }
    }

    void        PCount³::count(multiply_k, y_k, unsigned Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountʸCommand({.target=object()}, Δy));
        }
    }

    void        PCount³::count(multiply_k, z_k, unsigned Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyCountᶻCommand({.target=object()}, Δz));
        }
    }
}
