////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Payload.hpp"
#include <tachyon/api/Post.hpp>
#include <yq/core/Any.hpp>

namespace yq::tachyon {
    Payload::Payload() = default;
    Payload::Payload(const Payload&) = default;
    Payload::Payload(Payload&&) = default;
    Payload::~Payload() = default;
    Payload& Payload::operator=(const Payload&) = default;
    Payload& Payload::operator=(Payload&&) = default;
    
    static const Any& badref()
    {
        static const Any    s_ret;
        return s_ret;
    }


    Payload& Payload::operator<<(const Any&v)
    {
        arguments.push_back(v);
        return *this;
    }
    
    Payload& Payload::operator<<(Any&&v)
    {
        arguments.push_back(std::move(v));
        return *this;
    }

    const Any&  Payload::argument(first_k, uint32_t k) const
    {
        if(k >= arguments.size())
            return badref();
        return arguments[k];
    }

    bool    Payload::argument(has_k, uint32_t k) const
    {
        return k < arguments.size();
    }

    const Meta* Payload::meta(first_k, uint32_t k) const
    {
        auto i = metas.find(k);
        if(i!=metas.end())
            return i->second;
        return nullptr;
    }

    bool        Payload::meta(has_k, uint32_t k) const
    {
        return metas.contains(k);
    }
    
    const Any&  Payload::parameter(first_k, uint32_t k) const
    {
        auto i = mapped.find(k);
        if(i != mapped.end())
            return i->second;
        return badref();
    }
    
    const Any&  Payload::parameter(first_k, const std::string& k) const
    {
        auto i = named.find(k);
        if(i != named.end())
            return i->second;
        return badref();
    }
    
    bool    Payload::parameter(has_k, uint32_t k) const
    {
        return mapped.contains(k);
    }
    
    bool    Payload::parameter(has_k, const std::string&k) const
    {
        return named.contains(k);
    }
}
