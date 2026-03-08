////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorProperty.hpp"

#include <yq/resource/Resource.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/meta/ResourceProperty.hpp>
#include <yq/tachyon/api/meta/ResourceVectorAppend.hpp>
#include <yq/tachyon/api/meta/ResourceVectorClear.hpp>
#include <yq/tachyon/api/meta/ResourceVectorCount.hpp>
#include <yq/tachyon/api/meta/ResourceVectorEAdd.hpp>
#include <yq/tachyon/api/meta/ResourceVectorEGet.hpp>
#include <yq/tachyon/api/meta/ResourceVectorEmpty.hpp>
#include <yq/tachyon/api/meta/ResourceVectorErase.hpp>
#include <yq/tachyon/api/meta/ResourceVectorESet.hpp>
#include <yq/tachyon/api/meta/ResourceVectorGetter.hpp>
#include <yq/tachyon/api/meta/ResourceVectorInsert.hpp>
#include <yq/tachyon/api/meta/ResourceVectorSetter.hpp>

namespace yq::tachyon {
    ResourceVectorProperty::ResourceVectorProperty(std::string_view zName, const std::source_location& sl, const ResourceMeta& theResource, ObjectMeta* parent) :
        Meta(zName, parent, sl), m_resource(theResource)
    {
        assert(parent);
        
        if(TachyonMeta* ti = dynamic_cast<TachyonMeta*>(parent)){
            if(ti->m_resources.local.keys.has(zName))
                tachyonCritical << "ResourceVectorProperty::ResourceVectorProperty(" << parent->name() << "." << zName << ") -- duplicate detected!";
            if(ti->m_resourceVectors.local.keys.has(zName))
                tachyonCritical << "ResourceVectorProperty::ResourceVectorProperty(" << parent->name() << "." << zName << ") -- duplicate detected!";
            ti->m_resourceVectors.local << this;
        }
    }

    std::error_code     ResourceVectorProperty::add(Object* obj, const ResourceCPtr& res) const
    {
        if(m_eadd)
            return m_eadd -> add(obj, res);
        if(m_setter && m_getter){
            ResourceCPtrVector  resv    = m_getter->get(obj);
            resv.push_back(res);
            return m_setter->set(obj, resv);
        }
        return errors::no_handler();
    }

    std::error_code     ResourceVectorProperty::append(Object* obj, ResourceCPtrCSpan res) const
    {
        if(res.empty())
            return {};
        if(m_append)
            return m_append->append(obj, res);
        if(m_eadd){
            for(auto& rp : res)
                m_eadd->add(obj, rp);
            return {};
        }
        if(m_setter && m_getter){
            ResourceCPtrVector  resv    = m_getter->get(obj);
            for(auto& rp : res)
                resv.push_back(rp);
            return m_setter->set(obj, resv);
        }
        return errors::no_handler();
    }

    std::error_code     ResourceVectorProperty::clear(Object* obj) const
    {
        if(m_clear)
            return m_clear -> clear(obj);
        if(m_setter)
            return m_setter -> set(obj, {});
        return errors::no_handler();
    }

    size_x              ResourceVectorProperty::count(const Object* obj) const
    {
        if(m_count)
            return m_count -> count(obj);
        if(m_getter){
            ResourceCPtrVector  resv    = m_getter->get(obj);
            return resv.size();
        }
        return errors::no_handler();
    }

    boolean_x           ResourceVectorProperty::empty(const Object* obj) const
    {
        if(m_empty)
            return m_empty -> empty(obj);
        if(m_count){
            auto x = m_count->count(obj);
            if(!x)
                return unexpected(x.error());
            return *x == 0;
        }
        if(m_getter){
            ResourceCPtrVector  resv    = m_getter->get(obj);
            return resv.empty();
        }
        return errors::no_handler();
    }

    std::error_code     ResourceVectorProperty::erase(Object* obj, size_t n) const
    {
        if(m_erase) 
            return m_erase->erase(obj, n);
        if(m_getter && m_setter){
            ResourceCPtrVector  resv    = m_getter->get(obj);
            if(n >= resv.size())    
                return errors::bad_index();
            resv.erase(resv.begin() + n);
            return m_setter->set(obj, resv);
        }
        return errors::no_handler();
    }

    ResourceCPtrVector  ResourceVectorProperty::get(const Object* obj) const
    {
        if(!m_getter)
            return {};
        return m_getter->get(obj);
    }

    ResourceCPtr        ResourceVectorProperty::get(const Object* obj, size_t n) const
    {
        if(m_eget)
            return m_eget->get(obj, n);
        if(m_getter){
            ResourceCPtrVector  resv    = m_getter->get(obj);
            if(n >= resv.size())
                return {};
            return resv[n];
        }
        return {};
    }

    std::error_code     ResourceVectorProperty::insert(Object* obj, size_t n, const ResourceCPtr&res) const
    {
        if(m_insert)
            return m_insert -> insert(obj, n, res);
        if(m_getter && m_setter){
            ResourceCPtrVector  resv    = m_getter->get(obj);
            if(n >= resv.size())
                return errors::bad_index();
            resv.insert(resv.begin()+n, res);
            return {};
        }
        return errors::no_handler();
    }

    std::error_code     ResourceVectorProperty::set(Object* obj, ResourceCPtrCSpan res) const
    {
        if(!m_setter)   
            return errors::no_handler();
        return m_setter->set(obj, res);
    }

    std::error_code     ResourceVectorProperty::set(Object* obj, size_t n, const ResourceCPtr& res) const
    {
        if(m_eset)
            return m_eset->set(obj,n,res);
        if(m_getter && m_setter){
            ResourceCPtrVector  resv    = m_getter->get(obj);
            if(n>=resv.size())  
                return errors::bad_index();
            resv[n] = res;
            return m_setter->set(obj, resv);
        }
        return errors::no_handler();
    }
}
