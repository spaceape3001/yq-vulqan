////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/api/Interface.hpp>
#include <yt/api/InterfaceInfo.hpp>
#include <yt/api/InterfaceInfoWriter.hpp>

namespace yq::tachyon {
    struct InterfaceInfo::Repo {
        MetaLookup<InterfaceInfo>   interfaces;
    };
    
    InterfaceInfo::Repo&    InterfaceInfo::repo()
    {
        static Repo    s_repo;
        return s_repo;
    }
    
    const std::vector<const InterfaceInfo*>&   InterfaceInfo::all()
    {
        return repo().interfaces.all;
    }

    const InterfaceInfo*     InterfaceInfo::find(id_t i)
    {
        const Meta* m   = lookup(i);
        if(m && m->is_interface())
            return static_cast<const InterfaceInfo*>(m);
        return nullptr;
    }
    
    const InterfaceInfo*     InterfaceInfo::find(std::string_view k)
    {
        return repo().interfaces.find(k);
    }


    //  ------------------------------------------------------------------------------------------------------------

    InterfaceInfo::InterfaceInfo(std::string_view zName, const std::source_location& sl) : CompoundInfo(zName, sl)
    {
        set(Flag::INTERFACE);
        repo().interfaces << this;
    }
        
    InterfaceInfo::~InterfaceInfo()
    {
    }
    
    const std::vector<const MethodInfo*>&   InterfaceInfo::methods() const
    {
        return m_methods.all;
    }
    
    size_t      InterfaceInfo::methods(count_k) const
    {
        return m_methods.all.size();
    }


    const PropertyInfo*                 InterfaceInfo::property(std::string_view k) const
    {
        return m_properties.find(k);
    }
    
    size_t      InterfaceInfo::properties(count_k) const
    {
        return m_properties.all.size();
    }
    

    const std::vector<const PropertyInfo*>&  InterfaceInfo::properties() const
    {
        return m_properties.all;
    }

    InterfaceInfo::PropertyLUC::equal_range_t              InterfaceInfo::properties(std::string_view k) const
    {
        return m_properties.lut.equal_range(k);
    }

    void    InterfaceInfo::sweep_impl() 
    {
        CompoundInfo::sweep_impl();
        gather(m_properties);
        gather(m_methods);
    }
}
