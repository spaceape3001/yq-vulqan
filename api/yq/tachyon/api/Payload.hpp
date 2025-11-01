////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/post.hpp>
#include <vector>
#include <map>
#include <cstdint>
#include <yq/typedef/string_maps.hpp>
#include <yq/text/IgCase.hpp>
#include <tachyon/keywords.hpp>
#include <yq/core/Any.hpp>
#include <yq/util/Iterable.hpp>

namespace yq {
    class Any;
};

namespace yq::tachyon {
    class Tachyon;
    class UIElement;

    /*! \brief Generic data passing for actions and other dynamic scenarios
    
        \note All recipients should use suitable defaults for anything missing 
            (unless that's absolutely impossible to do)
    */
    struct Payload {
    
        using meta_multimap_t       = std::multimap<uint32_t,const Meta*>;
        using parameter_multimap_t  = std::multimap<uint32_t, Any>;
        using meta_multimap_const_iterator_t    = meta_multimap_t::const_iterator;
        using meta_multimap_iterable_t          = Iterable<meta_multimap_const_iterator_t>;
    
        std::vector<PostCPtr>               m_posts;          //!< Posts that triggered this action
        std::vector<Any>                    m_arguments;      //!< Functional position-based arguments 0...N
        parameter_multimap_t                m_mapped;         //!< Mapped parameters (more exact than strings)
        meta_multimap_t                     m_metas;          //!< Meta parameters
        string_any_multimap_t               m_named;          //!< Named paramaters
        Tachyon*                            m_source  = nullptr;  //!< Sender for post reasons (or callback)
        Tachyon*                            m_target  = nullptr;  //!< A target, if applicaable
        UIElement*                          m_uielem  = nullptr;  //!< UI element making the call (if any)
    
        Tachyon*        source() const { return m_source; }
        Tachyon*        target() const { return m_target; }
        UIElement*      element() const { return m_uielem; }
        
        const auto& posts() const { return m_posts; }
        const auto& arguments() const { return m_arguments; }
        const auto& mappeds() const { return m_mapped; }
        const auto& metas() const { return m_metas; }
        const auto& nameds() const { return m_named; }
        
        struct Header {
            Tachyon*        source  = nullptr;
            Tachyon*        target  = nullptr;
            UIElement*      uielem  = nullptr;
        };
    
            //  Sigh... wanted these to not exist so it's POD style of a structure, however, 
            //  it's slightly *TOO* complicated for that (and... as it'll likely be stacked...POD 
            //  isn't as required/useful).
    
        Payload();
        Payload(const Header&);
        Payload(const Payload&);
        Payload(Payload&&);
        ~Payload();
        Payload& operator=(const Payload&);
        Payload& operator=(Payload&&);
        
        const Any&  argument(first_k, uint32_t) const;
        const Any&  parameter(first_k, const std::string&) const;
        const Any&  parameter(first_k, uint32_t) const;
        const Meta* meta(first_k, uint32_t) const;
        bool        meta(has_k, uint32_t) const;

        bool        argument(has_k, uint32_t) const;
        bool        parameter(has_k, uint32_t) const;
        bool        parameter(has_k, const std::string&) const;
        
        Payload&    append(uint32_t, const Any&);
        Payload&    append(uint32_t, Any&&);
        Payload&    append(uint32_t, const Meta&);
        Payload&    append(uint32_t, const Meta*);
        Payload&    append(std::string_view, const Any&);
        Payload&    append(std::string_view, Any&&);
        Payload&    append(const Any&);
        Payload&    append(Any&&);
        Payload&    append(const PostCPtr&);
        
        Payload& operator<<(const Any&);
        Payload& operator<<(Any&&);

        template <typename T>
        Payload& operator<<(const T&v)
        {
            return operator<<(Any(v));
        }
        
        template <typename T>
        Payload& operator<<(T&&v)
        {
            return operator<<(Any(std::move(v)));
        }
     };
}
