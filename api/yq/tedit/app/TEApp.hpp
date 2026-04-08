////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tbb/spin_rw_mutex.h>
#include <yq/vkqt/app/YApp.hpp>
#include <filesystem>

namespace yq::tachyon {
    class TEApp : public YApp {
    public:
    
        TEApp(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
        ~TEApp();
        
        static TEApp*   app() { return s_app; }

        virtual bool    start() override;    // starts the threads
        
        auto& imports() const { return m_imports; }
        auto& plugins() const { return m_plugins; }
        auto& vlibs() const { return m_vlibs; }
        auto& respath() const { return m_respath; }


    protected:
        using mutex_t   = tbb::spin_rw_mutex;
        using lock_t    = mutex_t::scoped_lock;

        std::vector<std::filesystem::path>  m_imports, m_plugins, m_vlibs, m_respath;

    private:
        static TEApp*   s_app;
    };
}
