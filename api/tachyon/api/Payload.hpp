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
        std::vector<PostCPtr>   posts;          //!< Posts that triggered this action
        std::vector<Any>        arguments;      //!< Functional position-based arguments 0...N
        std::map<uint32_t,Any>  mapped;         //!< Mapped parameters (more exact than strings)
        string_any_map_t        named;          //!< Named paramaters
        Tachyon*                source  = nullptr;  //!< Sender for post reasons (or callback)
        Tachyon*                target  = nullptr;  //!< A target, if applicaable
        UIElement*              uielem  = nullptr;  //!< UI element making the call (if any)
    
            //  Sigh... wanted these to not exist so it's POD style of a structure, however, 
            //  it's slightly *TOO* complicated for that (and... as it'll likely be stacked...POD 
            //  isn't as required/useful).
    
        Payload();
        Payload(const Payload&);
        Payload(Payload&&);
        ~Payload();
        Payload& operator=(const Payload&);
        Payload& operator=(Payload&&);
        
        const Any&  argument(uint32_t) const;
        const Any&  parameter(const std::string&) const;
        const Any&  parameter(uint32_t) const;

        bool        argument(has_k, uint32_t) const;
        bool        parameter(has_k, uint32_t) const;
        bool        parameter(has_k, const std::string&) const;
        
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
