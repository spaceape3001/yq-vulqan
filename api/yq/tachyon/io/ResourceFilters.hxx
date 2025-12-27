////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/Resource.hpp>
#include <yq/typedef/string_sets.hpp>
#include <set>
#include <vector>

namespace yq::tachyon {

    template <typename ... Rs> struct ResourceFilterMaker;

    template <SomeResource R>
    void        add_loading_resource_filter(string_set_t& exts)
    {
        for(auto& s : Resource::loadable_extensions_for(meta<R>()))
            exts.insert(s);
    }

    template <SomeResource R>
    void        add_saving_resource_filter(string_set_t& exts)
    {
        for(auto& s : Resource::saveable_extensions_for(meta<R>()))
            exts.insert(s);
    }

    template <typename R1>
    struct ResourceFilterMaker<R1> {
        
        static void loadable(string_set_t& exts)
        {
            add_loading_resource_filter<R1>(exts);
        }
    };

    template <typename R1, typename ... R>
    struct ResourceFilterMaker<R1, R...> {
        static void loadable(string_set_t& exts)
        {
            add_loading_resource_filter<R1>(exts);
            ResourceFilterMaker<R...>::loadable(exts);
        }
        static void saveable(string_set_t& exts)
        {
            add_saving_resource_filter<R1>(exts);
            ResourceFilterMaker<R...>::saveable(exts);
        }
    };

    inline std::string  make_filter_set(const string_set_t& exts)
    {
        std::string     ret;
        for(const auto& s : exts){
            if(!ret.empty())
                ret += ',';
            ret += '.';
            ret += s;
        }
        return ret;
    }

    template <SomeResource ... Rs>
    std::string         make_resource_loading_filters()
    {
        string_set_t    exts;
        ResourceFilterMaker<Rs...>::loadable(exts);
        return make_filter_set(exts);
    }
    

    template <SomeResource ... Rs>
    std::string         make_resource_saving_filters()
    {
        string_set_t    exts;
        ResourceFilterMaker<Rs...>::saveable(exts);
        return make_filter_set(exts);
    }
    

    template <SomeResource ... Rs>
    const std::string& resource_load_filters()
    {
        static const std::string s_ret = make_resource_loading_filters<Rs...>();
        return s_ret;
    }

    template <SomeResource ... Rs>
    const std::string& resource_save_filters()
    {
        static const std::string s_ret = make_resource_saving_filters<Rs...>();
        return s_ret;
    }
}
