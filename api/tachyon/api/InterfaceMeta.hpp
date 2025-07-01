////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/CompoundMeta.hpp>
#include <yq/meta/InfoBinder.hpp>
#include <yq/meta/MetaLookup.hpp>
#include <yq/typedef/string_initlists.hpp>

namespace yq::tachyon {
    class Proxy;
    class Tachyon;
    
    class InterfaceMeta : public CompoundMeta {
        using MethodLUC     = MetaLookup<MethodInfo>;
        using PropertyLUC   = MetaLookup<PropertyInfo>;
    public:

        //! Helper for registering type information
        template <typename T> class Writer;
        template <typename T> class Fixer;
    
        /*! \brief Returns all current interface infos
            \note WARNING Unsafe in unlocked multithreaded mode (as this isn't a copy, 
                    its the actual list that could be changing.)
        */
        static const std::vector<const InterfaceMeta*>&   all();

        //! Finds the type info by ID
        static const InterfaceMeta*     find(id_t);

        //! Finds the type info by name
        static const InterfaceMeta*     find(std::string_view);

        //! The "generic" classification for this meta which is type.
        virtual const char*     generic() const override { return "Interface"; }

        //! List of methods for this type
        const std::vector<const MethodInfo*>&   methods() const;
        
        size_t      methods(count_k) const;


        const PropertyInfo*                 property(std::string_view) const;
        
        size_t      properties(count_k) const;

        //! List of properties for this type
        const std::vector<const PropertyInfo*>&  properties() const;

        PropertyLUC::equal_range_t              properties(std::string_view) const;

        
        //! Proxies the tachyon... note, if the interface is unavailable, this will return NULL
        virtual Proxy*      proxy(Tachyon*) const = 0;

        //! Returns the interface from the proxy, if possible (needed for properties)
        virtual const void* interface(const Proxy*) const = 0;
        
    protected:
        InterfaceMeta(std::string_view zName, const std::source_location& sl);
        
        virtual ~InterfaceMeta();
        
        //! Sweeps on the type (ie gathers properties/methdos)
        virtual void    sweep_impl() override;

    private:
        
        struct Repo;
        static Repo&    repo();
        
        //! Method for this type
        MethodLUC                   m_methods;

        //! Properties for this type
        PropertyLUC                 m_properties;
    };
}
