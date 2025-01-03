////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/CompoundInfoDynamic.hpp>
#include <yt/api/InterfaceInfo.hpp>
#include <yt/api/Tachyon.hpp>
#include <yq/core/DelayInit.hpp>
#include <type_traits>

namespace yq::tachyon {
    template <typename C>
    class InterfaceInfo::Writer : public CompoundInfo::Dynamic<C> {
    public:
    
        Writer&     abstract()
        {
            if(Meta::Writer::m_meta)
                Meta::Writer::m_meta -> set(Flag::ABSTRACT);
            return *this;
        }
        
        Writer(InterfaceInfo* obj) : CompoundInfo::Dynamic<C>(obj) 
        {
            assert(obj);
            if constexpr ( std::is_abstract_v<C> ){
                Meta::Writer::m_meta -> set(Flag::ABSTRACT);
            }
            
        }
        
        Writer(InterfaceInfo& obj) : Writer(&obj)
        {
        }
    };
    
    template <class I>
    struct InterfaceFixer : public InterfaceInfo, public DelayInit {
        
        static_assert(I::IsInterface, "Must be interface declared!");
    
        InterfaceFixer(std::string_view szName, std::source_location sl=std::source_location::current()) :
            InterfaceInfo(szName, sl)
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

        static DelayInit::Ctor  s_reg;
    };
}
