////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tbb/spin_rw_mutex.h>
#include <yq/vkqt/app/YAppThread.hpp>

class SCEApp : public yq::tachyon::YAppThread {
    YQ_TACHYON_DECLARE(SCEApp, YAppThread)
    Q_OBJECT
public:
    SCEApp(int&,char* argv[], yq::tachyon::Application&);
    ~SCEApp();

    static SCEApp*  app() { return s_app; }
    
    auto& imports() const { return m_imports; }
    auto& plugins() const { return m_plugins; }
    auto& vlibs() const { return m_vlibs; }
    auto& respath() const { return m_respath; }

private:
    static SCEApp*    s_app;

    using mutex_t = tbb::spin_rw_mutex;
    using lock_t = mutex_t::scoped_lock;

    std::vector<std::filesystem::path>  m_imports, m_plugins, m_vlibs, m_respath;

    mutable mutex_t                 m_mutex;
};
