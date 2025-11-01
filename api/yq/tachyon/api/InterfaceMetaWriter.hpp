////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/CompoundMetaDynamic.hpp>
#include <yq/tachyon/api/InterfaceMeta.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/core/DelayInit.hpp>
#include <type_traits>

namespace yq::tachyon {
    template <typename C>
    class InterfaceMeta::Writer : public CompoundMeta::Dynamic<C> {
    public:
    
        Writer&     abstract()
        {
            if(Meta::Writer::m_meta)
                Meta::Writer::m_meta -> set(Flag::ABSTRACT);
            return *this;
        }
        
        Writer(InterfaceMeta* obj) : CompoundMeta::Dynamic<C>(obj) 
        {
            assert(obj);
            if constexpr ( std::is_abstract_v<C> ){
                Meta::Writer::m_meta -> set(Flag::ABSTRACT);
            }
            
        }
        
        Writer(InterfaceMeta& obj) : Writer(&obj)
        {
        }
    };
    
    template <class I>
    struct InterfaceFixer : public InterfaceMeta, public DelayInit {
        
        static_assert(I::IsInterface, "Must be interface declared!");
    
        InterfaceFixer(std::string_view szName, std::source_location sl=std::source_location::current()) :
            InterfaceMeta(szName, sl)
        {
            if constexpr ( std::is_abstract_v<I> ){
                Meta::set(Meta::Flag::ABSTRACT);
            }
        }

        virtual Proxy*      proxy(Tachyon*tac) const override
        {
            if(!tac)
                return nullptr;
            I*  i   = dynamic_cast<I*>(tac);
            if(!i)
                return nullptr;
                
            return new typename I::MyProxy(*i);
        }

        virtual const void* interface(const Proxy* p) const override
        {
            return dynamic_cast<const I*>(p);
        }

        static DelayInit::Ctor  s_reg;
    };
}
