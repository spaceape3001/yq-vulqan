////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/trait/indices.hpp>
#include <yq/trait/is_pointer.hpp>
#include <tbb/spin_rw_mutex.h>
#include <tuple>
#include <unordered_map>

namespace yq::tachyon {
    struct VizBase;
    class ViDevice;

    template <typename V, typename A, typename ... Args>
    class ViManager {
    public:
        
        static constexpr const size_t   ARG_COUNT   = sizeof...(Args);
        
        using v_ref_t           = Ref<V>;
        using map_t             = std::unordered_map<uint64_t, v_ref_t>;
        using mutex_t           = tbb::spin_rw_mutex;
        using data_k            = std::tuple<Args...>;
        
        static uint64_t     get_id(const A& resource_ptr)
        {
            if constexpr (is_pointer_v<A>){
                return resource_ptr -> id();
            }
            
            if constexpr (!is_pointer_v<A>){
                return resource_ptr.id();
            }
        }
        
        ViManager(VizBase& viz, Args...args) : m_viz(viz), m_data(args...)
        {
        }

        ~ViManager()
        {
            m_hash.clear();
        }
    
        void        clear()
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            m_hash.clear();
        }
        
        template <unsigned... Is, typename ... B>
        v_ref_t    _create(const A& resource, indices<Is...>, B... args)
        {
            return new V(m_viz, resource, std::get<Is, Args...>(m_data)..., args...);
        }
        
        template <typename ... B>
        v_ref_t     create(const A& resource, B... args)
        {
            uint64_t    idv = get_id(resource);
            
            {
                mutex_t::scoped_lock _lock(m_mutex, false);
                auto j = m_hash.find(idv);
                if(j != m_hash.end())
                    return j->second;
            }

            v_ref_t    ret, p;
            if constexpr (sizeof...(Args) != 0){
                p       = _create(resource, indices_gen<ARG_COUNT>(), args...);
            }
            
            if constexpr (sizeof...(Args) == 0){
                p       = new V(m_viz, resource, args...);
            }
            
            if(!p->valid())
                return {};
            
            {
                mutex_t::scoped_lock _lock(m_mutex, true);
                auto [j,f]  = m_hash.try_emplace(idv, p);
                if(f){
                    std::swap(p, ret);
                } else
                    ret = j->second;
            }

            return ret;
        }
        
        template <typename ... B>
        v_ref_t recreate(const A& resource, B... args)
        {
            uint64_t    idv = get_id(resource);
            v_ref_t    ret, p;
            if constexpr (sizeof...(Args) != 0){
                ret = p = _create(resource, indices_gen<ARG_COUNT>(), args...);
            }
            
            if constexpr (sizeof...(Args) == 0){
                ret = p = new V(m_viz, resource, args...);
            }

            if(!p->valid())
                return {};
            
            {
                mutex_t::scoped_lock _lock(m_mutex, true);
                auto    j   = m_hash.find(idv);
                if(j != m_hash.end()){
                    std::swap(p, j->second);
                } else
                    m_hash[idv] = p;
            }
            
            return ret;
        }
        
        
        bool            empty() const
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.empty();
        }
        
        void            erase(const A& resource)
        {
            erase(get_id(resource));
        }
        
        void            erase(uint64_t i)
        {
            v_ref_t    va;
            {
                mutex_t::scoped_lock _lock(m_mutex, true);
                auto j  = m_hash.find(i);
                if(j != m_hash.end()){
                    std::swap(va,j->second);
                    m_hash.erase(j);
                }
            }
        }
        
        v_ref_t    get(uint64_t i) const
        {
            {
                mutex_t::scoped_lock _lock(m_mutex, false);
                auto j = m_hash.find(i);
                if(j != m_hash.end())
                    return j->second;
            }

            return {};
        }
        
        bool            has(uint64_t i) const
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.contains(i);
        }
        
        size_t          size() const 
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.size();
        }
        
        void            update(Args...args, bool autoClear=false)
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            m_data      = { args... };
            if(autoClear){
                m_hash.clear();
            }
        }

    private:
        ViManager(const ViManager&) = delete;
        ViManager(ViManager&&) = delete;
        ViManager& operator=(const ViManager&) = delete;
        ViManager& operator=(ViManager&&) = delete;
        
        VizBase&            m_viz;
        map_t               m_hash;
        mutable mutex_t     m_mutex;
        data_k              m_data;
    };

    template <typename V, typename A, typename ... Args>
    class ViManager2 {
    public:
        
        static constexpr const size_t   ARG_COUNT   = sizeof...(Args);
        
        using v_ref_t           = Ref<V>;
        using map_t             = std::unordered_map<uint64_t, v_ref_t>;
        using mutex_t           = tbb::spin_rw_mutex;
        using data_k            = std::tuple<Args...>;
        
        static uint64_t     get_id(const A& resource_ptr)
        {
            if constexpr (is_pointer_v<A>){
                return resource_ptr -> id();
            }
            
            if constexpr (!is_pointer_v<A>){
                return resource_ptr.id();
            }
        }
        
        ViManager2(ViDevice& viz, Args...args) : m_viz(viz), m_data(args...)
        {
        }

        ~ViManager2()
        {
            m_hash.clear();
        }
    
        void        clear()
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            m_hash.clear();
        }
        
        template <unsigned... Is>
        v_ref_t    _create(const A& resource, indices<Is...>)
        {
            return new V(m_viz, resource, std::get<Is, Args...>(m_data)...);
        }
        
        v_ref_t     create(const A& resource)
        {
            uint64_t    idv = get_id(resource);
            
            {
                mutex_t::scoped_lock _lock(m_mutex, false);
                auto j = m_hash.find(idv);
                if(j != m_hash.end())
                    return j->second;
            }

            v_ref_t    ret, p;
            if constexpr (sizeof...(Args) != 0){
                p       = _create(resource, indices_gen<ARG_COUNT>());
            }
            
            if constexpr (sizeof...(Args) == 0){
                p       = new V(m_viz, resource);
            }
            
            if(!p->valid())
                return {};
            
            {
                mutex_t::scoped_lock _lock(m_mutex, true);
                auto [j,f]  = m_hash.try_emplace(idv, p);
                if(f){
                    std::swap(p, ret);
                } else
                    ret = j->second;
            }

            return ret;
        }
        
        bool            empty() const
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.empty();
        }
        
        void            erase(const A& resource)
        {
            erase(get_id(resource));
        }
        
        void            erase(uint64_t i)
        {
            v_ref_t    va;
            {
                mutex_t::scoped_lock _lock(m_mutex, true);
                auto j  = m_hash.find(i);
                if(j != m_hash.end()){
                    std::swap(va,j->second);
                    m_hash.erase(j);
                }
            }
        }
        
        v_ref_t    get(uint64_t i) const
        {
            {
                mutex_t::scoped_lock _lock(m_mutex, false);
                auto j = m_hash.find(i);
                if(j != m_hash.end())
                    return j->second;
            }

            return {};
        }
        
        bool            has(uint64_t i) const
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.contains(i);
        }
        
        size_t          size() const 
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.size();
        }
        
        void            update(Args...args, bool autoClear=false)
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            m_data      = { args... };
            if(autoClear){
                m_hash.clear();
            }
        }

    private:
        ViManager2(const ViManager2&) = delete;
        ViManager2(ViManager2&&) = delete;
        ViManager2& operator=(const ViManager2&) = delete;
        ViManager2& operator=(ViManager2&&) = delete;
        
        ViDevice&           m_viz;
        map_t               m_hash;
        mutable mutex_t     m_mutex;
        data_k              m_data;
    };
}
