////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/api/InterfaceMeta.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>

namespace yq::tachyon {
    struct InterfaceMeta::Repo {
        MetaLookup<InterfaceMeta>   interfaces;
    };
    
    InterfaceMeta::Repo&    InterfaceMeta::repo()
    {
        static Repo    s_repo;
        return s_repo;
    }
    
    const std::vector<const InterfaceMeta*>&   InterfaceMeta::all()
    {
        return repo().interfaces.all;
    }

    const InterfaceMeta*     InterfaceMeta::find(id_t i)
    {
        const Meta* m   = lookup(i);
        if(m && m->is_interface())
            return static_cast<const InterfaceMeta*>(m);
        return nullptr;
    }
    
    const InterfaceMeta*     InterfaceMeta::find(std::string_view k)
    {
        return repo().interfaces.find(k);
    }


    //  ------------------------------------------------------------------------------------------------------------

    InterfaceMeta::InterfaceMeta(std::string_view zName, const std::source_location& sl) : CompoundMeta(zName, sl)
    {
        set(Flag::INTERFACE);
        repo().interfaces << this;
    }
        
    InterfaceMeta::~InterfaceMeta()
    {
    }
    
    const std::vector<const MethodMeta*>&   InterfaceMeta::methods() const
    {
        return m_methods.all;
    }
    
    size_t      InterfaceMeta::methods(count_k) const
    {
        return m_methods.all.size();
    }


    const PropertyMeta*                 InterfaceMeta::property(std::string_view k) const
    {
        return m_properties.find(k);
    }
    
    size_t      InterfaceMeta::properties(count_k) const
    {
        return m_properties.all.size();
    }
    

    const std::vector<const PropertyMeta*>&  InterfaceMeta::properties() const
    {
        return m_properties.all;
    }

    InterfaceMeta::PropertyLUC::equal_range_t              InterfaceMeta::properties(std::string_view k) const
    {
        return m_properties.lut.equal_range(k);
    }

    void    InterfaceMeta::sweep_impl() 
    {
        CompoundMeta::sweep_impl();
        gather(m_properties);
        gather(m_methods);
    }
}
