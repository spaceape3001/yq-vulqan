////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Trigger.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {

    namespace impl {
        template <SomeTrigger T, SomePost P, typename R> 
        struct TriggerArgDeducer {
            using trigger_t     = T;
            using post_t        = P;
            using result_t      = R;
        };
        
        template <SomeTrigger T, SomePost P, typename R> 
        constexpr TriggerArgDeducer<T,P,R> deduce_trigger(R (T::*)(const P&) const) 
        {
            return {};
        }
        
        struct AbstractTriggerTraits {
            using post_t        = void;
            static constexpr bool  has_accept  = false;
        };
        
        template <SomeTrigger T>
        struct ConcreteTriggerTraits {
            using deduce_t          = decltype(deduce_trigger(&T::accept));
            using post_t            = typename deduce_t::post_t;
            static_assert( std::derived_from<post_t, Post>, "Post must be post-based class!");
            static constexpr bool has_accept  = true;
        };
    }

    
    template <typename C>
    class Trigger::Fixer : public ObjectFixer<C> {
    public:
        using traits_t      = std::conditional_t<std::is_same_v<Trigger,C>, impl::AbstractTriggerTraits, impl::ConcreteTriggerTraits<C>>;
        using post_t        = typename traits_t::post_t;
        using result_t      = typename traits_t::result_t;
        static constexpr bool      has_accept  = traits_t::has_accept;
        
        Fixer(std::string_view zName, typename C::MyBase::MyInfo& base, const std::source_location& sl=std::source_location::current()) : 
            ObjectFixer<C>(zName, base, sl)
        {
            if constexpr (has_accept){
                if constexpr (!std::is_same_v<post_t, Post>){
                    TriggerInfo::m_postInfo  = &meta<post_t>();
                }
            } else {
                Meta::set(Meta::Flag::ABSTRACT);
            }
        }
        
        TriggerResult      accept(const Trigger& trigger, const Post& thePost) const override
        {
            if constexpr (has_accept){
                const post_t*       pp;
                
                if constexpr (std::is_same_v<post_t, Post>){
                    pp      = &thePost;
                }
                if constexpr (!std::is_same_v<post_t, Post>){
                    pp      = dynamic_cast<const post_t*>(&thePost);
                    if(!pp)
                        return TriggerResult::Mismatch;
                }

                try 
                {
                    if constexpr (std::is_same_v<result_t, TriggerResult>){
                        return static_cast<const C&>(trigger).accept(*pp);
                    }
                    if constexpr (std::is_same_v<result_t, bool>){
                        if(static_cast<const C&>(trigger).accept(*pp)){
                            return TriggerResult::Accept;
                        } else {
                            return TriggerResult::Reject;
                        }
                    }
                    return TriggerResult::Undefined;
                }
                catch(...)
                {
                    return TriggerResult::Exception;
                }
            } 
            if constexpr (!has_accept){
                return TriggerResult::Undefined;
            }
        }
    };
    
    /*! \brief Writer of event information
    */
    template <typename C>
    class TriggerInfo::Writer : public ObjectInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(TriggerInfo* pInfo) : ObjectInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(TriggerInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        TriggerInfo* m_meta;
    };
}
