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

    Payload::Payload(const Header&h) : m_source(h.source), m_target(h.target), m_uielem(h.uielem)
    {
    }

    Payload& Payload::operator<<(const Any&v)
    {
        m_arguments.push_back(v);
        return *this;
    }
    
    Payload& Payload::operator<<(Any&&v)
    {
        m_arguments.push_back(std::move(v));
        return *this;
    }

    Payload& Payload::append(uint32_t n, const Any&v)
    {
        m_mapped.insert({n,v});
        return *this;
    }
    
    Payload& Payload::append(uint32_t n, Any&&v)
    {
        m_mapped.insert({n,std::move(v)});
        return *this;
    }
    
    Payload& Payload::append(uint32_t n, const Meta&v)
    {
        m_metas.insert({n,&v});
        return *this;
    }
    
    Payload& Payload::append(uint32_t n, const Meta* v)
    {
        if(v)
            m_metas.insert({n,v});
        return *this;
    }
    
    Payload& Payload::append(std::string_view k, const Any&v)
    {
        m_named.insert({std::string(k), v});
        return *this;
    }
    
    Payload& Payload::append(std::string_view k, Any&&v)
    {
        m_named.insert({std::string(k), std::move(v)});
        return *this;
    }
    
    Payload& Payload::append(const Any&v)
    {
        m_arguments.push_back(v);
        return *this;
    }
    
    Payload& Payload::append(Any&&v)
    {
        m_arguments.push_back(std::move(v));
        return *this;
    }
    
    Payload& Payload::append(const PostCPtr&v)
    {
        if(v)
            m_posts.push_back(v);
        return *this;
    }

    const Any&  Payload::argument(first_k, uint32_t k) const
    {
        if(k >= m_arguments.size())
            return badref();
        return m_arguments[k];
    }

    bool    Payload::argument(has_k, uint32_t k) const
    {
        return k < m_arguments.size();
    }

    const Meta* Payload::meta(first_k, uint32_t k) const
    {
        auto i = m_metas.find(k);
        if(i!=m_metas.end())
            return i->second;
        return nullptr;
    }

    bool        Payload::meta(has_k, uint32_t k) const
    {
        return m_metas.contains(k);
    }
    
    const Any&  Payload::parameter(first_k, uint32_t k) const
    {
        auto i = m_mapped.find(k);
        if(i != m_mapped.end())
            return i->second;
        return badref();
    }
    
    const Any&  Payload::parameter(first_k, const std::string& k) const
    {
        auto i = m_named.find(k);
        if(i != m_named.end())
            return i->second;
        return badref();
    }
    
    bool    Payload::parameter(has_k, uint32_t k) const
    {
        return m_mapped.contains(k);
    }
    
    bool    Payload::parameter(has_k, const std::string&k) const
    {
        return m_named.contains(k);
    }
}
