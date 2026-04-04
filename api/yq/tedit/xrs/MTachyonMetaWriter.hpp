////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {

    /*! \brief Writer of widget information
    */
    template <typename C>
    class MTachyonMeta::Writer : public TachyonMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(MTachyonMeta* tacInfo) : TachyonMeta::Writer<C>(tacInfo), m_meta(tacInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(MTachyonMeta& tacInfo) : Writer(&tacInfo)
        {
        }
        
        template <SomeTachyon T>
        void manage()
        {
            if(m_meta && thread_safe_write() && !std::is_base_of_v<MTachyon,T>){
                m_meta -> add_managed(meta<T>());
            }
        }
        
    private:
        MTachyonMeta* m_meta;
    };
    
    template <typename C>
    class MTachyon::Fixer : public Tachyon::Fixer<C> {
    public:
    
        Fixer(std::string_view zName, typename C::MyBase::MyMeta& base, const std::source_location& sl=std::source_location::current()) : 
            Tachyon::Fixer<C>(zName, base, sl)
        {
        }
        
        virtual MTachyon*           create(TypedID tid) const override 
        { 
            if constexpr (std::is_constructible_v<C, TypedID>){
                return new C(tid); 
            } else if constexpr (std::is_constructible_v<C>){
                return new C;
            } else
                return nullptr;
        }
    };
    
}
